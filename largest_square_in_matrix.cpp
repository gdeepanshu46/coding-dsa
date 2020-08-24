#include <bits/stdc++.h>
using namespace std;

//memoized version
int check_(vector<vector<int>> v, int i, int j, vector<vector<int>>& dp){
	if(i < 0 || i >= v.size() || j < 0 || j >= v[0].size() || v[i][j] == 0)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];

	dp[i][j] = 1 + min(check_(v, i+1, j, dp), min(check_(v, i, j+1, dp), check_(v, i+1, j+1, dp)));
	return dp[i][j];
}

int largest_square(vector<vector<int>> v){
	int n = v.size();
	int m = v[0].size();

	vector<vector<int>> dp(n, vector<int>(m, -1));

	int max_ = INT_MIN;


	for(int i=0; i<n; i++){
		for(auto j=0; j<m; j++){
			int temp = check_(v, i, j, dp);
			max_ = max(max_, temp);
		}
	}

	return max_;

}

//tabulation version
int largest_square_(vector<vector<int>> v){
	int n = v.size();
	int m = v[0].size();

	vector<vector<int>> dp(n, vector<int>(m, 0));

	int max_ = -1;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(i == 0 || j == 0){
				dp[i][j] = v[i][j];
			}
			else{
				if(v[i][j] == 0){
					dp[i][j] = 0;
				}
				else{
					dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
				}
			}

			max_ = max(max_ , dp[i][j]);
		}
	}

	return max_;
}

int main(){

	int t; cin>>t;

	while(t--){
		int n , m; cin>>n>>m;
		vector<vector<int>> v(n, vector<int>(m, 0));

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin>>v[i][j];
			}
		}

		cout << largest_square_(v)<< endl;
	}
	return 0;
}

