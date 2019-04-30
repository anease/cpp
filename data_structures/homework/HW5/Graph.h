#pragma once
#include "List.h"
#include "Queue.h"

class Graph {

public:
	Graph();
	Graph(int);
	void addEdge(int, int);
	void removeEdge(int, int);
	bool hasEdge(int, int);
	List<int> outEdges(int);
	List<int> inEdges(int);
	List<int> depthFirstSearch(int);
	void dfsHelper(int);
	List<int> breadthFirstSearch(int);
	int findIndex(int);
	void displayGraph();
	~Graph();

private:
	List<List<int>>* adjList;
	List<int> checkList;
	List<int> retList;
};