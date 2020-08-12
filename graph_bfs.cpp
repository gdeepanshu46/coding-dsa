#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> g[], int v, int sv){
	bool visited[v];
	for(int i=0; i<v; i++)
		visited[i] = false;

	queue<int> q;
	q.push(sv);
	visited[sv] = true;

	while(!q.empty()){
		int temp = q.front();
		cout << temp << endl;
		q.pop();
		for(auto x : g[temp]){
			if(visited[x] == false){
				q.push(x);
				visited[x] = true;
			}
		}
	} 

}

void shortest_path(vector<int> g[], int v, int sv){
	bool visited[v];
	int dist[v];
	for(int i=0; i<v; i++){
		dist[i] = INT_MAX;
	}
	for(int i=0; i<v; i++)
		visited[i] = false;

	queue<int> q;
	q.push(sv);
	dist[sv] = 0;
	visited[sv] = true;

	while(!q.empty()){
		int temp = q.front();
		//cout << temp << endl;
		q.pop();
		for(auto x : g[temp]){
			if(visited[x] == false){
				dist[x] = dist[temp] + 1;
				visited[x] = true;
				q.push(x);
			}
		}
	}

	for(int i=0; i<v; i++)
		cout << i << " " << dist[i] << "\n";
	
}


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

void print_bfs(int **graph, int v, int sv){
	bool visited[v];
	for(int i=0; i<v; i++)
		visited[i] = false;

	queue<int> q;
	q.push(sv);
	visited[sv] = true;
	

	while(!q.empty()){
		int temp = q.front();
		q.pop();
		cout << temp << "\n";
		//visited[temp] = true;
		

		for(int i=0; i<v; i++){
			if(i == temp)
				continue;

			if(graph[temp][i] && !visited[i]){

				q.push(i);
				visited[i] = true;
			}
		}
	}
}


int main(){

	int v ; cin >> v;
	int e; cin >> e;
	//int graph[v][v] = {0};

	//using adjacency list
	vector<int> g[v];

	for(int i=0; i<e; i++){
		int f, s; cin >> f >> s;
		g[f].push_back(s);
		g[s].push_back(f);
	}
	//using adjacency matrix
	// int **graph = new int*[v];

	// for(int i=0; i<v; i++){
	// 	graph[i] = new int[v];
	// 	for(int j=0; j<v; j++){
	// 		graph[i][j] = 0;
	// 	}
	// }

	// bool visited[v];
	// for(int i=0; i<v; i++)
	// 	visited[i] = false;

	// for(int i=0; i<e; i++){
	// 	int f, s; cin >> f >> s;
	// 	graph[f][s] = 1;
	// 	graph[s][f] = 1;
	// }

	//cout << "DFS \n";
	 //print(graph, v, 0, visited);

	 cout << "BFS \n";
	//print_bfs(graph, v, 0);
	 //bfs(g, v, 0);

	 shortest_path(g, v, 0);

	return 0;
}