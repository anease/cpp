/* Homework 5: Graphs
* File: DSHW5.cpp
* Date: 25 April 2019
* By: Andrew Nease, James Wilfong
* neasaw, wilfonjv
* Section: 001
*
* ELECTRONIC SIGNATURE
* Andrew Nease, James V. Wilfong IV
*
* The electronic signatures above indicate the script
* submitted for evaluation is the combined effort of all
* team members and that each member of the team was an
* equal participant in its creation. In addition, each
* member of the team has a general understanding of all
* aspect of the script development and execution.
*
* A BRIEF DESCRIPTION OF WHAT THE SCRIPT OR FUNCTION DOES
* Design, implementation, and testing of a graph using
* the adjacency list method
*/
#include "pch.h"
#include "Graph.h"
#include "List.h"
#include <iostream>

using namespace std;

int main() {
	Graph myGraph;

	// input variables
	int response = 0;
	int v1, v2;

	// input prompt
	while (response != 8) {
		cout << "Enter 1 to add edge: " << endl;
		cout << "Enter 2 to remove an edge: " << endl;
		cout << "Enter 3 to check for an edge: " << endl;
		cout << "Enter 4 to see out edges" << endl;
		cout << "Enter 5 to see in edges" << endl;
		cout << "Enter 6 for depth first search" << endl;
		cout << "Enter 7 for breadth first search" << endl;
		cout << "Enter 8 to quit: " << endl << endl;
		cout << "Choice: ";
		cin >> response;
		cout << endl;

		switch (response) {

		// add edge
		case 1:
			cout << "Enter vertex 1: ";
			cin >> v1;
			cout << "Enter vertex 2: ";
			cin >> v2;
			cout << endl;
			myGraph.addEdge(v1, v2);
			myGraph.displayGraph();
			break;

		// remove edge
		case 2:
			cout << "Enter vertex 1: ";
			cin >> v1;
			cout << "Enter vertex 2: ";
			cin >> v2;
			cout << endl;
			myGraph.removeEdge(v1, v2);
			myGraph.displayGraph();
			break;
		
		// check if edge exists
		case 3:
			cout << "Enter vertex 1: ";
			cin >> v1;
			cout << "Enter vertex 2: ";
			cin >> v2;
			cout << endl;
			switch (myGraph.hasEdge(v1, v2)) {
			case 0:
				cout << "Edge does not exist." << endl;
				break;
			case 1:
				cout << "Edge exists." << endl;
				break;
			}
			break;
		
		// display out edges
		case 4:
			cout << "Enter vertex: ";
			cin >> v1;
			cout << endl;
			printList(myGraph.outEdges(v1));
			break;

		// display in edges
		case 5:
			cout << "Enter vertex: ";
			cin >> v1;
			cout << endl;
			printList(myGraph.inEdges(v1));
			break;

		// depth first search
		case 6:
			cout << "Enter starting vertex: ";
			cin >> v1;
			cout << endl;
			printList(myGraph.depthFirstSearch(v1));
			break;

		// breadth first search
		case 7:
			cout << "Enter starting vertex: ";
			cin >> v1;
			cout << endl;
			printList(myGraph.breadthFirstSearch(v1));
			break;

		// quit
		case 8:
			break;

		default:
			cout << "INVALID INPUT" << endl;
		}

		cout << endl;
	}
	return 0;
}
