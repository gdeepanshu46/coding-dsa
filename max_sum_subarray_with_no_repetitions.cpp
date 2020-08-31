#include<bits/stdc++.h>
using namespace std;

//Time : O(n) | Space : O(n)
int max_sum(vector<int>& v){

	//store last index of the element
	map<int, int> mp;

	int n = v.size();

	//Build a prefix sum array to get sum between indexes in O(1)
	vector<int> prefix(n);
	prefix[0] = v[0];
	int sum = v[0];
	for(int i=1; i<n; i++){
		sum += v[i];
		prefix[i] = sum;
	}

	//left index of the window
	int left = 1;
	
	//sum counter
	sum = 0;

	//max value that will be achieved
	int max_ = *max_element(v.begin(), v.end());
	
	//If for any ele, its position lies inside our window or pos >= left, that means we need to
	//find sum after that pos and mark its new pos
	for(int i=0; i<n; i++){
		if(mp[v[i]] < left){
			mp[v[i]] = i+1;
			sum += v[i];
			
		}
		else{
			left = mp[v[i]]+1;
			sum = prefix[i] - prefix[left-2];
			mp[v[i]] = i+1;
		}
		max_ = max(max_, sum);
	}
	return max_;
}

int main(){

	int n; cin>>n;
	vector<int> v(n);
	for(auto &x : v)
		cin>>x;
	cout << max_sum(v);
	return 0;
}