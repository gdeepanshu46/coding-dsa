#include <bits/stdc++.h>
using namespace std;

//Time Complexity in all cases O(N*N)
void bubbleSort(int* arr, int n){

	for(int i=n-1; i>=1; i--){
		for(int j=0; j<i; j++){
			if(arr[j] > arr[j+1])
				swap(arr[j], arr[j+1]);
		}
	}
	

	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;

}

//Time Complexity in all cases O(N*N)
void selectionSort(int* arr, int n){

	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(arr[i] > arr[j])
				swap(arr[i], arr[j]);
		}
	}
	
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;

}


//Time Complexity 
//worst case O(N*N)
//best case O(N) : already sorted array
void insertionSort(int* arr, int n){

	for(int i=1; i<n; i++){
		if(arr[i] < arr[i-1]){
			swap(arr[i], arr[i-1]);
			for(int j=i-1; j>0; j--){
				if(arr[j] < arr[j-1])
					swap(arr[j], arr[j-1]);
			}
		}
	}
	

	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

//Worst case : O(N*N) Array is already sorted
//Average or Best case : O(NlogN)

int partition(int* arr, int start, int end){
	
	int c = 0;
	int last_ele = arr[end];
	
	int i = start - 1; 
	int j = start;

	while(j < end){
		if(arr[j] < last_ele){
			i++;
			swap(arr[j], arr[i]);
		}
		j++;
	}

	swap(arr[end], arr[i+1]);

	return i+1;
}

void qSort(int* arr, int start, int end){

	if(start <= end){
		int p_ind = partition(arr, start, end);
		qSort(arr, start, p_ind - 1);
		qSort(arr, p_ind + 1, end);		
	}
}

void quickSort(int* arr, int n){
	qSort(arr, 0, n-1);
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void merge(int* arr, int start, int mid, int end){

	int resultant[end - start + 1];

	int index = 0;

	int i = start;
	int j = mid + 1;

	while(i <= mid  && j <= end){
		if(arr[i] < arr[j]){
			resultant[index++] = arr[i++];
		}
		else
			resultant[index++] = arr[j++];
	}

	while(i <= mid){
		resultant[index++] = arr[i++];
	}
	

	while(j <= end){
		resultant[index++] = arr[j++];
	}

	index = 0;;

	for(int i=start; i<=end; i++){
		arr[i] = resultant[index++];
	}
}

void mSort(int* arr, int start, int end){
	if(start < end){
		int mid = start + (end - start)/2;
		mSort(arr, start, mid);
		mSort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}	
}

//O(N*N) in best, worst and best cases
void mergeSort(int* arr, int n){
	mSort(arr, 0, n-1);

	for(int i=0; i<n; i++)
		cout << arr[i] << " " ;
	cout << endl;
}

void heapify(int* arr, int n, int ind){
	
}

void extractMin(int* arr, int &n){
	
}

void buildHeap(int* temp, int n){
	
}


//best, average, worst O(NlogN)
void heapSort(int* arr, int n){

	//create temp array same as arr
	int temp[n];
	for(int i=0; i<n; i++)
		temp[i] = arr[i];

	int size = n;

	//build heap using temp array
	buildHeap(temp, n);

	for(int i=0; i<size; i++){
		arr[i] = temp[0];
		extractMin(temp, n);
	}

	for(int i=0; i<size; i++){
		cout << arr[i] << " " ;
	}
	cout << endl;
}




int main(){

	int arr1[5] = {5, 4, 3, 2 ,1};
	int arr2[5] = {11, 12, 13, 14, 15};
	int arr3[5] = {24, 21, 25, 22, 23};

	// bubbleSort(arr1, 5);
	// bubbleSort(arr2, 5);
	// bubbleSort(arr3, 5);

	// selectionSort(arr1, 5);
	// selectionSort(arr2, 5);
	// selectionSort(arr3, 5);

	// insertionSort(arr1, 5);
	// insertionSort(arr2, 5);
	// insertionSort(arr3, 5);


	// quickSort(arr1, 5);
	// quickSort(arr2, 5);
	// quickSort(arr3, 5);

	mergeSort(arr1, 5);
	mergeSort(arr2, 5);
	mergeSort(arr3, 5);

	// heapSort(arr1, 5);
	// heapSort(arr2, 5);
	// heapSort(arr3, 5);

	// selectionSort();
	// insertiionSort();
	// quickSort();
	// mergeSort();
	// heapSort();


	return 0;
}