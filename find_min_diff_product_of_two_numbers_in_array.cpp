#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	unordered_map<ll, ll> om; 
	int n; cin>>n;
	int arr[n];
	for(auto &x : arr) cin >> x;

	int m; cin>>m;

	int min_ = INT_MAX;
	int first, second;

	for(auto x : arr){
		if(m%x == 0 && om.find(m/x) != om.end()){
			if(abs(x - m/x) < min_){
				min_ = abs(x - m/x);
				first = max(x, m/x);
				second = min(x, m/x); 
			}
		}
		om[x] = 1;
	}

	if(min_ == INT_MAX) cout << "no found" << endl;
	else
		cout << first << " " << second << endl;
	return 0;
}