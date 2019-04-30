#include "pch.h"
#include "Graph.h"

// default constructor(20 vertices)
Graph::Graph() {
	adjList = new List<List<int>>;
}

// overloaded constructor(specified # of vertices)
Graph::Graph(int in_vertices) {
	adjList = new List<List<int>>(in_vertices);
}

// add edge directed from i to j
void Graph::addEdge(int i, int j) {
	bool flag = 0;
	bool flag2 = 0;
	bool flag3 = 0;

	// look at each vertex
	for (int k = 0; k < adjList->getLength(); k++) {

		// if vertex has value i
		if (*(adjList->findItem(k)->getStart()) == i) {

			flag = 1;

			// look at each out edge
			for (int m = 1; m < adjList->findItem(k)->getLength(); m++) {

				// if out edge has value j
				if (*(adjList->findItem(k)->findItem(m)) == j)

					flag3 = 1;

			}

			// if no out edge had value j
			if (flag3 == 0) {

				// add out edge with value j
				adjList->findItem(k)->addItem(new int(j));
			}
		}
	}

	// if no vertex was found with value i
	if (flag == 0) {

		// add new vertex with value i 
		adjList->addItem(new List<int>);
		adjList->getLast()->addItem(new int(i));

		// add out edge with value j to new vertex
		adjList->getLast()->addItem(new int(j));
	}

	// look at each vertex
	for (int g = 0; g < adjList->getLength(); g++) {

		// if vertex has value j
		if (*(adjList->findItem(g)->getStart()) == j) {
			flag2 = 1;
		}
	}

	// if no vertex was found with value j
	if (flag2 == 0) {

		// add new vertex with value j
		adjList->addItem(new List<int>);
		adjList->getLast()->addItem(new int(j));
	}
}

// remove edge directed from i to j
void Graph::removeEdge(int i, int j) {
	bool flag = 0;
	int index = 0;

	// look at each vertex
	for (int k = 0; k < adjList->getLength(); k++) {

		// if vertex has value i
		if (*(adjList->findItem(k)->getStart()) == i) {

			// look at each out edge
			for (int m = 1; m < adjList->findItem(k)->getLength(); m++) {

				// if out edge has value j
				if (*(adjList->findItem(k)->findItem(m)) == j) {
					flag = 1;
					index = m;
				}
			}

			// if out edge was found with value j
			if (flag == 1) {

				// remove out edge with value j
				adjList->findItem(k)->removeItem(index);
				return;
			}
		}
	}
}

// check if out edge directed from i to j exists
bool Graph::hasEdge(int i, int j) {
	bool flag = 0;

	// look at each vertex
	for (int k = 0; k < adjList->getLength(); k++) {

		// if vertex has value i
		if (*(adjList->findItem(k)->getStart()) == i) {

			// look at each out edge
			for (int m = 1; m < adjList->findItem(k)->getLength(); m++) {

				// if out edge has value j
				if (*(adjList->findItem(k)->findItem(m)) == j) {
					flag = 1;
				}
			}

			// if out edge was found with value j
			if (flag == 1) {
				return true;
			}
		}
	}
	return false;
}

// return list of edges leading to vertex i
List<int> Graph::inEdges(int i) {
	retList.makeEmpty();

	// look at each vertex
	for (int k = 0; k < adjList->getLength(); k++) {

		// look at each out edge
		for (int m = 1; m < adjList->findItem(k)->getLength(); m++) {

			// if out edge has value i
			if (*(adjList->findItem(k)->findItem(m)) == i) {

				// add vertex to list being returned
				retList.addItem(new int(*(adjList->findItem(k)->getStart())));
			}
		}
	}
	return retList;
}

// return list of edges coming from vertex i
List<int> Graph::outEdges(int i) {
	retList.makeEmpty();
	bool flag = 0;

	// look at each vertex
	for (int k = 0; k < adjList->getLength(); k++) {

		// if vertex has value i
		if (*(adjList->findItem(k)->getStart()) == i) {

			// look at each out edge
			for (int m = 1; m < adjList->findItem(k)->getLength(); m++) {

				// add out edge to list being returned
				retList.addItem(new int(*(adjList->findItem(k)->findItem(m))));
			}
			return retList;
		}
	}
}

// display visual depiction of graph
void Graph::displayGraph() {

	// look at each list
	for (int i = 0; i < adjList->getLength(); i++) {

		// look at each list element
		for (int j = 0; j < adjList->findItem(i)->getLength(); j++) {

			// display element of list
			cout << *(adjList->findItem(i)->findItem(j)) << " ";
		}

		// new line
		cout << endl;
	}
}


void Graph::dfsHelper(int vertex) {
	int index, flag, search;

	index = findIndex(vertex);

	//Add the starting vertex to the return list
	//Will also use retList for checking if node has been visited
	retList.addItem(new int(*(adjList->findItem(index)->getStart())));

	//Looping through all the edges of the vertex
	for (int i = 0; i < adjList->findItem(index)->getLength(); i++) {

		search = *(adjList->findItem(index)->findItem(i));
		flag = 0;

		for (int i = 0; i < retList.getLength(); i++) {

			//If the item has been checked already, flag so it isn't called again
			if (search == *(retList.findItem(i)))
				flag++;
		}

		//If the item hasn't been checked, then recursively call the search function
		if (flag == 0) dfsHelper(search);
	}
}


List<int> Graph::depthFirstSearch(int start) {
	retList.makeEmpty();

	dfsHelper(start);

	return retList;
}


List<int> Graph::breadthFirstSearch(int start) {
	checkList.makeEmpty();
	Queue<int> searchQueue;
	int index, search, flag, temp;
	bool stopLoop = 0;

	index = findIndex(start);

	//Add the starting vertex to the return list
	//Will also use checkList for checking if node has been visited
	checkList.addItem(new int(*(adjList->findItem(index)->getStart())));


	while (!stopLoop) {

		//Loop through the vertex's edges, queue them for searching and mark as visited
		for (int i = 0; i < adjList->findItem(index)->getLength(); i++) {
			search = *(adjList->findItem(index)->findItem(i));
			flag = 0;

			//Flags if the value has already been checked
			for (int j = 0; j < checkList.getLength(); j++) {
				if (search == *(checkList.findItem(j))) {
					flag++;
				}
			}

			//If the value has not been checked, it is added to queue and marked as checked by adding to checkList 
			if (flag == 0) {
				checkList.addItem(new int(*(adjList->findItem(index)->findItem(i))));
				searchQueue.enqueue(*(adjList->findItem(index)->findItem(i)));
			}
		}

		//If the queue is empty, then the search is done
		if (searchQueue.isEmpty()) stopLoop = true;

		//Else, dequeue an item and search it's edges
		else {
			start = searchQueue.dequeue();
			index = findIndex(start);
		}
	}

	return checkList;
}


int Graph::findIndex(int search) {
	int index = 0;

	//Loop to find the index of vertex
	for (int i = 0; i < adjList->getLength(); i++) {
		if (search == *(adjList->findItem(i)->getStart())) {
			index = i;
		}
	}
	return index;
}

// deconstructor
Graph::~Graph() {

	// look at each list
	for (int i = 0; i < adjList->getLength(); i++) {

		// look at each list element
		for (int j = 0; j < adjList->findItem(i)->getLength(); j++) {

			// delete element
			delete adjList->findItem(i)->findItem(j);
		}

		// delete list
		delete adjList->findItem(i);
	}

	delete adjList;
}
