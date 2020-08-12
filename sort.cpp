#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int *arr, int n){
  for(int i=n-2; i>=0; i--){
    for(int j=0; j<=i; j++){
      if(arr[j] > arr[j+1])
        swap(arr[j], arr[j+1]);
    }
  }
}

void selection_sort(int *arr, int n){
  
}

int main(){


  int arr[] = {5, 4, 2, 1, 3, 5, 1, 6, 6, 100};

  bubble_sort(arr, 10);

  for(int i=0; i<10; i++)
    cout << arr[i] << " ";

  return 0;
}