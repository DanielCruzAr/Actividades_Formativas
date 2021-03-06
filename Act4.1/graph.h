#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

class Graph {
	private:
		vector<vector<int>> adj_matrix;
		vector<vector<int>> adj_list;
		int vertex;
		int edges;

	public:
		Graph(){}
		void loadGraphMat(string,int,int);
		void loadGraphList(string,int,int);
		string print_vector(vector<int>);
		string printAdjMat();
		string printAdjList();
		string DFS(int,int);
		string BFS(int,int);
};


void Graph::loadGraphMat(string file, int vert, int ed){
	edges = ed;
	vertex = vert;
	
	for (int i=0; i<vert; i++){
		vector<int> row(vert, 0);
		adj_matrix.push_back(row);
	}
	
	ifstream read;
	read.open(file);
	while(read.good()){
		string start; 
		string end;
		getline(read, start, ',');
		getline(read, end, '\n');
		start = start.substr(1, start.length()-1);
		end = end.substr(1, end.length()-2);
		int fnode = stoi(start);
		int lnode = stoi(end);
		
		adj_matrix[fnode][lnode] = 1;
		adj_matrix[lnode][fnode] = 1;
	}
}


void Graph::loadGraphList(string file, int vertices, int edges){
	vertex = vertices;
	edges = edges;
	
	for (int i=0; i<vertices; i++){
		vector<int> row;
		adj_list.push_back(row);
	}
	
	ifstream read;
	read.open(file);
	while(read.good()){
		string start;
		string end;
		getline(read, start, ',');
		getline(read, end, '\n');
		start = start.substr(1, start.length()-1);
		end = end.substr(1, end.length()-2);
		int fnode = stoi(start);
		int lnode = stoi(end);
		
		adj_list[fnode].push_back(lnode);
		adj_list[lnode].push_back(fnode);
	}
}

/* PRINT */

string Graph::print_vector(vector<int> vec){
	string result = "";
	for (int i=0; i<vec.size(); i++){
		result = result + to_string(vec[i]) + " ";
	}
	return result;
}

string Graph::printAdjMat(){
	string result = "";
	for(int i=0; i<adj_matrix.size(); i++){
		for(int j=0; j<adj_matrix[i].size(); j++){
			result = result + to_string(adj_matrix[i][j]) + " ";
		}
	}
	return result;
}

string Graph::printAdjList(){
	string result = "";
	for(int i=0; i<adj_list.size(); i++){
		result += "vertex " + to_string(i) + " : ";
		sort(adj_list[i].begin(), adj_list[i].end());
		for(int j=0; j<adj_list[i].size(); j++){
			result += to_string(adj_list[i][j]) + " ";
		}
	}
	return result;
}

/* BUSQUEDA */

string Graph::DFS(int start, int target_vertex){
	
	vector<vector<int>> adj_list_copy;
	for (int i=0; i<adj_list.size(); i++){
		adj_list_copy.push_back(adj_list[i]);
	}
	
	vector<int> stack;
	vector<int> visited;
	bool found = false;
	int current = start;

	while (!found && !(visited.size() >= vertex)){
		bool already_visited = false;
		for (int i=0; i<visited.size(); i++){
			if(current == visited[i]) {
				already_visited = true;
				break;
			}
		}

		if (!already_visited) visited.push_back(current);

		if (current == target_vertex){
			found = true;
			break;
		}

		for (int i=0; i<adj_list_copy[current].size(); i++){
			for (int j=0; j<visited.size(); j++){
				if(adj_list_copy[current][i] == visited[j])
					adj_list_copy[current].erase(adj_list_copy[current].begin()+i);
			}
		}
		if (adj_list_copy[current].size() > 0){
			stack.push_back(current);
			int temp_index = current;
			current = adj_list_copy[current].back();
			adj_list_copy[temp_index].pop_back();
		} 
		else {
			current = stack[stack.size()-1];
			stack.pop_back();
		}
	}
	stack.push_back(current);
	
	string visited_str = print_vector(visited);
	string path_str = print_vector(stack);
	string result = "visited: " + visited_str + "path: " + path_str;
	result = result.substr(0, result.size()-1);
	return result;
}


string Graph::BFS(int start, int target_vertex){
	vector<vector<int>> queue;
	vector<vector<int>> visited;
	int current = start;
	int parent = -1;
	bool found = false;

	while (true){
		visited.push_back(vector<int>({parent, current}));

		if (current == target_vertex){
			found = true;
			break;
		}

		for (int i=0; i<adj_list[current].size(); i++){
			int val = adj_list[current][i];
			bool already_visited = false;
			for (int j=0; j<visited.size(); j++){
				if (visited[j][1] == val){
					already_visited = true;
					break;
				}
			}
			if (!already_visited) queue.push_back(vector<int>({current, val}));
		}
		parent = queue[0][0];
		current = queue[0][1];
		queue.erase(queue.begin());
	}
	vector<int> path;
	int find = target_vertex;
	do {
		for (int i=0; i<visited.size(); i++){
			if (visited[i][1] == find){
				path.insert(path.begin(), find);
				find = visited[i][0];
			}
		}
	} while (find != -1);
	vector<int> converted_visited;
	for (int i=0; i<visited.size(); i++){
		converted_visited.push_back(visited[i][1]);
	}

	string visited_str = print_vector(converted_visited);
	string path_str = print_vector(path);
	string result = "visited: " + visited_str + "path: " + path_str;
	result = result.substr(0, result.size()-1);
	return result;	
}

#endif