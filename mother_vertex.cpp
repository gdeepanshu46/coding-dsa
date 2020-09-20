#include <bits/stdc++.h>
using namespace std;

// A recursive function to print DFS starting from v 
void DFSUtil(vector<int> graph[], int v, vector<bool> &visited) 
{ 
    // Mark the current node as visited and print it 
    visited[v] = true; 
  
    // Recur for all the vertices adjacent to this vertex  
    for (auto i = graph[v].begin(); i != graph[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(graph, *i, visited); 
} 
  
// Returns a mother vertex if exists. Otherwise returns -1 
int findMother(vector<int> graph[], int V) 
{ 
    // visited[] is used for DFS. Initially all are 
    // initialized as not visited 
    vector <bool> visited(V, false); 
  
    // To store last finished vertex (or mother vertex) 
    int v = 0; 
  
    // Do a DFS traversal and find the last finished 
    // vertex   
    for (int i = 0; i < V; i++) 
    { 
        if (visited[i] == false) 
        { 
            DFSUtil(graph, i, visited); 
            v = i; 
        } 
    } 
  
    // If there exist mother vertex (or vetices) in given 
    // graph, then v must be one (or one of them) 
  
    // Now check if v is actually a mother vertex (or graph 
    // has a mother vertex).  We basically check if every vertex 
    // is reachable from v or not. 
  
    // Reset all values in visited[] as false and do  
    // DFS beginning from v to check if all vertices are 
    // reachable from it or not. 
    fill(visited.begin(), visited.end(), false); 
    DFSUtil(graph, v, visited);  
    for (int i=0; i<V; i++) 
        if (visited[i] == false) 
            return -1; 
  
    return v; 
} 

int main(){

	int v; cin>>v;
	vector<int> graph[v];

	int e; cin>>e;

	for(int i=0; i<e; i++){
		int a, b; cin>>a>>b;
		graph[a].push_back(b);
	}

	auto ans = findMother(graph, v);

	cout << ans << "\n";


	return 0;
}