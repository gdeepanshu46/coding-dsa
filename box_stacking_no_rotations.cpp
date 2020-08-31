//This problem is a variation of LIS, where we need to stack up boxes such that
//we can get maximum heights possible, without rotating boxes and also upper box
//should be less than lower box in respect to every dimension.

#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<int> v1, vector<int> v2){
	return v1[2] < v2[2];
}

int box_stacking_max(vector<vector<int>> v){

	int n = v.size();

	//sort all the boxes on the basis of height in asc order.
	sort(v.begin(), v.end(), comparator);

	vector<int> temp(n);


	//store corresponding max heights of each box;
	for(int i=0; i<n; i++){
		temp[i] = v[i][2];
	}


	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			if((v[i][0] > v[j][0]) && (v[i][1] > v[j][1]) && (v[i][2] > v[j][2])){
				temp[i] = max(temp[i], v[i][2] + temp[j]);
			}
		}
	}

	int res = *max_element(temp.begin(), temp.end());

	for(auto x : temp)
		cout << x << " ";
	cout << endl;

	return res;
}

int main(){

	int n; cin>>n;

	vector<vector<int>> v(n, vector<int>(3));

	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			cin >> v[i][j];
		}
	}

	cout << box_stacking_max(v) << endl;


	return 0;
}