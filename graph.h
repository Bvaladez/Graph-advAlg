#pragma once
#include <vector>
#include <iostream>
#include <fstream>

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
	void DFS(int v, int vertices, int components);

private:
	std::vector<std::vector<int>> mGraph;
	int prePost = 1;
	//int mGraph[VERTICES][VERTICES];
	std::vector<int> mVisited;
	std::vector<int> mPreVisit;
	std::vector<int> mPostVisit;
	std::vector<int> mCC;

};