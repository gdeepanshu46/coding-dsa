#include <bits/stdc++.h>
using namespace std;

//Time : O(n) | Space : O(1)
void arrange(vector<int>& v){

	int n = v.size();

	int i = 0;
	int j = 1;

	while(i < n){
		if(i%2 == 0){
			if(v[i]%2 == 0){
				i++;
				continue;
			}
			else{
				j = i+1;
				while(v[i]%2 == 1){
					swap(v[i], v[j++]);
				}
			}
		}
		else{
			if(v[i]%2 == 1){
				i++;
				continue;
			}
			else{
				j = i+1;
				while(v[i]%2 == 0){
					swap(v[i], v[j++]);
				}
			}
		}
	}
}

int main(){

	int n; cin>>n;
	vector<int> v(n);

	for(auto &x : v)
		cin>>x;

	arrange(v);

	for(auto x : v)
		cout << x << " ";
	return 0;
}
