#include <bits/stdc++.h>
using namespace std;

int main(){

	int m, n; cin >> m >> n;

	int max_ = max(m, n);
	int first[max_][max_] = {0};
	int second[max_][max_] = {0};


	for(int i=0; i<max_; i++){
		for(int j=0; j<max_; j++){
			first[i][j] = 1;
			second[i][j] = 1;
		}
	}
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin>>first[i][j];
		}
	}

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin>>second[i][j];
		}
	}

	long long count1 = 0;
	long long count2 = 0;

	for(int i=0; i<max_; i++){
		for(int j=0; j<max_; j++){
			if(i == j){
				count1 += first[i][j];
			}
		}
	}

	for(int i=0; i<max_; i++){
		for(int j=0; j<max_; j++){
			if(i == j){
				count2 += second[i][j];
			}
		}
	}

	cout << abs(count1 - count2) << endl;


	return 0;
}
