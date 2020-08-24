#include <bits/stdc++.h>
using namespace std;

int distinct_subsequences(string s1, string s2){
	
	int n = s2.size();
	int m = s1.size();
	if(n == 0 || m == 0){
		return 0;
	}

	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	for(int i=0; i<n+1; i++){
		for(int j=0; j<m+1; j++){
			if(i == 0){
				dp[i][j] = 1;
			}
			else if(j == 0){
				dp[i][j] = 0;
			}
			else{
				if(s2[i-1] == s1[j-1]){
					dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
				}
				else{
					dp[i][j] = dp[i][j-1];
				}
			}
		}
	}

	return dp[n][m];

}

int main(){

	string s1, s2;
	cin >> s1 >> s2;
	cout << distinct_subsequences(s1, s2) << endl;

	return 0;
}