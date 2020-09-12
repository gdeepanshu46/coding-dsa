#include <bits/stdc++.h>
using namespace std;

void set_(vector<vector<int>>& v){

	int n = v.size();
	int m = v[0].size();

	//check if first row or col has any 1 value
	bool row = false;
	bool col = false;

	for(int i=0; i<n; i++){
		if(v[i][0] == 1){
			row = true;
			break;
		}	
	} 

	for(int j=0; j<m; j++){
		if(v[0][j] == 1){
			col = true;
			break;
		}
	}


	//now use first row and col as dummy arrays to store values for each row and col
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			if(v[i][j] == 1){
				v[i][0] = 1;
				v[0][j] = 1;
			}
		}
	}

	//check if corresponding row or col value has 1 or not, accordingly mark current ele
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			if(v[i][0] == 1 || v[0][j] == 1){
				v[i][j] = 1;
			}
		}
	}

	//finally if first row had a single 1 fill it with 1's
	if(row){
		for(int i=0; i<n; i++){
			v[i][0] = 1;
		}
	}

	//do it for first col as well
	if(col){
		for(int j=0; j<m; j++){
			v[0][j] = 1;
		}
	}

}

int main(){

	int n, m; cin>>n>>m;

	vector<vector<int>> v(n, vector<int> (m));

	for(auto &x : v){
		for(auto &y : x)
			cin >> y;
	}

	set_(v);

	for(auto x : v){
		for(auto y : x)
			cout << y << " ";
		cout << endl;
	}
	return 0;
}