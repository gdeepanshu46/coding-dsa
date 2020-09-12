#include <bits/stdc++.h>
using namespace std;

#define row 3
#define col 3

//Remember int arr[row][col] <=> int (*arr)[col] <=> pointer-to-array
void build_1(int arr[row][col], int r, int c){
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}

//flattening 2d-array as 1d-array
void build_2(int* arr, int r, int c){
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++)
			cout << arr[i*c + j] << " ";
		cout << endl;
	}
}

//Dynamically alloted 2d array
void build_3(int** arr, int r, int c){
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}



int main(){

	//1st way : define max row and col size globally, Fixed sized array declaration
	//take your respective row and col. 
	int arr1[row][col];

	int r = 3;
	int c = 3;

	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++)
			cin>>arr1[i][j];
	}
	build_1(arr1, r, c);


	//2nd way : Flattening 2d array to 1d array, variable sized array

	int arr2[r][c];

	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++)
			cin>>arr2[i][j];
	}

	build_2(&arr2[0][0], r, c);

	//3rd way : Dynamically alloted array | Don't forget to delete the array as well 

	int** arr3 = new int*[r];
	for(int i=0; i<r; i++){
		arr3[i] = new int[c];
	}

	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++)
			cin>>arr3[i][j];
	}

	build_3(arr3, r, c);




	
	return 0;
}
