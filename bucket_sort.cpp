#include <bits/stdc++.h>
using namespace std;

void bucket_sort(vector<float>& v){
	int n = v.size();
	vector<float> b[n];

	for(int i=0; i<n; i++){
		int ind = v[i]*n;
		b[ind].push_back(v[i]);
	}

	for(int i=0; i<n; i++){
		sort(b[i].begin(), b[i].end());
	}

	int index = 0; 

	for(int i=0; i<n; i++){
		for(int j=0; j<b[i].size(); j++){
			v[index++] = b[i][j];
		}
	}
}

int main(){

	int n = 10;
	vector<float> v = {0.78, 0.17, 0.39, 0.26, 0.79, 0.94, 0.21, 0.12, 0.23, 0.68};
	bucket_sort(v);

	for(auto x : v){
		cout << x << " " ;
	}

	return 0;
}
