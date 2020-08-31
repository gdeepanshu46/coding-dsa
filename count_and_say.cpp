#include<bits/stdc++.h>
using namespace std;

string convert(string s){

	vector<pair<int, char>> v;
	map<char, int> mp;

	int n = s.size();
	for(int i=0; i<n; i++){

		if(i == n-1){
			if(mp.find(s[i]) == mp.end()){
				v.push_back({1, s[i]});
			}
			else{
				v.push_back({mp[s[i]], s[i]});
			}
			continue;
		}

		if(s[i] == s[i+1]){
			if(mp.find(s[i]) == mp.end()){
				mp[s[i]] = 2;
			} 
			else{
				mp[s[i]]++;
			}
		}
		else{
			if(mp.find(s[i]) == mp.end()){
				v.push_back({1, s[i]});
			}
			else{
				
				v.push_back({mp[s[i]], s[i]});
				mp.erase(s[i]);
			}
		}
	}

	string res;

	for(auto x : v){
		res += to_string(x.first);
		res += x.second; 
	}

	return res;
}

int main(){

	int n; cin>>n;
	string res = "1";

	for(int i=0; i<n-1; i++){
		res = convert(res);
	}
	
	cout << res << endl;
	

	return 0;
}