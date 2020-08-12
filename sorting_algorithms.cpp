#include <bits/stdc++.h>
using namespace std;

//Time Complexity in all cases O(N*N)
void bubbleSort(int* arr, int n){
	for(int i = n-1; i>0; i--){
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
	int pivot = arr[end];
	int i = start-1;

	for(int j=start; j<end; j++){
		if(arr[j] < pivot){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[end]);
	return i+1;
}

void qSort(int* arr, int start, int end){

	if(start <= end){
		int pivot_ind = partition(arr, start, end);

		qSort(arr, start, pivot_ind-1);
		qSort(arr, pivot_ind+1, end);
	}
}

void quickSort(int* arr, int n){
	qSort(arr, 0, n-1);
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void merge(int* arr, int start, int end, int mid){
	
	vector<int> v1;
	vector<int> v2;

	for(int i=start; i<=mid; i++){
		v1.push_back(arr[i]);
	}

	for(int i=mid+1; i<=end; i++){
		v2.push_back(arr[i]);
	}

	int n1 = v1.size();
	int n2 = v2.size();

	int i=0, j=0;

	vector<int> res;

	while(i<n1 && j<n2){
		if(v1[i] < v2[j]){
			res.push_back(v1[i]);
			i++;
		}
		else{
			res.push_back(v2[j]);
			j++;
		}
	}

	while(i<n1){
		res.push_back(v1[i]);
		i++;
	}


	while(j<n2){
		res.push_back(v2[j]);
		j++;
	}

	i = start;
	for(auto x : res){
		arr[i++] = x; 
	}
}

void mSort(int* arr, int start, int end){
	if(start < end){
		int mid = start + (end - start)/2;

		mSort(arr, start, mid);
		mSort(arr, mid+1, end);
		merge(arr, start, end, mid);
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
	int lchild = 2*ind+1;
	int rchild = 2*ind+2;

	int small = ind;
	
	if(lchild < n && arr[small] > arr[lchild]){
		small = lchild;
	}

	if(rchild < n && arr[small] > arr[rchild]){
		small = rchild;
	}

	if(small != ind){
		swap(arr[ind], arr[small]);
		heapify(arr, n, small);
	}
}

void extractMin(int* arr, int &n){
	swap(arr[0], arr[n-1]);
	n--;
	heapify(arr, n, 0);
}

void buildHeap(int* temp, int n){
	for(int i= (n-2)/2; i>=0; i--){
		heapify(temp, n, i);
	}
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

	// mergeSort(arr1, 5);
	// mergeSort(arr2, 5);
	// mergeSort(arr3, 5);

	heapSort(arr1, 5);
	heapSort(arr2, 5);
	heapSort(arr3, 5);

	// selectionSort();
	// insertiionSort();
	// quickSort();
	// mergeSort();
	// heapSort();


	return 0;
}