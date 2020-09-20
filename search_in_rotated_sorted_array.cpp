#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &v, int target){
	int start = 0;
	int end = v.size()-1;

	while(start <= end){
		int mid = start + (end - start)/2;

		//if the mid index ele is target, return mid
		if(v[mid] == target) return mid;

		//check if left subarray is rightly sorted
		else if(v[start] <= v[mid]){

			//if target lies in left half
			if(v[start] <= target && target <= v[mid])
				end = mid - 1;

			//if target lies in right half
			else
				start = mid + 1;
		}

		//check if right subarray is rightly sorted
		else if(v[mid] <= v[end]){

			//if target lies in right half
			if(v[mid] <= target && target <= v[end])
				start = mid + 1;

			//if target lies in left half
			else
				end = mid - 1;
		}

	} 

	//if target is not present
	return -1;
}

int main(){

	int t; cin>>t;
	while(t--){
		
		int n; cin>>n; 
		vector<int> v(n);

		for(auto &x : v)
			cin>>x;

		int target; cin >> target;

		cout << search(v, target) << endl;
	
	}
	return 0;
}