#include <bits/stdc++.h>
using namespace std;

void powerset(string s, string temp = ""){
	if(!s.size()){
		cout << temp << " ";
		return;
	}

	powerset(s.substr(1), temp);
	powerset(s.substr(1), temp + s[0]);
}

int main(){

	string s = "abc";
	powerset(s);
	return 0;
}
