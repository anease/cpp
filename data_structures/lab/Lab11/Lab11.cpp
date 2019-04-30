#include "pch.h"
#include "Student.h"
#include "List.h"
#include "sortingFunctions.cpp"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <time.h>
#include <string>

typedef std::chrono::high_resolution_clock Clock;

using namespace std;

int randMNum() {
	int temp = (rand() % 595) *  (rand() % 705) * (rand() % 205) + rand();
	int retVal = 10000000 + temp;
	return retVal;
}

List<Student> createStudentList() {
	Student* s1 = new Student(randMNum(), "Rexana", "Clarke");
	Student* s2 = new Student(randMNum(), "Coleman", "Elliot");
	Student* s3 = new Student(randMNum(), "Fancy", "Judd");
	Student* s4 = new Student(randMNum(), "Ruth", "Masters");
	Student* s5 = new Student(randMNum(), "Merv", "Jack");
	Student* s6 = new Student(randMNum(), "Lidia", "Lennon");
	Student* s7 = new Student(randMNum(), "Violet", "Wade");
	Student* s8 = new Student(randMNum(), "Haylie", "Ledford");
	Student* s9 = new Student(randMNum(), "Godnet", "Friel");
	Student* s10 = new Student(randMNum(), "Beatrix", "Norris");
	Student* s11 = new Student(randMNum(), "Kilie", "Sartor");
	Student* s12 = new Student(randMNum(), "Briana", "Clark");
	Student* s13 = new Student(randMNum(), "Bryce", "Valentini");
	Student* s14 = new Student(randMNum(), "Milburga", "Lacey");
	Student* s15 = new Student(randMNum(), "Matthew", "Merchant");
	Student* s16 = new Student(randMNum(), "Zane", "Spence");
	Student* s17 = new Student(randMNum(), "Indiana", "Arthur");
	Student* s18 = new Student(randMNum(), "Rowana", "Hodson");
	Student* s19 = new Student(randMNum(), "Curt", "Bone");
	Student* s20 = new Student(randMNum(), "Ravenna", "Mutton");
	Student* s21 = new Student(randMNum(), "Kaeden", "Rains");
	Student* s22 = new Student(randMNum(), "Earle", "Reynell");
	Student* s23 = new Student(randMNum(), "Maya", "Bryan");
	Student* s24 = new Student(randMNum(), "Judy", "Coleman");
	Student* s25 = new Student(randMNum(), "Roseanne", "Sloane");
	Student* s26 = new Student(randMNum(), "Barrman", "Goddard");
	Student* s27 = new Student(randMNum(), "Trev", "Triggs");
	Student* s28 = new Student(randMNum(), "Zac", "Mac");
	Student* s29 = new Student(randMNum(), "Jose", "Higgins");
	Student* s30 = new Student(randMNum(), "Phil", "Grant");
	Student* s31 = new Student(randMNum(), "Delora", "Stevens");
	Student* s32 = new Student(randMNum(), "Shelia", "Philips");
	Student* s33 = new Student(randMNum(), "Breann", "Firmin");
	Student* s34 = new Student(randMNum(), "Zandra", "Wright");
	Student* s35 = new Student(randMNum(), "Oswald", "Daniel");
	Student* s36 = new Student(randMNum(), "Sydney", "Wilson");
	Student* s37 = new Student(randMNum(), "Cherise", "Eoghian");
	Student* s38 = new Student(randMNum(), "Lucile", "Longstaff");
	Student* s39 = new Student(randMNum(), "Yancy", "Simpson");
	Student* s40 = new Student(randMNum(), "Millie", "Simpson");
	Student* s41 = new Student(randMNum(), "Stacie", "Russel");
	Student* s42 = new Student(randMNum(), "Nita", "Bateson");
	Student* s43 = new Student(randMNum(), "Malcolm", "Linville");
	Student* s44 = new Student(randMNum(), "Azure", "Barr");
	Student* s45 = new Student(randMNum(), "Easton", "Kimball");
	Student* s46 = new Student(randMNum(), "Dina", "Stacy");
	Student* s47 = new Student(randMNum(), "Al", "Barnett");
	Student* s48 = new Student(randMNum(), "Timur", "Harrison");
	Student* s49 = new Student(randMNum(), "Frieda", "Madden");
	Student* s50 = new Student(randMNum(), "Tiana", "Jackman");

	List<Student> testList;
	testList.addItem(s1);
	testList.addItem(s2);
	testList.addItem(s3);
	testList.addItem(s4);
	testList.addItem(s5);
	testList.addItem(s6);
	testList.addItem(s7);
	testList.addItem(s8);
	testList.addItem(s9);
	testList.addItem(s10);
	testList.addItem(s11);
	testList.addItem(s12);
	testList.addItem(s13);
	testList.addItem(s14);
	testList.addItem(s15);
	testList.addItem(s16);
	testList.addItem(s17);
	testList.addItem(s18);
	testList.addItem(s19);
	testList.addItem(s20);
	testList.addItem(s21);
	testList.addItem(s22);
	testList.addItem(s23);
	testList.addItem(s24);
	testList.addItem(s25);
	testList.addItem(s26);
	testList.addItem(s27);
	testList.addItem(s28);
	testList.addItem(s29);
	testList.addItem(s30);
	testList.addItem(s31);
	testList.addItem(s32);
	testList.addItem(s33);
	testList.addItem(s34);
	testList.addItem(s35);
	testList.addItem(s36);
	testList.addItem(s37);
	testList.addItem(s38);
	testList.addItem(s39);
	testList.addItem(s40);
	testList.addItem(s41);
	testList.addItem(s42);
	testList.addItem(s43);
	testList.addItem(s44);
	testList.addItem(s45);
	testList.addItem(s46);
	testList.addItem(s47);
	testList.addItem(s48);
	testList.addItem(s49);
	testList.addItem(s50);
	return testList;
}

int main() {
	srand(time(NULL));
	int insert;

	auto bubbleTotalTime = 0.0;
	auto insertionTotalTime = 0.0;
	auto mergeTotalTime = 0.0;
	auto quickTotalTime = 0.0;
	auto heapTotalTime = 0.0;
	auto countTotalTime = 0.0;
	auto radixTotalTime = 0.0;

	int bubbleTestArray_10[10];
	int insertionTestArray_10[10];
	int mergeTestArray_10[10];
	int quickTestArray_10[10];
	int heapTestArray_10[10];
	int countTestArray_10[10];
	int radixTestArray_10[10];

	int bubbleTestArray_100[100];
	int insertionTestArray_100[100];
	int mergeTestArray_100[100];
	int quickTestArray_100[100];
	int heapTestArray_100[100];
	int countTestArray_100[100];
	int radixTestArray_100[100];

	int bubbleTestArray_500[500];
	int insertionTestArray_500[500];
	int mergeTestArray_500[500];
	int quickTestArray_500[500];
	int heapTestArray_500[500];
	int countTestArray_500[500];
	int radixTestArray_500[500];

	int bubbleTestArray_5000[5000];
	int insertionTestArray_5000[5000];
	int mergeTestArray_5000[5000];
	int quickTestArray_5000[5000];
	int heapTestArray_5000[5000];
	int countTestArray_5000[5000];
	int radixTestArray_5000[5000];

	int bubbleTestArray_25000[25000];
	int insertionTestArray_25000[25000];
	int mergeTestArray_25000[25000];
	int quickTestArray_25000[25000];
	int heapTestArray_25000[25000];
	int countTestArray_25000[25000];
	int radixTestArray_25000[25000];

	//Populating test arrays
	for (int i = 0; i < 10; i++) {
		insert = rand() % (2 * 10);
		bubbleTestArray_10[i] = insert;
		insertionTestArray_10[i] = insert;
		mergeTestArray_10[i] = insert;
		quickTestArray_10[i] = insert;
		heapTestArray_10[i] = insert;
		countTestArray_10[i] = insert;
		radixTestArray_10[i] = insert;
	}

	for (int i = 0; i < 100; i++) {
		insert = rand() % (2 * 100);
		bubbleTestArray_100[i] = insert;
		insertionTestArray_100[i] = insert;
		mergeTestArray_100[i] = insert;
		quickTestArray_100[i] = insert;
		heapTestArray_100[i] = insert;
		countTestArray_100[i] = insert;
		radixTestArray_100[i] = insert;
	}

	for (int i = 0; i < 500; i++) {
		insert = rand() % (2 * 500);
		bubbleTestArray_500[i] = insert;
		insertionTestArray_500[i] = insert;
		mergeTestArray_500[i] = insert;
		quickTestArray_500[i] = insert;
		heapTestArray_500[i] = insert;
		countTestArray_500[i] = insert;
		radixTestArray_500[i] = insert;
	}

	for (int i = 0; i < 5000; i++) {
		insert = rand() % (2 * 5000);
		bubbleTestArray_5000[i] = insert;
		insertionTestArray_5000[i] = insert;
		mergeTestArray_5000[i] = insert;
		quickTestArray_5000[i] = insert;
		heapTestArray_5000[i] = insert;
		countTestArray_5000[i] = insert;
		radixTestArray_5000[i] = insert;
	}

	for (int i = 0; i < 25000; i++) {
		insert = rand() % (2 * 25000);
		bubbleTestArray_25000[i] = insert;
		insertionTestArray_25000[i] = insert;
		mergeTestArray_25000[i] = insert;
		quickTestArray_25000[i] = insert;
		heapTestArray_25000[i] = insert;
		countTestArray_25000[i] = insert;
		radixTestArray_25000[i] = insert;
	}

	 /**************************/
	/* TESTING SORT FUNCTIONS */
   /**************************/

	cout << "Testing sort functions. . ." << endl;

	/* Size 10 Arrays*/
	for (int i = 0; i < 15; i++) {
		auto testStart = Clock::now();
		bubbleSort(bubbleTestArray_10, 10);
		auto testStop = Clock::now();
		auto bubble10Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		bubbleTotalTime += bubble10Time;

		testStart = Clock::now();
		insertionSort(insertionTestArray_10, 10);
		testStop = Clock::now();
		auto insertion10Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		insertionTotalTime += insertion10Time;

		testStart = Clock::now();
		mergeSort(mergeTestArray_10, 0, 9);
		testStop = Clock::now();
		auto merge10Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		mergeTotalTime += merge10Time;

		testStart = Clock::now();
		quickSort(quickTestArray_10, 0, 9);
		testStop = Clock::now();
		auto quick10Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		quickTotalTime += quick10Time;

		testStart = Clock::now();
		heapSort(heapTestArray_10, 10);
		testStop = Clock::now();
		auto heap10Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		heapTotalTime += heap10Time;

		testStart = Clock::now();
		countSort(countTestArray_10, 10, 20);
		testStop = Clock::now();
		auto count10Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		countTotalTime += count10Time;

		testStart = Clock::now();
		radixsort(radixTestArray_10, 10);
		testStop = Clock::now();
		auto radix10Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		radixTotalTime += radix10Time;
	}

	auto bubble10Avg = bubbleTotalTime / 15;
	auto insertion10Avg = insertionTotalTime / 15;
	auto merge10Avg = mergeTotalTime / 15;
	auto quick10Avg = quickTotalTime / 15;
	auto heap10Avg = heapTotalTime / 15;
	auto count10Avg = countTotalTime / 15;
	auto radix10Avg = radixTotalTime / 15;

	//Reset total times
	bubbleTotalTime = 0.0;
	insertionTotalTime = 0.0;
	mergeTotalTime = 0.0;
	quickTotalTime = 0.0;
	heapTotalTime = 0.0;
	countTotalTime = 0.0;
	radixTotalTime = 0.0;
	

	/* Size 100 Arrays */
	for (int i = 0; i < 15; i++) {
		auto testStart = Clock::now();
		bubbleSort(bubbleTestArray_100, 100);
		auto testStop = Clock::now();
		auto bubble100Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		bubbleTotalTime += bubble100Time;

		testStart = Clock::now();
		insertionSort(insertionTestArray_100, 100);
		testStop = Clock::now();
		auto insertion100Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		insertionTotalTime += insertion100Time;

		testStart = Clock::now();
		mergeSort(mergeTestArray_100, 0, 99);
		testStop = Clock::now();
		auto merge100Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		mergeTotalTime += merge100Time;

		testStart = Clock::now();
		quickSort(quickTestArray_100, 0, 99);
		testStop = Clock::now();
		auto quick100Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		quickTotalTime += quick100Time;

		testStart = Clock::now();
		heapSort(heapTestArray_100, 100);
		testStop = Clock::now();
		auto heap100Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		heapTotalTime += heap100Time;

		testStart = Clock::now();
		countSort(countTestArray_100, 100, 200);
		testStop = Clock::now();
		auto count100Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		countTotalTime += count100Time;

		testStart = Clock::now();
		radixsort(radixTestArray_100, 100);
		testStop = Clock::now();
		auto radix100Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		radixTotalTime += radix100Time;
	}

	auto bubble100Avg = bubbleTotalTime / 15;
	auto insertion100Avg = insertionTotalTime / 15;
	auto merge100Avg = mergeTotalTime / 15;
	auto quick100Avg = quickTotalTime / 15;
	auto heap100Avg = heapTotalTime / 15;
	auto count100Avg = countTotalTime / 15;
	auto radix100Avg = radixTotalTime / 15;

	//Reset total times
	bubbleTotalTime = 0.0;
	insertionTotalTime = 0.0;
	mergeTotalTime = 0.0;
	quickTotalTime = 0.0;
	heapTotalTime = 0.0;
	countTotalTime = 0.0;
	radixTotalTime = 0.0;


	/* Size 500 Arrays */
	for (int i = 0; i < 15; i++) {
		auto testStart = Clock::now();
		bubbleSort(bubbleTestArray_500, 500);
		auto testStop = Clock::now();
		auto bubble500Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		bubbleTotalTime += bubble500Time;

		testStart = Clock::now();
		insertionSort(insertionTestArray_500, 500);
		testStop = Clock::now();
		auto insertion500Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		insertionTotalTime += insertion500Time;

		testStart = Clock::now();
		mergeSort(mergeTestArray_500, 0, 499);
		testStop = Clock::now();
		auto merge500Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		mergeTotalTime += merge500Time;

		testStart = Clock::now();
		quickSort(quickTestArray_500, 0, 499);
		testStop = Clock::now();
		auto quick500Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		quickTotalTime += quick500Time;

		testStart = Clock::now();
		heapSort(heapTestArray_500, 500);
		testStop = Clock::now();
		auto heap500Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		heapTotalTime += heap500Time;

		testStart = Clock::now();
		countSort(countTestArray_500, 500, 1000);
		testStop = Clock::now();
		auto count500Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		countTotalTime += count500Time;

		testStart = Clock::now();
		radixsort(radixTestArray_500, 500);
		testStop = Clock::now();
		auto radix500Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		radixTotalTime += radix500Time;
	}

	auto bubble500Avg = bubbleTotalTime / 15;
	auto insertion500Avg = insertionTotalTime / 15;
	auto merge500Avg = mergeTotalTime / 15;
	auto quick500Avg = quickTotalTime / 15;
	auto heap500Avg = heapTotalTime / 15;
	auto count500Avg = countTotalTime / 15;
	auto radix500Avg = radixTotalTime / 15;

	//Reset total times
	bubbleTotalTime = 0.0;
	insertionTotalTime = 0.0;
	mergeTotalTime = 0.0;
	quickTotalTime = 0.0;
	heapTotalTime = 0.0;
	countTotalTime = 0.0;
	radixTotalTime = 0.0;


	/* Size 5000 Arrays */
	for (int i = 0; i < 15; i++) {
		auto testStart = Clock::now();
		bubbleSort(bubbleTestArray_5000, 5000);
		auto testStop = Clock::now();
		auto bubble5000Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		bubbleTotalTime += bubble5000Time;

		testStart = Clock::now();
		insertionSort(insertionTestArray_5000, 5000);
		testStop = Clock::now();
		auto insertion5000Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		insertionTotalTime += insertion5000Time;

		testStart = Clock::now();
		mergeSort(mergeTestArray_5000, 0, 4999);
		testStop = Clock::now();
		auto merge5000Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		mergeTotalTime += merge5000Time;

		testStart = Clock::now();
		quickSort(quickTestArray_5000, 0, 4999);
		testStop = Clock::now();
		auto quick5000Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		quickTotalTime += quick5000Time;

		testStart = Clock::now();
		heapSort(heapTestArray_5000, 5000);
		testStop = Clock::now();
		auto heap5000Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		heapTotalTime += heap5000Time;

		testStart = Clock::now();
		countSort(countTestArray_5000, 5000, 10000);
		testStop = Clock::now();
		auto count5000Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		countTotalTime += count5000Time;

		testStart = Clock::now();
		radixsort(radixTestArray_5000, 5000);
		testStop = Clock::now();
		auto radix5000Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		radixTotalTime += radix5000Time;
	}

	auto bubble5000Avg = bubbleTotalTime / 15;
	auto insertion5000Avg = insertionTotalTime / 15;
	auto merge5000Avg = mergeTotalTime / 15;
	auto quick5000Avg = quickTotalTime / 15;
	auto heap5000Avg = heapTotalTime / 15;
	auto count5000Avg = countTotalTime / 15;
	auto radix5000Avg = radixTotalTime / 15;

	//Reset total times
	bubbleTotalTime = 0.0;
	insertionTotalTime = 0.0;
	mergeTotalTime = 0.0;
	quickTotalTime = 0.0;
	heapTotalTime = 0.0;
	countTotalTime = 0.0;
	radixTotalTime = 0.0;


	/* Size 25000 Arrays */
	for (int i = 0; i < 15; i++) {
		auto testStart = Clock::now();
		bubbleSort(bubbleTestArray_25000, 25000);
		auto testStop = Clock::now();
		auto bubble25000Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		bubbleTotalTime += bubble25000Time;

		testStart = Clock::now();
		insertionSort(insertionTestArray_25000, 25000);
		testStop = Clock::now();
		auto insertion25000Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		insertionTotalTime += insertion25000Time;

		testStart = Clock::now();
		mergeSort(mergeTestArray_25000, 0, 24999);
		testStop = Clock::now();
		auto merge25000Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		mergeTotalTime += merge25000Time;

		testStart = Clock::now();
		quickSort(quickTestArray_25000, 0, 24999);
		testStop = Clock::now();
		auto quick25000Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		quickTotalTime += quick25000Time;

		testStart = Clock::now();
		heapSort(heapTestArray_25000, 25000);
		testStop = Clock::now();
		auto heap25000Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		heapTotalTime += heap25000Time;

		testStart = Clock::now();
		countSort(countTestArray_25000, 25000, 50000);
		testStop = Clock::now();
		auto count25000Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		countTotalTime += count25000Time;

		testStart = Clock::now();
		radixsort(radixTestArray_25000, 25000);
		testStop = Clock::now();
		auto radix25000Time = std::chrono::duration_cast<std::chrono::nanoseconds>(testStop - testStart).count();
		radixTotalTime += radix25000Time;
	}

	auto bubble25000Avg = bubbleTotalTime / 15;
	auto insertion25000Avg = insertionTotalTime / 15;
	auto merge25000Avg = mergeTotalTime / 15;
	auto quick25000Avg = quickTotalTime / 15;
	auto heap25000Avg = heapTotalTime / 15;
	auto count25000Avg = countTotalTime / 15;
	auto radix25000Avg = radixTotalTime / 15;

	const char separator = ' ';
	const int nameWidth = 10;
	const int numWidth = 15;

	std::system("cls");
	cout << left << setw(nameWidth) << setfill(separator) << "All times are in nanoseconds.";
	cout << endl << endl;

	cout << left << setw(nameWidth) << setfill(separator) << "";
	cout << left << setw(nameWidth) << setfill(separator) << "";
	cout << left << setw(numWidth) << setfill(separator) << 10;
	cout << left << setw(numWidth) << setfill(separator) << 100;
	cout << left << setw(numWidth) << setfill(separator) << 500;
	cout << left << setw(numWidth) << setfill(separator) << 5000;
	cout << left << setw(numWidth) << setfill(separator) << 25000;
	cout << endl << endl;

	cout << "Bubble Sort" << left << setw(9) << setfill(separator) << "";
	cout << left << setw(numWidth) << setfill(separator) << bubble10Avg;
	cout << left << setw(numWidth) << setfill(separator) << bubble100Avg;
	cout << left << setw(numWidth) << setfill(separator) << bubble500Avg;
	cout << left << setw(numWidth) << setfill(separator) << bubble5000Avg;
	cout << left << setw(numWidth) << setfill(separator) << bubble25000Avg;
	cout << endl;

	cout << "Insertion Sort" << left << setw(6) << setfill(separator) << "";
	cout << left << setw(numWidth) << setfill(separator) << insertion10Avg;
	cout << left << setw(numWidth) << setfill(separator) << insertion100Avg;
	cout << left << setw(numWidth) << setfill(separator) << insertion500Avg;
	cout << left << setw(numWidth) << setfill(separator) << insertion5000Avg;
	cout << left << setw(numWidth) << setfill(separator) << insertion25000Avg;
	cout << endl;

	cout << "Merge Sort" << left << setw(10) << setfill(separator) << "";
	cout << left << setw(numWidth) << setfill(separator) << merge10Avg;
	cout << left << setw(numWidth) << setfill(separator) << merge100Avg;
	cout << left << setw(numWidth) << setfill(separator) << merge500Avg;
	cout << left << setw(numWidth) << setfill(separator) << merge5000Avg;
	cout << left << setw(numWidth) << setfill(separator) << merge25000Avg;
	cout << endl;

	cout << "Quick Sort" << left << setw(10) << setfill(separator) << "";
	cout << left << setw(numWidth) << setfill(separator) << quick10Avg;
	cout << left << setw(numWidth) << setfill(separator) << quick100Avg;
	cout << left << setw(numWidth) << setfill(separator) << quick500Avg;
	cout << left << setw(numWidth) << setfill(separator) << quick5000Avg;
	cout << left << setw(numWidth) << setfill(separator) << quick25000Avg;
	cout << endl;
	
	cout << "Heap Sort" << left << setw(11) << setfill(separator) << "";
	cout << left << setw(numWidth) << setfill(separator) << heap10Avg;
	cout << left << setw(numWidth) << setfill(separator) << heap100Avg;
	cout << left << setw(numWidth) << setfill(separator) << heap500Avg;
	cout << left << setw(numWidth) << setfill(separator) << heap5000Avg;
	cout << left << setw(numWidth) << setfill(separator) << heap25000Avg;
	cout << endl;

	cout << "Counting Sort" << left << setw(7) << setfill(separator) << "";
	cout << left << setw(numWidth) << setfill(separator) << count10Avg;
	cout << left << setw(numWidth) << setfill(separator) << count100Avg;
	cout << left << setw(numWidth) << setfill(separator) << count500Avg;
	cout << left << setw(numWidth) << setfill(separator) << count5000Avg;
	cout << left << setw(numWidth) << setfill(separator) << count25000Avg;
	cout << endl;

	cout << "Radix Sort" << left << setw(10) << setfill(separator) << "";
	cout << left << setw(numWidth) << setfill(separator) << radix10Avg;
	cout << left << setw(numWidth) << setfill(separator) << radix100Avg;
	cout << left << setw(numWidth) << setfill(separator) << radix500Avg;
	cout << left << setw(numWidth) << setfill(separator) << radix5000Avg;
	cout << left << setw(numWidth) << setfill(separator) << radix25000Avg;
	cout << endl << endl;
	std::system("pause");
	std::system("CLS");

	 /************************/
	/* STUDENT INFO SORTING */
   /************************/

	List<Student> testList;
	Student* testArray[50];

	int directionChoice;
	int parameterChoice;
	int sortChoice;
	int loopChoice;
	int flag = 0;

	while (flag != 1) {
		cout << "Select Parameter to Sort on (1: Firstname, 2: Lastname, 3: MNumber):" << endl;
		cout << "Choice: ";
		cin >> parameterChoice;
		cout << endl;

		cout << "Select Sorting Algorithm (1: Insertion Sort, 2: Quick Sort, 3: Heap Sort):" << endl;
		cout << "Choice: ";
		cin >> sortChoice;
		cout << endl;

		cout << "Select Sorting Type (1: Ascending, 2: Descending):" << endl;
		cout << "Choice: ";
		cin >> directionChoice;
		cout << endl;

		testList = createStudentList();
	
		for (int i = 0; i < 50; i++) {
			testArray[i] = testList.pop();
		}

		switch (parameterChoice) {
	
		//Parameter = First Name
		case 1:
		
			switch (sortChoice) {
		
			//Sort = Insertion
			case 1:
				insertionSortStudent(testArray, 50, 1);
			
				switch (directionChoice) {
				//Direction = Ascending
				case 1:
					for (int i = 0; i < 50; i++) {
						cout << testArray[i]->getStudentInfo() << endl;
					}
					break;
				//Direction = Descending
				case 2:
					for (int i = 49; i >= 0; i--) {
						cout << testArray[i]->getStudentInfo() << endl;
					}
					break;
				}
				break;
		
		
			//Sort = Quick
			case 2:
				quickSortStudent(testArray, 0, 49, 1);

				switch (directionChoice) {
				//Direction = Ascending
				case 1:
					for (int i = 0; i < 50; i++) {
						cout << testArray[i]->getStudentInfo() << endl;
					}
					break;
				//Direction = Descending
				case 2:
					for (int i = 49; i >= 0; i--) {
						cout << testArray[i]->getStudentInfo() << endl;
					}
					break;
				}
				break;


			//Sort = Heap
			case 3:
				heapSortStudent(testArray, 50, 1);

				switch (directionChoice) {
				//Direction = Ascending
				case 1:
					for (int i = 0; i < 50; i++) {
						cout << testArray[i]->getStudentInfo() << endl;
					}
					break;
				//Direction = Descending
				case 2:
					for (int i = 49; i >= 0; i--) {
						cout << testArray[i]->getStudentInfo() << endl;
					}
					break;
				}
				break;
			}
			break;
	

		//Parameter = Last Name
		case 2:

			switch (sortChoice) {

			//Sort = Insertion
			case 1:
				insertionSortStudent(testArray, 50, 2);

				switch (directionChoice) {
				//Direction = Ascending
				case 1:
					for (int i = 0; i < 50; i++) {
						cout << testArray[i]->getStudentInfo() << endl;
					}
					break;
				//Direction = Descending
				case 2:
					for (int i = 49; i >= 0; i--) {
						cout << testArray[i]->getStudentInfo() << endl;
					}
					break;
				}
				break;


			//Sort = Quick
			case 2:
				quickSortStudent(testArray, 0, 49, 2);

				switch (directionChoice) {
				//Direction = Ascending
				case 1:
					for (int i = 0; i < 50; i++) {
						cout << testArray[i]->getStudentInfo() << endl;
					}
					break;
				//Direction = Descending
				case 2:
					for (int i = 49; i >= 0; i--) {
						cout << testArray[i]->getStudentInfo() << endl;
					}
					break;
				}
				break;


			//Sort = Heap
			case 3:
				heapSortStudent(testArray, 50, 2);

				switch (directionChoice) {
				//Direction = Ascending
				case 1:
					for (int i = 0; i < 50; i++) {
						cout << testArray[i]->getStudentInfo() << endl;
					}
					break;
				//Direction = Descending
				case 2:
					for (int i = 49; i >= 0; i--) {
						cout << testArray[i]->getStudentInfo() << endl;
					}
					break;
				}
				break;
			}
			break;

	
		//Parameter = MNumber
		case 3:

			switch (sortChoice) {

			//Sort = Insertion
			case 1:
				insertionSortStudent(testArray, 50, 3);

				switch (directionChoice) {
				//Direction = Ascending
				case 1:
					for (int i = 0; i < 50; i++) {
						cout << testArray[i]->getStudentInfo() << endl;
					}
					break;
				//Direction = Descending
				case 2:
					for (int i = 49; i >= 0; i--) {
						cout << testArray[i]->getStudentInfo() << endl;
					}
					break;
				}
				break;


			//Sort = Quick
			case 2:
				quickSortStudent(testArray, 0, 49, 3);

				switch (directionChoice) {
				//Direction = Ascending
				case 1:
					for (int i = 0; i < 50; i++) {
						cout << testArray[i]->getStudentInfo() << endl;
					}
					break;
				//Direction = Descending
				case 2:
					for (int i = 49; i >= 0; i--) {
						cout << testArray[i]->getStudentInfo() << endl;
					}
					break;
				}
				break;


			//Sort = Heap
			case 3:
				heapSortStudent(testArray, 50, 3);

				switch (directionChoice) {
				//Direction = Ascending
				case 1:
					for (int i = 0; i < 50; i++) {
						cout << testArray[i]->getStudentInfo() << endl;
					}
					break;
				//Direction = Descending
				case 2:
					for (int i = 49; i >= 0; i--) {
						cout << testArray[i]->getStudentInfo() << endl;
					}
					break;
				}
				break;
			}
			break;
		}

		cout << endl << "Would you like to try another sorting algortihm? (1: Yes, 2: No)" << endl;
		cout << "Choice: ";
		cin >> loopChoice;

		if (loopChoice == 1) system("cls");
		else flag++;
	}
	return 0;
}