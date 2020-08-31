#include <bits/stdc++.h>
using namespace std;

void zigzag_traversal(vector<vector<int>> v){

	int n = v.size();

	int f = 1;

	for(int i=0; i<n; i++){

		if(f == 0){
			int i_ = i;
			int j_ = 0;

			while(i_ >= 0 && j_ < n){
				cout << v[i_][j_] << " ";
				i_--;
				j_++;
			}
			f = 1;
		}
		else{
			int i_ = 0;
			int j_ = i;

			while(i_ < n && j_ >= 0){
				cout << v[i_][j_] << " ";
				i_++;
				j_--;
			}
			f = 0;
		}
	}

	f = 1 - f;

	for(int j=1; j<n; j++){

		if(f == 0){
			int i = n-1;

			int i_ = j;
			int j_ = i;

			while(i_ < n && j_ >= 0){
				cout << v[i_][j_] << " ";
				i_++;
				j_--;
			}
			f = 1;
		}
		else{
			int i = n-1;

			int i_ = i;
			int j_ = j;

			while(i_ >= 0  && j_ < n){
				cout << v[i_][j_] << " ";
				i_--;
				j_++;
			}
			f = 0;
		}
		
	}

}

//Time : O(n^2)
//Space : O(n^2)
void print_diagonally(vector<vector<int>> v){

	int n = v.size();
	vector<vector<int>> res;
	for(int i=0; i<n; i++){
		vector<int> temp;

		int j = i;
		int k = 0;

		while(j >= 0 && k < n){
			temp.push_back(v[j][k]);

			j--;
			k++;
		}

		reverse(temp.begin(), temp.end());
		res.push_back(temp);
	}

	for(int j=1; j<n; j++){
		int i=j;
		int k=n-1;

		vector<int> temp;
		while(i < n){
			temp.push_back(v[k][i]);
			k--;
			i++;
		}

		reverse(temp.begin(), temp.end());
		res.push_back(temp);
	}

	for(auto x : res){
		for(auto y : x){
			cout << y << " " ;
		}
	}
}

//Time : O(n^2)
//Space : O(1)
void print_diagonally_(vector<vector<int>> v){

	int n = v.size();

	for(int i=0; i<n; i++){
		int i_ = 0;
		int j_ = i;

		while(i_ < n && j_ >= 0){
			cout << v[i_][j_] << " ";
			i_++;
			j_--;
		}
	}

	for(int j=1; j<n; j++){
		int i = n-1;

		int i_ = j;
		int j_ = i;

		while(i_ < n && j_ >= 0){
			cout << v[i_][j_] << " ";
			i_++;
			j_--;
		}
	}
}

int main(){

	int t; cin>>t;

	while(t--){

		int n; cin>>n;

		vector<vector<int>> v(n, vector<int>(n));

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> v[i][j];
			}
		}

		zigzag_traversal(v);
		cout << endl;
			
	}
	return 0;
}