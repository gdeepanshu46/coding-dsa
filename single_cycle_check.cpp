#include <bits/stdc++.h>
using namespace std;

bool single_cycle_check(int* arr, int n){
	int visited[n] = {0};

	visited[0] = 1;
	int first_ele = arr[0];

	int count = 1;
	int curr_ind = (arr[0])%n;
	if(curr_ind < 0)
		curr_ind += n;

	while(count < n){
		if(visited[curr_ind] == 1){
			return false;
		}
		visited[curr_ind] = 1;
		curr_ind = (curr_ind + arr[curr_ind])%n;
		if(curr_ind < 0)
			curr_ind += n;

		count++;

		//cout << curr_ind << " " << count << endl;
	}

	if(curr_ind == 0)
		return true;
	return false;
}

int main(){

	int n; cin>>n; 
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];

	cout << single_cycle_check(arr, n);

	return 0;
}
