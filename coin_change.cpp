#include <bits/stdc++.h>
using namespace std;



int total_ways(int* arr, int m, int n){
	vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

	for(int i = 0; i<m+1; i++){
		for(int j=0; j<n+1; j++){
			if(j == 0) dp[i][j] = 1;
			else if(i == 0) dp[i][j] = 0;
			else if(arr[i-1] > j){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = dp[i-1][j] + dp[i][j - arr[i-1]];			}
		}
	}

	return dp[m][n];
}

int main(){

	int n; cin>>n; 

	int m; cin>>m;
	int arr[m];
	for(int i=0; i<m; i++)
		cin>>arr[i];

	cout << total_ways(arr, m, n) << endl;

	return 0;
}	