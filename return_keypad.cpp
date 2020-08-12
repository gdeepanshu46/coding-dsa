#include <bits/stdc++.h>
using namespace std;

void keypad(string s, vector<string> v, string empty){
	if(s.size() == 0){
		cout << empty << endl;
		return;
	}
	
	int num = s[0] - 48;
	for(int j=0; j<v[num].size(); j++){
		keypad(s.substr(1), v, empty + v[num][j]);
	}
}

int main(){
	
	long long n; cin>>n;
	vector<string> v(10);

	v[2] = "abc";
	v[3] = "def";
	v[4] = "ghi";
	v[5] = "jkl";
	v[6] = "mno";
	v[7] = "pqrs";
	v[8] = "tuv";
	v[9] = "wxyz";

	string s = to_string(n);

	keypad (s, v, "");
	
	// for(int i=2; i<10; i++){
	// 	for(auto x : v[i]){
	// 		cout << x <<" ";
	// 	}
	// 	cout <<endl;
	// }

	return 0;
}