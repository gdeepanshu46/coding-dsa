#include <bits/stdc++.h> 
using namespace std; 

int min_ = INT_MAX;

void helper(int* arr, int n, bool* curr_ele, int no_of_ele, 
			bool* soln, int* min_diff, int sum, int curr_sum, int curr_pos) { 
	if (curr_pos == n) 
		return; 

	if ((n/2 - no_of_ele) > (n - curr_pos)) 
		return; 

	helper(arr, n, curr_ele, no_of_ele, 
			soln, min_diff, sum, curr_sum, curr_pos+1); 

	no_of_ele++; 
	curr_sum = curr_sum + arr[curr_pos]; 
	curr_ele[curr_pos] = true; 

	if (no_of_ele == n/2) 
	{ 
		if (abs(sum/2 - curr_sum) < min_) 
		{ 
			min_ = abs(sum/2 - curr_sum); 
			for (int i = 0; i<n; i++) 
				soln[i] = curr_ele[i]; 
		} 
	} 
	else
	{ 
		helper(arr, n, curr_ele, no_of_ele, soln, 
				min_diff, sum, curr_sum, curr_pos+1); 
	} 

	curr_ele[curr_pos] = false; 
} 

int min_diff_(int *arr, int n) 
{ 
	bool* curr_ele = new bool[n]; 

	bool* soln = new bool[n]; 

	int min_diff = INT_MAX; 

	int sum = 0; 
	for (int i=0; i<n; i++) 
	{ 
		sum += arr[i]; 
		curr_ele[i] = soln[i] = false; 
	} 

	helper(arr, n, curr_ele, 0, soln, &min_diff, sum, 0, 0); 
	
	 long long first = 0;
	 long long second = 0;
    for (int i=0; i<n; i++){ 
        if (soln[i] == true)
            first += arr[i];
        else
        	second += arr[i];
    } 

    return abs(first - second);
} 

int main() 
{ 
	min_ = INT_MAX;
	int n; cin>>n;

	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i]; 
	cout << min_diff_(arr, n); 

	cout << endl;

	return 0; 
} 
