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

void Graph::explore(int v){
	mVisited[v] = 1;

	std::cout << v << " -> ";

	for (int j = 0; j < VERTICES; j++){
		if( mVisited[j] == false && mGraph[v][j] == 1 ){
			explore(j);
		}
	}

}

void Graph::DFS(int v){
	for (int i = 0; i < VERTICES; i++){
		mVisited[i] = 0;
	}
	explore(v);	

}

// adds edge from u to v and v to u
void Graph::addUndirectedEdge(int u, int v){
	mGraph[u][v] = 1;
	mGraph[v][u] = 1;
}

// adds edge from u to v
void Graph::addEdge(int u, int v){
	mGraph[u][v] = 1;
}

void Graph::displayMatrix(int v) {
   int i, j;
   for(i = 0; i < v; i++) {
      for(j = 0; j < v; j++) {
					if (j == 1){
						//std::cout << i << ": " << std::setw(3);
					}
         std::cout << mGraph[i][j] << " ";
      }
      std::cout << std::endl;
   }
}

int main(){
	Graph graph(VERTICES);

	graph.addUndirectedEdge(0, 1);
	graph.addUndirectedEdge(0, 2);
	graph.addUndirectedEdge(0, 3);
	graph.addUndirectedEdge(0, 4);
	graph.addUndirectedEdge(0, 5);
	graph.addUndirectedEdge(0, 6);
	graph.addUndirectedEdge(0, 8);
	graph.addUndirectedEdge(0, 9);
	graph.addUndirectedEdge(0, 10);
	graph.addUndirectedEdge(0, 11);
	graph.addUndirectedEdge(1, 2);
	graph.addUndirectedEdge(2, 3);
	graph.addUndirectedEdge(3, 4);
	graph.addUndirectedEdge(4, 5);
	graph.addUndirectedEdge(5, 6);
	graph.addUndirectedEdge(5, 7);
	graph.addUndirectedEdge(6, 7);
	graph.addUndirectedEdge(6, 8);
	graph.addUndirectedEdge(6, 12);
	graph.addUndirectedEdge(8, 12);
	graph.addUndirectedEdge(8, 9);
	graph.addUndirectedEdge(8, 10);
	graph.addUndirectedEdge(9, 10);
	graph.addUndirectedEdge(10, 11);
	graph.displayMatrix(VERTICES);
	graph.DFS(12);


}