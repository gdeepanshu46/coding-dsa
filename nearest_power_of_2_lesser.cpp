#include <bits/stdc++.h>
using namespace std;

int nearest_power(int n){

	int count = 0;
	while(n != 0){
		count++;
		n /= 2;
	}

	return pow(2, count-1);
}

int main(){

	int n; cin>>n;
	
	vector<int> v(n);

	for(auto &x : v)
		cin >> x;

	int max_ = INT_MIN;

	int sum = 0;
	for(auto x : v){

		x += sum;
		int temp = nearest_power(x);
		max_ = max(max_, temp);

		sum = x - temp;
	}
	cout << max_ << endl;

	return 0;
}