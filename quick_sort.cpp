#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int start, int end){

	// consider first element as our pivot element
	int pivot = arr[start];

	// count smaller elements than pivot element
	int count_smaller = 0;
	for(int i=start + 1; i<=end; i++){
		if(pivot >= arr[i])
			count_smaller++ ;
	}

	/* finding pivot index and placing our pivot 
		ele at its correct position */

	int pivot_ind = start + count_smaller;
	swap(arr[pivot_ind], arr[start]);
	int pivot_ele = arr[pivot_ind];

	int st = start;
	int en = end;

	/* Arrange all elements smaller than pivot to 
		left of it and greater to right of it */

	while( st != pivot_ind && en != pivot_ind){
		if(arr[st] <= pivot_ele){
			st++ ;
		}
		else if(arr[en] > pivot_ele){
			en-- ;
		}
		else{
			swap(arr[st] , arr[en]);
			st++ ;
			en-- ;
		}
	}
	// finally return pivot index
	return pivot_ind;
}

void quick_sort(int *arr, int start, int end){

	if(start >= end)
		return;

	/* placing the first element at its correct position 
	  and return its position */
	int pivot = partition(arr, start, end);

	/* now do the same thing for left and right halves */
	quick_sort(arr, start, pivot - 1);
	quick_sort(arr, pivot + 1, end);
}

int main(){
	
	int n; cin>>n;
	int arr[n] ;
	for(int i=0; i<n; i++)
		cin >> arr[i];

	quick_sort(arr, 0, n-1);

	for(int i=0; i<n; i++)
		cout << arr[i] <<" ";

	return 0;
}