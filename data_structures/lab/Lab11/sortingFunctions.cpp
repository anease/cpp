#include "pch.h"

template <class T>

void bubbleSort(T inArray[], int length) {
	int i, j;
	T temp;

	for (i = 0; i < length - 1; i++) {
		for (j = 0; j < length - i - 1; j++) {
			if (inArray[j] > inArray[j + 1]) {
				//Swap
				temp = inArray[j];
				inArray[j] = inArray[j + 1];
				inArray[j + 1] = temp;
			}
		}
	}
}

template <class T>

void insertionSort(T inArray[], int length) {
	int i, j;
	T compare;

	for (i = 1; i < length; i++) {
		compare = inArray[i];
		j = i - 1;

		while (j >= 0 && inArray[j] > compare) {
			inArray[j + 1] = inArray[j];
			j = j - 1;
		}

		inArray[j + 1] = compare;
	}
}

template <class T>

void merge(T inArray[], int start, int mid, int end) {
	
	int p = start, q = mid + 1;

	T* Arr = new T [end - start + 1];
	int k = 0;

	for (int i = start; i <= end; i++) {
		if (p > mid)  
			Arr[k++] = inArray[q++];
		else if (q > end)
			Arr[k++] = inArray[p++];
		else if (inArray[p] < inArray[q])
			Arr[k++] = inArray[p++];
		else
			Arr[k++] = inArray[q++];
	}

	for (int p = 0; p < k; p++) {
		inArray[start++] = Arr[p];
	}
}

template <class T>

void mergeSort(T inArray[], int start, int end) {
	
	if (start < end) {
		int mid = (start + end) / 2;
		 
		mergeSort(inArray, start, mid);
		mergeSort(inArray, mid + 1, end);

		merge(inArray, start, mid, end);
	}
}

template <class T>

void quickSort(T inArray[], int start, int end) {

	int i = start, j = end;
	T temp;
	T pivot = inArray[(start + end) / 2];

	//Partitioning Array
	while (i <= j) {
		while (inArray[i] < pivot)
			i++;

		while (inArray[j] > pivot)
			j--;

		if (i <= j) {
			temp = inArray[i];
			inArray[i] = inArray[j];
			inArray[j] = temp;
			i++;
			j--;
		}
	};

	//Recursion
	if (start < j)
		quickSort(inArray, start, j);

	if (i < end)
		quickSort(inArray, i, end);
}

template <class T>

void heapify(T inArray[], int n, int i) {
	T temp;
	int largest = i;
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 

	if (l < n && inArray[l] > inArray[largest])
		largest = l;

	if (r < n && inArray[r] > inArray[largest])
		largest = r;

	if (largest != i) {
		temp = inArray[largest];
		inArray[largest] = inArray[i];
		inArray[i] = temp;

		// Recursively heapify the sub-tree
		heapify(inArray, n, largest);
	}
}

template <class T>

void heapSort(T inArray[], int n) {
	T temp;
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(inArray, n, i);

	for (int i = n - 1; i >= 0; i--) {
		temp = inArray[0];
		inArray[0] = inArray[i];
		inArray[i] = temp;

		heapify(inArray, i, 0);
	}
}

template <class T>

void countSort( T inArray[], int length, int range) {
	
	int* count = new int[range]{0};
	int i;
	T* out = new T[length];

	for (i = 0; i < length; i++)
		++count[inArray[i]];

	for (i = 1; i < range; i++)
		count[i] += count[i - 1];

	for (i = length - 1; i >= 0; i--) {
		out[count[inArray[i]] - 1] = inArray[i];
		--count[inArray[i]];
	}

	for (i = 0; i < length; i++)
		inArray[i] = out[i];
}

template <class T>

T getMax(T inArray[], int length) {
	T max = inArray[0];
	for (int i = 1; i < length; i++)
		if (inArray[i] > max)
			max = inArray[i];
	return max;
}

template <class T>

void radixCountSort(T inArray[], int n, int exp) {
	T* output = new T[n];
	int i;
	int count[10] = { 0 };

	for (i = 0; i < n; i++)
		count[(inArray[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--) {
		output[count[(inArray[i] / exp) % 10] - 1] = inArray[i];
		count[(inArray[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		inArray[i] = output[i];
}

template <class T>

void radixsort(T inArray[], int length) {
	// Find maximum value to know number of digits (assuming template is int) 
	T max = getMax(inArray, length);

	for (int exp = 1; max / exp > 0; exp *= 10)
		radixCountSort(inArray, length, exp);
}


  /****************************/
 /* STUDENT SORTING VERSIONS */
/****************************/

template <class T>

void quickSortStudent(T inArray[], int start, int end, int parameter) {
	int i = start, j = end;
	T temp;
	T pivot = inArray[(start + end) / 2];

	switch (parameter) {

	//Parameter = Firstname
	case 1:
		
		while (i <= j) {
			while (inArray[i]->getFirstName() < pivot->getFirstName())
				i++;

			while (inArray[j]->getFirstName() > pivot->getFirstName())
				j--;

			if (i <= j) {
				temp = inArray[i];
				inArray[i] = inArray[j];
				inArray[j] = temp;
				i++;
				j--;
			}
		};

		if (start < j)
			quickSortStudent(inArray, start, j, 1);

		if (i < end)
			quickSortStudent(inArray, i, end, 1);	
		break;


	//Parameter = Lastname
	case 2:

		while (i <= j) {
			while (inArray[i]->getLastName() < pivot->getLastName())
				i++;

			while (inArray[j]->getLastName() > pivot->getLastName())
				j--;

			if (i <= j) {
				temp = inArray[i];
				inArray[i] = inArray[j];
				inArray[j] = temp;
				i++;
				j--;
			}
		};

		if (start < j)
			quickSortStudent(inArray, start, j, 2);

		if (i < end)
			quickSortStudent(inArray, i, end, 2);

		break;

	
	//Parameter = MNumber
	case 3:

		while (i <= j) {
			while (inArray[i]->getID() < pivot->getID())
				i++;

			while (inArray[j]->getID() > pivot->getID())
				j--;

			if (i <= j) {
				temp = inArray[i];
				inArray[i] = inArray[j];
				inArray[j] = temp;
				i++;
				j--;
			}
		};

		if (start < j)
			quickSortStudent(inArray, start, j, 3);

		if (i < end)
			quickSortStudent(inArray, i, end, 3);

		break;
	}
}

template <class T>

void insertionSortStudent(T inArray[], int length, int parameter) {
	int i, j;
	T compare;

	switch (parameter) {
	
	//Parameter = Firstname
	case 1:
		
		for (i = 1; i < length; i++) {
			compare = inArray[i];
			j = i - 1;

			while (j >= 0 && inArray[j]->getFirstName() > compare->getFirstName()) {
				inArray[j + 1] = inArray[j];
				j = j - 1;
			}

			inArray[j + 1] = compare;
		}
		break;
	

	//Parameter = Lastname
	case 2:
		
		for (i = 1; i < length; i++) {
			compare = inArray[i];
			j = i - 1;

			while (j >= 0 && inArray[j]->getLastName() > compare->getLastName()) {
				inArray[j + 1] = inArray[j];
				j = j - 1;
			}

			inArray[j + 1] = compare;
		}
		break;


	//Parameter = MNumber
	case 3:

		for (i = 1; i < length; i++) {
			compare = inArray[i];
			j = i - 1;

			while (j >= 0 && inArray[j]->getID() > compare->getID()) {
				inArray[j + 1] = inArray[j];
				j = j - 1;
			}

			inArray[j + 1] = compare;
		}
		break;
	}
}

template <class T>

void heapifyStudent(T inArray[], int n, int i, int parameter) {
	T temp;
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	switch (parameter) {

	//Parameter = Firstname
	case 1:
		
		if (l < n && inArray[l]->getFirstName() > inArray[largest]->getFirstName())
			largest = l;

		if (r < n && inArray[r]->getFirstName() > inArray[largest]->getFirstName())
			largest = r;

		if (largest != i) {
			temp = inArray[largest];
			inArray[largest] = inArray[i];
			inArray[i] = temp;

			// Recursively heapify the sub-tree
			heapifyStudent(inArray, n, largest, 1);
		}
		break;


	//Parameter = Lastname
	case 2:

		if (l < n && inArray[l]->getLastName() > inArray[largest]->getLastName())
			largest = l;

		if (r < n && inArray[r]->getLastName() > inArray[largest]->getLastName())
			largest = r;

		if (largest != i) {
			temp = inArray[largest];
			inArray[largest] = inArray[i];
			inArray[i] = temp;

			// Recursively heapify the sub-tree
			heapifyStudent(inArray, n, largest, 2);
		}
		break;

	
	//Parameter = MNumber
	case 3:

		if (l < n && inArray[l]->getID() > inArray[largest]->getID())
			largest = l;

		if (r < n && inArray[r]->getID() > inArray[largest]->getID())
			largest = r;

		if (largest != i) {
			temp = inArray[largest];
			inArray[largest] = inArray[i];
			inArray[i] = temp;

			// Recursively heapify the sub-tree
			heapifyStudent(inArray, n, largest, 3);
		}
		break;
	}
}

template <class T>

void heapSortStudent(T inArray[], int n, int parameter) {
	T temp;

	switch (parameter) {

	//Parameter = Firstname
	case 1:

		for (int i = n / 2 - 1; i >= 0; i--)
			heapifyStudent(inArray, n, i, 1);

		for (int i = n - 1; i >= 0; i--) {
			temp = inArray[0];
			inArray[0] = inArray[i];
			inArray[i] = temp;

			heapifyStudent(inArray, i, 0, 1);
		}
		break;


	//Parameter = Lastname
	case 2:
		
		for (int i = n / 2 - 1; i >= 0; i--)
			heapifyStudent(inArray, n, i, 2);

		for (int i = n - 1; i >= 0; i--) {
			temp = inArray[0];
			inArray[0] = inArray[i];
			inArray[i] = temp;

			heapifyStudent(inArray, i, 0, 2);
		}
		break;


	//Parameter = MNumber
	case 3:

		for (int i = n / 2 - 1; i >= 0; i--)
			heapifyStudent(inArray, n, i, 3);

		for (int i = n - 1; i >= 0; i--) {
			temp = inArray[0];
			inArray[0] = inArray[i];
			inArray[i] = temp;

			heapifyStudent(inArray, i, 0, 3);
		}
		break;
	}
}