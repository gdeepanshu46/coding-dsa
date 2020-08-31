#include <bits/stdc++.h>
using namespace std;


int min_cost_(const vector<int>& v, vector<vector<int>>& dp, int s, int e){

	if(s == e){
		dp[s][e] = 0;
		return 0;
	}

	if(dp[s][e] != -1){
		return dp[s][e];
	}

	int i = s;
	int j = e;

	int res = INT_MAX;
	while(i < e){

		dp[s][i] = min_cost_(v, dp, s, i);
		dp[i+1][e] = min_cost_(v, dp, i+1, e);

		res = min(res, dp[s][i] + dp[i+1][e] + v[s-1]*v[i]*v[e]);
		i++;
	}
	dp[s][e] = res;

	return res;
}

int min_cost(const vector<int>& v){

	int n = v.size();

	vector<vector<int>> dp(n, vector<int> (n, -1));

	int res = min_cost_(v, dp, 1, n-1);

	return res;
}

int main(){

	int t; cin>>t;

	while(t--){
		int n; cin>>n; 
		vector<int> v(n);
		for(auto &x : v)
			cin >> x;

		cout << min_cost(v) << endl;
	}
	return 0;
}