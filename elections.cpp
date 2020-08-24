#include <bits/stdc++.h>
using namespace std;

int main(){

	int n; cin>>n; 

	string str; cin>>str;


	vector<int> a(n), b(n);

	int a_ = INT_MAX, b_ = INT_MAX;

	for(int i=0; i<n; i++){
		if(str[i] == 'A'){
			b_ = INT_MAX;
		}
		else if(str[i] == 'B'){
			b_ = i;
		}
		else{
			if(b_ == INT_MAX){
				b[i] = INT_MAX;
			}
			else{
				b[i] = abs(i - b_);
			}
		}
	}

	for(int i=n-1; i>=0; i--){
		if(str[i] == 'B'){
			a_ = INT_MAX;
		}
		else if(str[i] == 'A'){
			a_ = i;
		}
		else{
			if(a_ == INT_MAX){
				a[i] = INT_MAX;
			}
			else{
				a[i] = abs(i - a_);
			}
		}
	}

	for(int i=0; i<n; i++){
		if(str[i] == '-'){
			if(a[i] == b[i])
				continue;

			else if(a[i] < b[i]){
				str[i] = 'A';
			}
			else
				str[i] = 'B';
		}
	}

	int count_a = 0;
	int count_b = 0;
	for(auto x : str){
		if(x == 'A')
			count_a++;
		else if(x == 'B')
			count_b++;
	}

	if(count_a == count_b){
		cout << "Coalition government";
	}
	else if(count_a < count_b)
		cout << "B";
	else
		cout << "A";

	return 0;
}