#include <bits/stdc++.h>
using namespace std;

int main()
{
	
	map<char, int> mp1, mp2;

	string input; cin>>input;

	int t; cin>>t;

	map<char, char> res;

	vector<pair<string, string>> queries(t);

	for(int i=0; i<t; i++){
		cin >> queries[i].first;
		cin >> queries[i].second;
	}

	

	for(int i=0; i<t; i++){
		string s1 = queries[i].first;
		string s2 = queries[i].second;
		map<char, int> mp1, mp2;

		for(auto x : s1){
			mp1[x]++;
		}

		for(auto x : s2){
			mp2[x]++;
		}

		vector<pair<int, char>> v1, v2;

		for(auto x : mp1){
			v1.push_back({x.second, x.first});
		}


		for(auto x : mp2){
			v2.push_back({x.second, x.first});
		}

		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());

		int n = v1.size();

		for(int i=0; i<n; i++){
			if(i == 0){
				if(v1[i].first != v1[i+1].first){
					res[v1[i].second] = v2[i].second;
				}	
			}
			else if(i==n-1){
				if(v1[i].first != v1[i-1].first){
					res[v1[i].second] = v2[i].second;
				}
			}

			if(v1[i].first != v1[i+1].first && v1[i].first != v1[i-1].first){
				res[v1[i].second] = v2[i].second;
			}
		}
	}	

	int f = 0;
	for(auto x : input){
		if(res.find(x) == res.end()){
			f = 1;
		}
	}

	if(f == 0){
		for(auto x : input){
			cout << res[x];
		}
		return 0;
	}

	while(1){
		for(int i=1; i<2; i++){
			string s1 = queries[i].first;
			string s2 = queries[i].second;
			map<char, int> mp1, mp2;

			for(auto x : s1){
				mp1[x]++;
			}

			for(auto x : s2){
				mp2[x]++;
			}

			for(auto x : res){
				if(mp1.find(x.first) != mp1.end()){
					mp1.erase(x.first);
					mp2.erase(x.second);
				}
			}

			vector<pair<int, char>> v1, v2;

			for(auto x : mp1){
				v1.push_back({x.second, x.first});
			}


			for(auto x : mp2){
				v2.push_back({x.second, x.first});
			}

			sort(v1.begin(), v1.end());
			sort(v2.begin(), v2.end());

			int n = v1.size();

			if(n == 1){
				res[v1[0].second] = v2[0].second;
				continue;
			}

			for(int i=0; i<n; i++){
				if(i == 0){
					if(v1[i].first != v1[i+1].first){
						res[v1[i].second] = v2[i].second;
					}	
				}
				else if(i==n-1){
					if(v1[i].first != v1[i-1].first){
						res[v1[i].second] = v2[i].second;
					}
				}

				if(v1[i].first != v1[i+1].first && v1[i].first != v1[i-1].first){
					res[v1[i].second] = v2[i].second;
				}
			}
		}

		f = 0;
		for(auto x : input){
			if(res.find(x) == res.end()){
				f = 1;
			}
		}

		if(f == 0){
			for(auto x : input){
				cout << res[x];
			}
			break;
		}
	}




	return 0;
}
