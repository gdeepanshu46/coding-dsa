//This problem is a variation of Matrix Chain Multiplication, here we need to find the min cuts 
//so we will try to cut the string at every index possible and compute further recursively and
//combine the min results to form our solution. The problem does dp two times, while
//building Palin.. table and for computing min cuts.

#include <bits/stdc++.h>
using namespace std;


//Running two for loops and checking using isPalindrome takes O(n^3) time. Better way is:
//Building Palindromic table in O(n^2) to check if a substring is a palindrome
void isPalindrome_build(string& v, vector<vector<bool>>& isPalin){
	int n = v.size();

	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			int k = j - i;

			if(k == j){
				isPalin[k][j] = 1;
			}
			else if(v[k] != v[j]){
				isPalin[k][j] = 0;
			}
			else if(abs(k - j) == 1){
				isPalin[k][j] = 1;
			}
			else{
				isPalin[k][j] = isPalin[k+1][j-1];
			}
		}
	}
}

int min_cuts_(string& s, vector<vector<int>>& dp, vector<vector<bool>>& isPalin, int i, int j){

	//if it is a single char, than return 0 as it is already a palindrome
	if(i >= j){
		return dp[i][j] = 0;
	}

	//if string is palin.. return 0
	if(isPalin[i][j]){
		return dp[i][j] = 0;
	}

	if(dp[i][j] != -1) return dp[i][j];

	//else try all possible cuts at every index
	int k = i;

	int min_ = INT_MAX;

	while(k < j){
		min_ = min(min_, min_cuts_(s, dp, isPalin, i, k) + min_cuts_(s, dp, isPalin, k+1, j) + 1);
		k++;
	}

	return dp[i][j] = min_;
}

int min_cuts(string s){

	int n = s.size();
	vector<vector<bool>> isPalin(n, vector<bool> (n, 0));

	vector<vector<int>> dp(n, vector<int> (n, -1));

	isPalindrome_build(s, isPalin);

	return min_cuts_(s, dp, isPalin, 0, n-1);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin>>t;
	while(t--){
		string s; cin>>s;
		cout << min_cuts(s) << endl;
	}

	return 0;
}