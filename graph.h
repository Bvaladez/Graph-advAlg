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

	void explore(int v);

	// takes the the vertex number to start DFS on
	void DFS(int v);

private:

	int mGraph[VERTICES][VERTICES];
	int mVisited[VERTICES];

};