#include <bits/stdc++.h>
using namespace std;

int largest_rectangle_in_histogram(vector<int> arr){

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

int largest_rectangle(vector<vector<int>> v){

	int n = v.size();
	if(n == 0)
		return 0;
	int m = v[0].size();

	int max_ = -1;

	vector<int> temp(m, 0);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(v[i][j] == 0){
				temp[j] = 0;
			}
			else{
				temp[j] += v[i][j];
			}
		}

		int res = largest_rectangle_in_histogram(temp);

		max_ = max(max_ , res);
	}
	return max_;
}

int main(){

	int t; cin>>t;

	while(t--){
		int n , m; cin>>n>>m;
		vector<vector<int>> v(n, vector<int>(m, 0));

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin>>v[i][j];
			}
		}

		cout << largest_rectangle(v)<< endl;
	}
	return 0;
}

