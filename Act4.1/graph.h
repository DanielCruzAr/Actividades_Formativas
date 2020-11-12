#ifndef GRAPH_H_
#define GRAPH_H_

#inculde <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Graph {
	private:
		int edgesList;
		int edgesMat;
		int nodes;
		vector<int> *adjList;
		int *adjMatrix;
	public:
		Graph(int);
		void loadGraphMat(string, int, int);
		void loadGraphList(string, int, int);
		string DFS(int, int);
		string BFS(int, int);
};

Graph::Graph(int n) {
	nodes = n;
	adjList = new vector<int>[nodes];
	adjMatrix = new int [nodes*nodes];
	for(int i = 0; i < nodes*nodes; i++)
		adjMatrix[i] = 0;
	edgesList = 0;
}

void Graph::loadGraphMat(string file, int u, int v){
	adjMatrix[u*nodes+v] = 1;
	adjMatrix[v*nodes+u] = 1;
	edgesMat++;
}

void Graph::loadGraphList(string file, int u, int v){
	adjList[u].push_back(v);
	adjList[v].push_back(u);
	edgesList++;
}

string Graph::DFS(int u, int v){
	return 0;
}

string Graph::BFS(int u, int v){
	return 0;
}

#endif