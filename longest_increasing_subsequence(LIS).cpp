#include<bits/stdc++.h>
using namespace std;

int lis(const vector<int> &A) {
    
    int n = A.size();
    vector<int> B(A.size(), 1);
    for(int i=0; i<n; i++){
        for(int j=i-1; j>=0; j--){
            if(A[i] > A[j]){
                B[i] = max(B[i], B[j] + 1);
            }
        }
    }
    
    int res = *max_element(B.begin(), B.end());
    return res;
}


int main()
 {
     int t;cin>>t;
     while(t--)
     {
        int n; cin>>n;
        
        vector<int> v(n);
        for(auto &x : v)
            cin>>x;
        
        cout << lis(v) << endl;
        
     }
	
	return 0;
}