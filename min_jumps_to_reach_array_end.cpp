#include <bits/stdc++.h>
using namespace std;

int min_jump(vector<int> v){
	
	if(v[0] == 0){
		return -1;
	}
	int n = v.size();
	vector<int> dp(n);

	dp[n-1] = 0;

	for(int i=n-2; i>=0 ; i--){
		if(v[i] == 0){
			dp[i] = INT_MAX;
		}
		else if(v[i] + i >= n-1){
			dp[i] = 1;
		}
		else{

			int min_ = INT_MAX;
			for(int j=i+1; j <= v[i]+i; j++){
				min_ = min(min_, dp[j]);
			}

			if(min_ == INT_MAX){
				dp[i] =  INT_MAX;
			}
			else
				dp[i] = min_ + 1;
		}
	}

	if(dp[0] == INT_MAX)
		return -1;
	else
		return dp[0];
}

int main(){

	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> v(n);
		for(auto &x : v)
			cin>>x;

		cout << min_jump(v) << endl;
	}

	return 0;
}
