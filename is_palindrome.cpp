#include<bits/stdc++.h>
using namespace std;

//Note : Every sub-string in a palin.. has its reverse in the palin..
bool isPalindrome(string s){
    string t = s;
    reverse(t.begin(), t.end());
    
    return s == t;
}

int main(){

	string s; cin>>s;

	cout << isPalindrome(s) << endl;

	return 0;
}

