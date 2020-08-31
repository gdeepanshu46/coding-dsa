//Moore Voting Algorithm is used to find the majority ele using O(1) space
//It works on the fact that, if a majority ele exists it will cancel out all
//the minority elements

#include <bits/stdc++.h>
using namespace std;

int majority_ele(vector<int>& v){

	int n = v.size();
	int ele = v[0];
	int count = 0;

	for(auto x : v){
		if(ele == x){
			count++;
		}
		else{
			count--;
			if(count == 0){
				count = 1;
				ele = x;
			}
		}
	}

	count = 0;

	for(auto x : v)
		if(x == ele)
			count++;

	if(count > n/2)
		return ele;
	return -1;
}

int main(){

	int n; cin>>n; 
	vector<int> v(n);
	for(auto &x : v)
		cin >> x;

	cout << majority_ele(v) << endl;
	return 0;
}