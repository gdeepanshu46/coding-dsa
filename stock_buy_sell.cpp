#include <bits/stdc++.h>
using namespace std;

//Max profit with atmost 1 transaction
int stock_1(vector<int> v){
	int n = v.size();
	if(n == 0) return 0;

	int max_profit = 0;
	int min_val = INT_MAX;

	for(int i=0; i<n; i++){
		min_val = min(min_val, v[i]);
		max_profit = max(max_profit, v[i] - min_val);
	} 

	return max_profit;
}

//Max profit with atmost 2 transactions
int stock_2(vector<int> v){
	int n = v.size();

	if(n == 0) return 0;

	vector<int> first(n), second(n);

	int max_profit = 0;
	int min_val = INT_MAX;

	for(int i=0; i<n; i++){
		min_val = min(min_val, v[i]);
		max_profit = max(max_profit, v[i] - min_val);
		first[i] = max_profit;
	}

	max_profit = 0;
	int max_val = INT_MIN;

	for(int i=n-1; i>=0; i--){
		max_val = max(max_val, v[i]);
		max_profit = max(max_profit, max_val - v[i]);
		second[i] = max_profit;
	}

	max_profit = 0;

	for(int i=0; i<n; i++){
		max_profit = max(max_profit, first[i]+second[i]);
	}

	return max_profit;
}

//printing Pairs of transactions
void stock_pairs(vector<int> v){
	int left = -1;
	int right = -1;
	int n = v.size(); 

	int f = 0;

	for(int i=0; i<n-1; i++){
		if(v[i] < v[i+1]){
			if(left != -1){
				right = i+1;
			}
			else{
				left = i;
				right = i+1;
			}
		}
		else{
			if(left != -1){
				f = 1;
				cout << "(" << left << " " << right << ")" << " ";
				left = -1;
				right = -1;
			}
		}
	}
	if(left != -1){
		f = 1;
		cout << "(" << left << " " << right << ")" << endl;
	}

	if(f == 0){
		cout << "No Profit" << endl;
	}
}

//Max profit with atmost K transactions -> DP solution : Time = O(n*k) Space = O(n*k)
int stock_k(vector<int> price, int k){
	int n = price.size();

	if(n == 0) return 0;

	vector<vector<int>> dp(k+1, vector<int>(n, 0));

	for(int i=0; i<k+1; i++){
		int max_ = INT_MIN;
		for(int j=0; j<n; j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
				continue;
			}

			max_ = max(max_, -price[j-1] + dp[i-1][j-1]);

			dp[i][j] = max(dp[i][j-1], price[j] + max_);
		}
	}


	return dp[k][n-1];
} 

//Max profit with atmost K transactions -> DP solution : Time = O(n*k) Space = O(n)
int stock_k_(vector<int> price, int k){
	int n = price.size();

	if(n == 0) return 0;

	vector<int> oddProfits(n, 0), evenProfits(n, 0);
	vector<int>	currentProfits(n), previousProfits(n);


	for(int i=1; i<k+1; i++){

		int max_val = INT_MIN;
		
		if(i%2 == 0){
			currentProfits = evenProfits;
			previousProfits = oddProfits;
		}
		else{
			currentProfits = oddProfits;
			previousProfits = evenProfits;
		}

		for(int j=1; j<n; j++){
			max_val = max(max_val, -price[j-1] + previousProfits[j-1]);
			currentProfits[j] = max(currentProfits[j-1], price[j] + max_val);
			if(i%2 == 1){
				oddProfits = currentProfits;
			}
			else{
				evenProfits = currentProfits;
			}
		}
	}

	return currentProfits[n-1];
	
} 

int main(){

	int t; cin>>t;
	while(t--){
		
		int k; cin>>k;
		int n; cin>>n;

		vector<int> v(n);
		for(auto &x : v){
			cin >> x;
		}

		cout << stock_k_(v, k) << endl;
	}

	


	return 0;
}