#include <bits/stdc++.h>
using namespace std;


//Time : O(n)
//Space : O(1) using Lower Envelope Technique
// https://www.youtube.com/watch?v=XqTBrQYYUcc

int trapping_rain_water(vector<int> v){
	int n = v.size();

	//if pillars less than 3 no water can be trapped
	if(n < 3) return 0;

	int i = 0;
	int j = n-1;

	int l_max = 0;
	int r_max = 0;

	int water = 0;

	while(i <= j){

		l_max = max(l_max, v[i]);
		r_max = max(r_max, v[j]);
		
		if(l_max <= r_max){
			water += (l_max - v[i]);
			i++;
		}
		else{
			water += (r_max - v[j]);
			j--;
		}
	}

	return water;
}

int main(){

	int t; cin>>t;

	while(t--){
		
		int n; cin>>n;
		vector<int> v(n);

		for(auto &x : v)
			cin >> x;

		cout << trapping_rain_water(v) << endl;		
	}

	return 0;
}
