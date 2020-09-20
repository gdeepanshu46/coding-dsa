#include <bits/stdc++.h>
using namespace std;

int nextGreaterElement(int n) {
        
        string s = to_string(n);
        for(int i=s.size()-1; i>0; i--){

        	//if a small element is found, traversing from right -> left
			if(s[i-1] < s[i]){

				//sort elements right to it
				sort(s.begin() + i, s.end());

				//find the right position of our found element and place it there
				for(int j = i; j < s.size(); j++){
					if(s[i-1] < s[j]){
						swap(s[i-1], s[j]);
						break;
					}
				}

				break;
			}
		}

		long long ans = stoll(s);
        
        //for corner case 19999999999, res would be 9199999999, won't fit in int type
        if(ans > INT_MAX) return -1;
        
        //if no greater number can be found
        if(ans == n) return -1;

		return ans;        
    }

int main(){

	int n; cin>>n;

	cout << nextGreaterElement(n) << endl;

	return 0;
}