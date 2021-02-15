#include "graph.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

Graph::Graph(int v){
	 int i, j;
   for(i = 0; i < v; i++) {
		 mGraph.push_back(std::vector<int>());
      for(j = 0; j < v; j++) {
				mGraph[i].push_back(0);
      }
   }
}

void Graph::explore(int v, int vertices){
	int components = 1;
	for (int i = 0; i < vertices; i++){
		mVisited.push_back(0);
		mPreVisit.push_back(0);
		mPostVisit.push_back(0);
		mCC.push_back(0);
	}
	DFS(v, vertices, components);
	for (int j = 0; j < vertices; j++){
		if (mVisited[j] == 0){
			components++;
			DFS(j, vertices, components);	
		}
	}

}

void Graph::DFS(int v, int vertices, int components){
	//static int prePost = 1;
	mVisited[v] = 1;
	mPreVisit[v] = prePost++; 
	mCC[v] = components;

	for (int j = 0; j < vertices; j++){
		if( mVisited[j] == false && mGraph[v][j] == 1 ){
			DFS(j, vertices, components);
		}
	}
	mPostVisit[v] = prePost++;

}

// adds edge from u to v and v to u counting FROM 1
void Graph::addUndirectedEdge(int u, int v){
	mGraph[u - 1][v - 1] = 1;
	mGraph[v - 1][u - 1] = 1;
}

// adds edge from u to v COUNTING FROM 1
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

		std::cout << i + 1 << " " << 
		mPreVisit[i] << " " << 
		mPostVisit[i] << " " << 
		mCC[i] << std::endl;
	}
}

int main(){
	//for (int i = 1; i < 5; i++){
		std::ifstream mFin;
		std::stringstream ss;
		int u, v, w;
		ss << "graph-1000-" << 4 << ".txt";
		mFin.open(ss.str());
		ss.clear();
		if(!mFin.is_open()){
			std::cout << "error opening file" << std::endl;
			exit(0);
		}
		int verts;
		mFin >> verts;
		Graph g(verts);

		while(mFin >> u >> v >> w){
			g.addEdge(u,v);
		}
		g.explore(0, verts);
		g.outputDFS(verts);
		mFin.close();
	//}



//	int gOneVerts = 10;
//	Graph graph1(gOneVerts);
//	graph1.addEdge(1, 5);
//	graph1.addEdge(1, 2);
//	graph1.addEdge(3, 1);
//	graph1.addEdge(4, 3);
//	graph1.addEdge(6, 4);
//	graph1.addEdge(6, 8);
//	graph1.addEdge(8, 9);
//	graph1.addEdge(9, 7);
//	graph1.addEdge(7, 2);
//	graph1.addEdge(10, 6);
//	graph1.addEdge(3, 10);
//	graph1.addEdge(7, 8);
//	graph1.displayMatrix(gOneVerts);
//	graph1.explore(0, gOneVerts);
//	graph1.outputDFS(gOneVerts);



}