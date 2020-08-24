#include <bits/stdc++.h>
using namespace std;

int possible_triangles_(vector<int> v, int s, int e, int val){
	int count = 0;
	while(s < e){

		if(v[s] + v[e] > val){
			count += e-s;
			e--;
		}
		else{
			s++;
		}
	}
	return count;
}

int possible_triangles(vector<int> v){

	int n = v.size();
	if(n < 3){
		return 0;
	}

	int possible = 0;
	for(int i=n-1; i>=2; i--){
		possible += possible_triangles_(v, 0, i-1, v[i]);
	}

	return possible;
}

int main(){

	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> v(n);
		for(auto &x : v)
			cin>>x; 
		sort(v.begin(), v.end());
		cout << possible_triangles(v) << endl;
	}

	
	return 0;
}