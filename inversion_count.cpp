#include <bits/stdc++.h>
using namespace std;

//using Enhance Merge Sort : O(nlogn)

int inversion_ = 0;
void merge(int *arr, int start, int mid, int end){

	int st = start;
	int en = end;
	int mi = mid;

	// create a temp array of size of combined both halves
	int size = end - start + 1;
	int arr1[size] = {0};


	// merge the two sorted arr in one
	int i = 0;
	while( i < size && st <= mid - 1 && mi <= end){
		if(arr[st] < arr[mi]){
			arr1[i++] = arr[st];
			st++ ;
		}
		else{
			inversion_ += (mid - st);
			arr1[i++] = arr[mi] ;
			mi++ ;
		}
	}

	while(st <= mid - 1){
		arr1[i++] = arr[st];
		st++ ;
	}

	while(mi <= end){
		arr1[i++] = arr[mi];
		mi++ ;
	}
	i = 0;
	for(int j=start; j<=end ;j++){
		arr[j] = arr1[i++];
	}
}

void merge_sort(int *arr, int start, int end){

	// arr has 1 or no elements
	if(start >= end)
		return ;

	// create a point of division in the arr
	int mid = start + (end - start)/2;

	// keep dividing arr into two halves
	merge_sort( arr, start, mid);
	merge_sort( arr, mid + 1, end);

	// merge the two halves
	merge( arr, start, mid + 1, end);
	
}



//using STL : O(n*n) in worst case
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

		//inversion_count(arr, n);
		merge_sort(arr, 0, n-1);
		cout << inversion_ << endl;
		
		//cout << count_ << endl;
	}
	
	return 0;
}
