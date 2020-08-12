#include <bits/stdc++.h>
using namespace std;

string str = "abc";
int n = str.size();


bool isPalindrome(string s){

	string t = s;
	reverse(t.begin(), t.end());

	return s == t;

}

int ans = INT_MAX;


int check(int pos){

	if(pos == n)
		return 0;

	string curr = "";

	for(int i=pos; i<n; i++){
		curr += str[i];

		if(isPalindrome(curr)){
			int other = check(i+1);

			if(other != -1){
				ans = min(ans, other+1);
			}
		}
	}

	return (ans == INT_MAX)? -1: ans;
}

void minCuts(){

	int res = check(0);
	cout << ans << endl;
}


int main(){

	minCuts();
	return 0;
}