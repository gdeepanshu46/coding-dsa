#include <bits/stdc++.h>
using namespace std;


int lcs_(string s1, string s2, int i, int j, vector<vector<int>> &dp){

	if(i >= s1.size() || j >= s2.size()){
		return 0;
	}

	if(dp[i][j] != -1)
		return dp[i][j];


	if(s1[i] == s2[j]){
		dp[i][j] = (1 + lcs_(s1, s2, i+1, j+1, dp));
	}
	else{

		dp[i][j] = (max(lcs_(s1, s2, i, j+1, dp), lcs_(s1, s2, i+1, j, dp)));
	}

	return dp[i][j];
}



int lcs(string s1, string s2){
	int n = s1.size();
	int m = s2.size();
	vector<vector<int>> v(n, vector<int>(m, -1));
	return lcs_(s1, s2, 0, 0, v);
}

int main(){

	// string s1 = "abbcdgf";
	// string s2 = "bbadcgf";

	string s1 = "abecidj";
	string s2 = "abcd";

	cout << lcs(s1, s2);


	return 0;
}