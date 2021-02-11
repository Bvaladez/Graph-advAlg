#include "graph.h"
#include <iostream>
#include <iomanip>

Graph::Graph(int v){
	 int i, j;
   for(i = 0; i < v; i++) {
      for(j = 0; j < v; j++) {
				mGraph[i][j] = 0;
      }
   }
}

void Graph::explore(int v, int vertices){
	for (int i = 0; i < vertices; i++){
		mVisited[i] = 0;
		mPreVisit[i] = 0;
		mPostVisit[i] = 0;
	}
	DFS(v, vertices);
	for (int j = 0; j < vertices; j++){
		if (mVisited[j] == 0){
			DFS(j, vertices);	
		}
	}

}

void Graph::DFS(int v, int vertices){
	static int prePost = 1;
	mVisited[v] = 1;
	mPreVisit[v] = prePost++; 

	for (int j = 0; j < vertices; j++){
		if( mVisited[j] == false && mGraph[v][j] == 1 ){
			DFS(j, vertices);
		}
	}
	mPostVisit[v] = prePost++;

}

// adds edge from u to v and v to u
void Graph::addUndirectedEdge(int u, int v){
	mGraph[u - 1][v - 1] = 1;
	mGraph[v - 1][u - 1] = 1;
}

// adds edge from u to v
void Graph::addEdge(int u, int v){
	mGraph[u - 1][v - 1] = 1;
}

void Graph::displayMatrix(int v) {
	std::cout << std::setw(6);
	for (int k = 0; k < v; k++ ){
		std::cout << k + 1 << " ";
	}
	std::cout << std::endl;

  int i, j;
  for(i = 0; i < v; i++) {
    for(j = 0; j < v; j++) {
			if (j == 0){
				std::cout << std::setw(3) << i + 1 << ": ";
			}
      std::cout << mGraph[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void Graph::outputDFS(int vertices){
	for (int i = 0; i < vertices; i++){

		std::cout << "vert: " << i + 1 << " Pre: " << mPreVisit[i] << " Post: " << mPostVisit[i] << std::endl;
	}
}

int main(){
// This  wont work unlesss starting at 1
//	Graph graph(VERTICES);
//	graph.addUndirectedEdge(0, 1);
//	graph.addUndirectedEdge(0, 2);
//	graph.addUndirectedEdge(0, 3);
//	graph.addUndirectedEdge(0, 4);
//	graph.addUndirectedEdge(0, 5);
//	graph.addUndirectedEdge(0, 6);
//	graph.addUndirectedEdge(0, 8);
//	graph.addUndirectedEdge(0, 9);
//	graph.addUndirectedEdge(0, 10);
//	graph.addUndirectedEdge(0, 11);
//	graph.addUndirectedEdge(1, 2);
//	graph.addUndirectedEdge(2, 3);
//	graph.addUndirectedEdge(3, 4);
//	graph.addUndirectedEdge(4, 5);
//	graph.addUndirectedEdge(5, 6);
//	graph.addUndirectedEdge(5, 7);
//	graph.addUndirectedEdge(6, 7);
//	graph.addUndirectedEdge(6, 8);
//	graph.addUndirectedEdge(6, 12);
//	graph.addUndirectedEdge(8, 12);
//	graph.addUndirectedEdge(8, 9);
//	graph.addUndirectedEdge(8, 10);
//	graph.addUndirectedEdge(9, 10);
//	graph.addUndirectedEdge(10, 11);
	//graph.displayMatrix(VERTICES);
	//graph.DFS(12, VERTICES);
	int gOneVerts = 10;
	Graph graph1(gOneVerts);
	graph1.addEdge(1, 5);
	graph1.addEdge(1, 2);
	graph1.addEdge(3, 1);
	graph1.addEdge(4, 3);
	graph1.addEdge(6, 4);
	graph1.addEdge(6, 8);
	graph1.addEdge(8, 9);
	graph1.addEdge(9, 7);
	graph1.addEdge(7, 2);
	graph1.addEdge(10, 6);
	graph1.addEdge(3, 10);
	graph1.addEdge(7, 8);
	graph1.displayMatrix(gOneVerts);
	graph1.explore(0, gOneVerts);
	graph1.outputDFS(gOneVerts);



}