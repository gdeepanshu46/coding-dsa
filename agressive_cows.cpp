#include <bits/stdc++.h>
using namespace std;

bool isPossible(int* arr, int n, int mid, int c){
	int count = 1;
	int last = arr[0];

	for(int i=1; i<n; i++){
		if(arr[i]-last >= mid){
			count++;
			last = arr[i];
		}
	}
	if(count >= c){
		return true;
	}
	else
		return false;
}

int agressive_cows(int* arr, int n, int c){
	int low = 0; 
	int high = arr[n-1] - arr[0];
	int ans;

	while(low <= high){

		int mid = low + (high - low)/2;
		
		if(isPossible(arr, n, mid, c)){
			low = mid + 1;
			ans = mid;
		}	
		else{
			high = mid - 1;
		}
	}

	return ans;
}

int main(){

	int t; cin>>t; 

	while(t--){
		int n; cin>>n;
		int c; cin>>c;

		int arr[n];
		for(int i=0; i<n; i++)
			cin>>arr[i];

		sort(arr, arr+n);

		cout << agressive_cows(arr, n, c) << endl;

	}
	


	return 0;
}
