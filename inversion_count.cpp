#include <bits/stdc++.h>
using namespace std;

int count_ = 0;

void insert_(vector<int> &v, int num){
	int low = 0;
	int high = v.size()-1;

	while(low <= high){
		int mid = low + (high - low)/2;

		int mid_ele = v[mid];

		if(num < mid_ele){
			high = mid - 1;
		}
		else
			low = mid + 1;
	}

	v.insert(v.begin() + low, num);
	count_ += low;
}

void inversion_count(int* arr, int n){

	vector<int> v;
	for(int i=n-1; i>=0; i--){
		insert_(v, arr[i]);
	}
}

int main(){

	int t; cin>>t;

	while(t--){
		count_ = 0;
		int n; cin>>n;
		int arr[n];

		for(int i=0; i<n; i++)
			cin>>arr[i];

		inversion_count(arr, n);
		
		cout << count_ << endl;
	}
	
	return 0;
}
