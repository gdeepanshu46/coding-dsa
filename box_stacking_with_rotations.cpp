//This problem is a variation of LIS, where we need to stack up boxes such that
//we can get maximum heights possible, with rotation allowed on boxes and also upper box
//should be less than lower box in respect to both length and width only.

#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<int> v1, vector<int> v2){
	return v1[0]*v1[1] > v2[0]*v2[1];
}

vector<vector<int>> combination_possible(vector<vector<int>> v){

	int n = v.size();
	vector<vector<int>> v_temp;

	for(int i=0; i<n; i++){
		if(v[i][0] < v[i][1]){
			swap(v[i][0], v[i][1]);
		}
	}

	for(int i=0; i<n; i++){
		int first = v[i][0];
		int second = v[i][1];
		int third = v[i][2];

		vector<int> p0, p1, p2;

		p0.push_back(first);
		p0.push_back(second);
		p0.push_back(third);

		if(second > third){
			p1.push_back(second);
			p1.push_back(third);
			p1.push_back(first);
		}
		else{
			p1.push_back(third);
			p1.push_back(second);
			p1.push_back(first);
		}

		if(first > third){
			p2.push_back(first);
			p2.push_back(third);
			p2.push_back(second);
		}
		else{
			p2.push_back(third);
			p2.push_back(first);
			p2.push_back(second);
		}

		v_temp.push_back(p0);
		v_temp.push_back(p1);
		v_temp.push_back(p2);
	}
	return v_temp;
}


int box_stacking_max(vector<vector<int>> v){

	
	v = combination_possible(v);

	int n = v.size();

	sort(v.begin(), v.end(), comparator);

	vector<int> res(n);

	for(int i=0; i<n; i++){
		res[i] = v[i][2];
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			if((v[i][0] < v[j][0]) && (v[i][1] < v[j][1])){
				res[i] = max(res[i], v[i][2] + res[j]);
			}
		}
	}

	int result = *max_element(res.begin(), res.end());

	return result;

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