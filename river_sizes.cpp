#include <bits/stdc++.h>
using namespace std;
#define MAX 50

int check(int river[MAX][MAX], int visited[MAX][MAX], int n, int m, int i, int j){

	if(i<0 || i>n-1 || j<0 || j>m-1 || river[i][j] == 0 || visited[i][j] == 1)
		return 0;


	if(river[i][j] == 1 && visited[i][j] == 0){

		visited[i][j] = 1;

		int top =  check(river, visited, n, m, i-1, j);

		int down =  check(river, visited, n, m, i+1, j);
		
		int left =  check(river, visited, n, m, i, j-1);

		int right =  check(river, visited, n, m, i, j+1);

		int top_left =  check(river, visited, n, m, i-1, j-1);

		int top_right =  check(river, visited, n, m, i-1, j+1);

		int down_left =  check(river, visited, n, m, i+1, j-1);

		int down_right =  check(river, visited, n, m, i+1, j+1);
		
		return 1 + top+down+left+right+top_left+top_right+down_left+down_right;
	}
}

int river_sizes(int river[MAX][MAX], int visited[MAX][MAX], int n, int m){
	int largest_region = 0;
	int region = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(river[i][j] == 1 && visited[i][j] == 0){
				region = check(river, visited, n, m, i, j);
				if(region > largest_region)
					largest_region = region;
			}
		}
	}
	return largest_region;
}

int main(){

	int t; cin>>t;
	while(t--){

		int n, m; cin>>n>>m;
		int river[MAX][MAX];
		int visited[MAX][MAX];
		memset(river, 0, MAX*MAX*sizeof(int));
		memset(visited, 0, MAX*MAX*sizeof(int));

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin>>river[i][j];
			}
		}

		cout << river_sizes(river, visited, n, m) << endl;
	}
	

	return 0;
}




