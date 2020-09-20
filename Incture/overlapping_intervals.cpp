#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> merge(vector<pair<int, int>> v){
	sort(v.begin(), v.end());

	vector<pair<int, int>> ans;
	ans.push_back(v[0]);

	for(int i=1; i<v.size(); i++){
		auto curr = v[i];
		auto p = ans[ans.size()-1];

		if(curr.first > p.second){
			ans.push_back(curr);
		}
		else if(curr.second > p.second){
			ans[ans.size()-1].second = curr.second;
		}
		
	}
	return ans;
}

int main(){

	int t; cin>>t;

	while(t--){

		int n; cin>>n;
		vector<pair<int, int>> v;

		for(int i=0; i<n; i++){
			int a, b;
			cin>>a>>b;
			v.push_back({a, b});
		}

		auto ans = merge(v);

		for(auto x : ans)
			cout << x.first << " "<< x.second << " ";
	
	}

	


	return 0;
}
