#include <bits/stdc++.h>
using namespace std;

//DP solution

int knapsack_dp(vector<int> val, vector<int> weight, int w){
	int n = val.size();

	vector<vector<int>> dp(n+1, vector<int>(w+1, 0));

	for(int i=0; i<n+1; i++){
		for(int j=0; j<w+1; j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}
			else if(weight[i-1] > j){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = max(val[i-1] + dp[i-1][j-weight[i-1]], dp[i-1][j]);
			}
		}
	}
	return dp[n][w];
}


//Exponential solution
int knapsack(vector<int> val, vector<int> weight, int w, int i){

	if(i >= val.size() || w <= 0)
		return 0;

	int include_ = 0;
	if(weight[i] <= w)
		include_ = val[i] + knapsack(val, weight, w-weight[i], i+1);
	int disclude_ = knapsack(val, weight, w, i+1);

	return max(include_, disclude_);
}

int knapsack_(vector<int> val, vector<int> weight, int w){
	return knapsack(val, weight, w, 0); 
}


int main(){

	int t; cin>>t;
	while(t--){
		int n; cin>>n; 
		int w; cin>>w;
		vector<int> val(n); 
		vector<int> weight(n);
		for(int i=0; i<n; i++){
			cin>>val[i];
		}

		for(int i=0; i<n; i++){
			cin>>weight[i];
		}

		cout << knapsack_dp(val, weight, w);
	}

	


	return 0;
}