#include <bits/stdc++.h>
using namespace std;

int main(){

	int n; cin>>n;

	priority_queue<int> lower_half;
	priority_queue<int, vector<int>, greater<int>> upper_half;

	vector<int> v(n);

	for(int i=0; i<n; i++)
		cin >> v[i];

	for(int i=0; i<n; i++){
		int x = v[i];

		lower_half.push(x);

		int diff = lower_half.size() - upper_half.size();
		diff = abs(diff);
		
		if(diff == 0){
			cout << (lower_half.top() + upper_half.top())/2;
		}
		else if(diff == 1){
			if(lower_half.size() > upper_half.size()){
				cout << lower_half.top() << " ";
			}
			else
				cout << upper_half.top() << " ";

		}
		else{
			if(lower_half.size() > upper_half.size()){
				auto temp = lower_half.top();
				upper_half.push(temp);
				lower_half.pop();
			}
			else{
				auto temp = upper_half.top();
				lower_half.push(temp);
				upper_half.pop();
			}

			cout << (lower_half.top() + upper_half.top())/2 << " ";

		}
	}


	return 0;
}