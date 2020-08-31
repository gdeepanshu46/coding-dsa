#include <bits/stdc++.h>
using namespace std;

//Time : O(n) | Space : O(n)
int sum_of_sequence(int n){

	if(n < 2) return 1;

	vector<int> v(n+1);

	v[1] = 1;
	v[2] = 4;

	for(int i=3; i<=n; i++){
		v[i] = (i*(i+1))/2 + v[i-1];
	}
	return v[n];
}

//Direct Formula | O(1) both
int sum_of_sequence_(int n){

	if(n == 1) return 1;
	if(n == 2) return 5;

	int first = 1;
	int second = 5;

	int ans;
	for(int i=3; i<=n; i++){
		int temp = (i * (i + 1) * (2 * i + 4))/12;

		ans = temp + second;

		first = second;
		second = ans;
	}
	return ans;
}

int sum_of_sequence__(int n){

	return (n * (n + 1) * (n + 2) * (n + 3))/24;
}

int main(){

	int n; cin>>n; 

	cout << sum_of_sequence__(n);
	return 0;
}