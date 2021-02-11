#pragma once
#include <vector>
#include <iostream>

#define VERTICES 13

class Graph{

public:
	Graph(int v);

	void addEdge(int u, int v);
	void addUndirectedEdge(int u, int v);
	void displayMatrix(int v);
	void outputDFS(int vertices);

	void explore(int v, int vertices);

	// takes the the vertex number to start DFS on
	void DFS(int v, int vertices);

private:

	int mGraph[VERTICES][VERTICES];
	int mVisited[VERTICES];
	int mPreVisit[VERTICES];
	int mPostVisit[VERTICES];

};