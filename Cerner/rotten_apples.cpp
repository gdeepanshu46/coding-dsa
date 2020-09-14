#include <bits/stdc++.h>
using namespace std;

int main(){

	int n, m; cin>>n>>m;
	int t; cin>>t;
	int arr[n][m], dp[n][m] = {0}; 

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
			dp[i][j] = 0;
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
			cin>>arr[i][j];
	}

	for(int p=0; p<t; p++){
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if((arr[i][j] == 2) && dp[i][j] == 0){

					if(j+1 < m && arr[i][j+1] == 1){
						dp[i][j+1] = 1;
						arr[i][j+1] = 2;
					}



					if(j-1 >= 0 && arr[i][j-1] == 1){
						dp[i][j-1] = 1;
						arr[i][j-1] = 2;
					}


					if(i+1 < n && arr[i+1][j] == 1){
						dp[i+1][j] = 1;
						arr[i+1][j] = 2;
					}


					if(i-1 >= 0 && arr[i-1][j] == 1){
						dp[i-1][j] = 1;
						arr[i-1][j] = 2;
					}
				}

			}
		}

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++)
				dp[i][j] = 0;
		}
		
	}	

	int c = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(arr[i][j] == 1)
				c++;
		}
	}

	cout << c << endl;

	return 0;
}