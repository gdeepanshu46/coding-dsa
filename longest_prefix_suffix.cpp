#include <bits/stdc++.h>
using namespace std;

//Building longest Prefix Suffix Array of Substring
vector<int> longest_prefix_suffix(string s){

	int n = s.size();

	vector<int> v(n, -1);

	int i = 1;
	int j = 0;

	while(i < n){
		if(s[i] == s[j]){
			
			v[i] = j;
			i++;
			j++;
		}
		else if(j > 0){
			j = v[j-1] + 1;
		}
		else{
			i++;
		}
	}

	return v;
}

//Knuth-Moris-Pratt String Matching Algorithm
//Returning the first index where the pattern starts matching
int kmp(string s, string substr){

	int n = s.size();
	int size = substr.size();
	if(n == 0) return -1;
	if(size == 0) return -1;

	vector<int> v = longest_prefix_suffix(substr);

	int i=0; 
	int j=0;

	while(i < n){

		if(s[i] == substr[j]){

			if(j == size - 1){
				i = i - (size - 1);
				return i;	
			} 
			i++;
			j++;
		}
		else if(j > 0){
			j = v[j-1] + 1;
		}
		else{
			i++;
		}

	}
	return -1;
}

int main(){

	int t; cin>>t;

	while(t--){
		string s; cin>>s;
		string substr; cin>>substr;
		cout << kmp(s, substr) << endl;	
	}

	
	return 0;
}
