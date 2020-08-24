	#include <bits/stdc++.h>
using namespace std;

int largest_rectangle(vector<int> arr){

	int n = arr.size();
	int max_ = INT_MIN;
	stack<int> height, pos;

	height.push(arr[0]);
	pos.push(0);

	for(int i=1; i<n; i++){
		if(arr[i] == height.top()){
			continue;
		}
		else if(arr[i] > height.top()){
			height.push(arr[i]);
			pos.push(i);
		}
		else{
			int ps = i;
			while(!height.empty() && height.top() > arr[i] ){
				int temp = height.top() * (i - pos.top());
				max_ = max(max_, temp);
				ps = pos.top();

				height.pop();
				pos.pop();
			}
			height.push(arr[i]);
			pos.push(ps);
		}
	}

	while(!height.empty()){
		int temp = height.top() * (n - pos.top());
		max_ = max(max_, temp);

		height.pop();
		pos.pop();
	}

	return max_;
}

int main(){

	int t; cin>>t;

	while(t--){
		int n; cin>>n;
		vector<int> v(n);
		for(auto &x : v){
			cin>>x;
		}
		cout << largest_rectangle(v) << endl;
	}

	return 0;
}	