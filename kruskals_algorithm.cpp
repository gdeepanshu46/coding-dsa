#include <bits/stdc++.h>
using namespace std;


struct edge
{
	int source, dest;
	int weight;
	edge();
	edge(int s, int d, int w){
		source = s; 
		dest = d;
		weight = w;
	}
};

bool compare(edge e1, edge e2){
	return (e1.weight < e2.weight);
}

bool detect_cycle(int* parent, int s, int d){

	while(parent[s] != s){
		s = parent[s];
	}

	while(parent[d] != d){
		d = parent[d];
	}

	int parent_s = s;
	int parent_d = d;


	if(parent_d == parent_s){
		return true;
	}
	else{
		parent[parent_d] = parent[parent_s];
		return false;
	}
}

int main(){

	vector<edge> graph;

	int v, e; cin>>v>>e;



	for(int i=0; i<e; i++){
		int s, d, w;
		cin>>s>>d>>w;
		graph.push_back(edge(s, d, w));
	}

	int parent[v];
	for(int i=0; i<v; i++)
		parent[i] = i;

	sort(graph.begin(), graph.end(), compare);


	cout << endl;

	vector<edge> mst;

	for(auto x : graph){
		if(mst.size() == v-1)
			break;

		if(!detect_cycle(parent, x.source, x.dest))
			mst.push_back(x);
	}

	for(auto x : mst){
        if(x.source > x.dest)
            swap(x.source, x.dest);
		cout << x.source << " " << x.dest << " " << x.weight << "\n";
	}	
	return 0;
}


