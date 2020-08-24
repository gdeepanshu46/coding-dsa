#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotate_matrix_clockwise(vector<vector<int>> v){
	int n = v.size();
	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			swap(v[i][j], v[j][i]);
		}
	}

	for(int i=0; i<n; i++){
		reverse(v[i].begin(), v[i].end());
	}

	return v;

}

vector<vector<int>> rotate_matrix_anti_clockwise(vector<vector<int>> v){
	int n = v.size();
	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			swap(v[i][j], v[j][i]);
		}
	}

	for(int i=0; i<n/2; i++){
		for(int j=0; j<n; j++){
			swap(v[i][j], v[n-1-i][j]);
		}
	}

	return v;

}

vector<vector<int>> reverse_row_wise(vector<vector<int>> v){
	int n = v.size();
	
	//reverse rows
	for(int i=0; i<n; i++){
		for(int j=0; j<n/2; j++){
			swap(v[i][j], v[i][n-1-j]);
		}
	}

	return v;

}

vector<vector<int>> reverse_col_wise(vector<vector<int>> v){
	int n = v.size();
	
	//reverse columns
	for(int i=0; i<n/2; i++){
		for(int j=0; j<n; j++){
			swap(v[i][j], v[n-1-i][j]);
		}
	}

	return v;

}

void print_(vector<vector<int>>& v){
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[0].size(); j++){
			cout << v[i][j] << " " ;
		}
		cout << endl;
	}
	cout << endl;
}

int main(){

	int n = 3;
	vector<vector<int>> v(n, vector<int> (n));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cin>>v[i][j];
	}

	auto res1 = reverse_row_wise(v);

	print_(res1);

	auto res2 = reverse_col_wise(v);

	print_(res2);

	auto res3 = rotate_matrix_clockwise(v);

	print_(res3);

	auto res4 = rotate_matrix_anti_clockwise(v);

	print_(res4);


	return 0;
}