#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
	string t = s;
	reverse(t.begin(), t.end());

	return (t == s);
}

int min_chars(string s){
	if(isPalindrome(s)) return 0;

	string t = s;

	t = t.substr(1);
	reverse(t.begin(), t.end());

	for(int i=1; i<t.size();i++){
		string tt = t.substr(i);
		if(s.find(tt) != string::npos && s.find(tt) == 0){
			return i;
		}
	}

	return t.size();

}

int main(){

	string s; cin>>s;
	cout << min_chars(s) << endl;
	return 0;
}