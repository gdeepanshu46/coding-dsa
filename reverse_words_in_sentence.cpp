#include <bits/stdc++.h>
using namespace std;

int main(){

	string s; 
	getline(cin, s);

	reverse(s.begin(), s.end());

	stringstream sso;

	sso << s;

	string temp;

	while(sso >> temp){
		reverse(temp.begin(), temp.end());
		cout << temp << " ";
	}

	return 0;
}