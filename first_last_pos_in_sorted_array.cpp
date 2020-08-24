#include <bits/stdc++.h>
using namespace std;

int first_occurence(vector<int> v, int val){
	int n = v.size();

	int start = 0;
	int end = n-1;

	int res = -1;

	while(start <= end){
		int mid = start + (end - start)/2;

		if(v[mid] == val){
			res = mid;
			end = mid - 1;
		}
		else if(v[mid] > val){
			end = mid-1;
		}
		else{
			start = mid + 1;
		}
	}

	return res;
}

int last_occurence(vector<int> v, int val){
	int n = v.size();

	int start = 0;
	int end = n-1;

	int res = -1;

	while(start <= end){
		int mid = start + (end - start)/2;

		if(v[mid] == val){
			res = mid;
			start = mid + 1;
		}
		else if(v[mid] > val){
			end = mid-1;
		}
		else{
			start = mid + 1;
		}
	}

	return res;
}

int main(){

	vector<int> v = {2, 3, 6, 7, 7, 8, 8, 8, 12};

	auto l = lower_bound(v.begin(), v.end(), 8);
	auto u = upper_bound(v.begin(), v.end(), 8);
	u--;
	cout << l - v.begin() << " " << u - v.begin();

	cout << endl;

	cout << first_occurence(v, 8) << " " << last_occurence(v, 8);
	return 0;
}