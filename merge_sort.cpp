#include <bits/stdc++.h>
using namespace std;

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

int main(){
	
	int n; cin>>n;
	int arr[n] ;
	for(int i=0; i<n; i++)
		cin >> arr[i];

	merge_sort(arr, 0, n-1);

	for(int i=0; i<n; i++)
		cout << arr[i] <<" ";

	return 0;
}