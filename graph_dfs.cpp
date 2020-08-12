#include <bits/stdc++.h>
using namespace std;

void print(int** graph, int v, int sv, bool* visited){
	cout << sv << "\n";
	visited[sv] = true;

	for(int i=0; i<v; i++){
		if(i == sv)
			continue;
		if(graph[sv][i]){
			if(visited[i])
				continue;

			print(graph, v, i, visited);
		}
	}
}


int main(){

	int v, e; cin >> v >> e;
	//int graph[v][v] = {0};

	int **graph = new int*[v];

	for(int i=0; i<v; i++){
		graph[i] = new int[v];
		for(int j=0; j<v; j++){
			graph[i][j] = 0;
		}
	}

	bool visited[v];

	for(int i=0; i<e; i++){
		int f, s; cin >> f >> s;
		graph[f][s] = 1;
		graph[s][f] = 1;
	}

	print(graph, v, 0, visited);
	return 0;
}