#include <bits/stdc++.h>
using namespace std;

int lps_(string s, int i, int j, vector<vector<int>> &dp){

	if(i >= s.size() || j<0 || i > j){
		dp[i][j] == 0;
		return dp[i][j];
	}

		

	if(i == j){
		dp[i][j] = 1;
		return dp[i][j];
	}

	if(dp[i][j]){
		return dp[i][j];
	}

	if(s[i] == s[j]){
		dp[i][j] = 2 + lps_(s, i+1, j-1, dp); 
		return dp[i][j];
	}

	dp[i][j] =  max(lps_(s, i, j-1, dp), lps_(s, i+1, j, dp));

	return dp[i][j];
}

int lps(string s){

	int n = s.size();

	vector<vector<int>> v(n, vector<int>(n, 0));
	return lps_(s, 0, s.size()-1, v);
}


int main(){

	string str = "hello";

	cout << lps(str);


	return 0;
}