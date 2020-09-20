#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){

	vector<int> v(5);
	for(auto &x : v)
		cin >> x;

	for(auto i = v.begin(); i != v.end(); i++)
		cout << *i << " " ;
	
	return 0;
}