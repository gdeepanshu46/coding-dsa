#include <bits/stdc++.h>
using namespace std;


//Time Complexity : 2^N
int interleaving_strings(string s1, string s2, string s3){

	if(s1.size() + s2.size() != s3.size())
		return 0;

	if(s1.empty() && s2.empty())
		return 1;

	bool first =  (s1[0] == s3[0]) && interleaving_strings(s1.substr(1), s2, s3.substr(1));
	bool second = (s2[0] == s3[0] && interleaving_strings(s1, s2.substr(1), s3.substr(1)));

	return first || second;

}


int main(){

	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	cout << interleaving_strings(s1, s2, s3);
	return 0;
}