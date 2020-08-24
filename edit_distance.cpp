#include <bits/stdc++.h>
using namespace std;

int edit_(string s1, string s2, int i, int j, vector<vector<int>>& dp){
	
	if(i == s1.size() && j == s2.size())
		return 0;

	if(i == s1.size()){
		dp[i][j] = s2.size()-j;
		return dp[i][j];
	}

	if(j == s2.size()){
		dp[i][j] = s1.size()-i;
		return dp[i][j];
	}

	if(dp[i][j]>0)
		return dp[i][j];

	//if both the char are equal, we can skip them
	if(s1[i] == s2[j]){
		dp[i][j] = edit_(s1, s2, i+1, j+1, dp);
	}

	//else we can do 1 of the 3 operations on them, insert remove or replace
	else{
		dp[i][j] = 1 + min(edit_(s1, s2, i, j+1, dp), min(edit_(s1, s2, i+1, j+1, dp), edit_(s1, s2, i+1, j, dp)));
	}

	return dp[i][j];
}

int edit(string s1, string s2){

	int n = s1.size();
	int m = s2.size();

	vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
	return edit_(s1, s2, 0, 0, dp);
}

int main(){

	string s1 = "hello";
	string s2 = "abcd";

	cout << edit(s1, s2);


	return 0;
}