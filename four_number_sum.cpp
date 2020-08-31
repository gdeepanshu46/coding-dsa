#include <bits/stdc++.h>
using namespace std;

//O(n^3) solution using two pointer approach
bool four_number_sum(vector<int> v, int k){

	int n = v.size();
	if(n == 0) return 0;

	sort(v.begin(), v.end());

	for(int i=0; i<n-3; i++){
		for(int j=i+1; j<n-2; j++){
			int s = j;
			int e = n-1;

			while(s < e){
				int sum = v[i] + v[j] + v[s] + v[e];

				if(sum == k){
					return 1;
				}
				else if(sum < k){
					s++;
				}
				else{
					e--;
				}
			}
		}
	}
	return 0;
}

//O(n^2) solution in average case
//using sum of two numbers concept along with hashing
vector<vector<int>> four_number_sum_(vector<int> v, int k){
	int n = v.size();

	map<int, vector<vector<int>>> mp;

	vector<vector<int>> res;

	for(int i=0; i<n-1; i++){

		for(int j=i+1; j<n; j++){
			int diff = k - (v[i] + v[j]);
			if(mp.count(diff)){

				auto temp = mp[diff];

				for(auto x : temp){
					vector<int> t; 
					t.push_back(v[i]);
					t.push_back(v[j]);
					t.push_back(x[0]);
					t.push_back(x[1]);
					res.push_back(t);
				}
			}
		}

		for(int k=0; k<i; k++){
			if(mp.count(v[i] + v[k])){
				mp[v[i] + v[k]].push_back({v[i], v[k]});
			}
			else{
				mp.insert({v[i] + v[k], {{v[i], v[k]}} });
			}

		}
	}
	return res;
}

int main(){

	int t; cin >> t; 
	while(t--){
		int n; cin>>n; 
		vector<int> v(n);

		for(auto &x : v)
			cin >>x;

		int k; cin>>k;

		//cout << four_number_sum(v, k) << endl;	
		
		auto result = four_number_sum_(v, k);

		for(auto x : result){
			sort(x.begin(), x.end(), greater<int>());
			cout << x[0] << " " << x[1] << " " << x[2] << " " << x[3] << endl;
		}

		cout << endl;
	}
	
	return 0;
}