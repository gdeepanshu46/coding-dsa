#include <bits/stdc++.h>
using namespace std;

bool isUnique(string s){
	int check = 0;
	for(int i=0; i<s.size(); i++){
		int temp = check | (1 << s[i] - 'a');
		if (temp == check){
			return false;
		}
		check = temp;
	}
	return true;
}

int main(){
	int a;
	//cout << sizeof(a) << endl;
	string s; cin >> s;
	cout << isUnique(s) << endl;
	return 0;
}