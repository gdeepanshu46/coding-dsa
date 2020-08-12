#include <bits/stdc++.h>
using namespace std;
#define MAX 100

bool isPresent(int matrix[MAX][MAX], int n, int m, int x){
	int row = 0, col = m-1;

	while(row < n && col >= 0){
		if(matrix[row][col] == x)
			return true;
		else if(x > matrix[row][col]){
			row++;
		}
		else{
			col--;
		}
	}
	return false;

}

int main(){

	int t; cin>>t;
	while(t--){
		int n, m; cin>>n>>m;
		int matrix[MAX][MAX];

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++)
				cin>>matrix[i][j];
		}

		int x; cin>>x;

		cout << isPresent(matrix, n, m, x) << endl;
	}
	

	return 0;
}