#include <bits/stdc++.h>
using namespace std;

//Sieve can be build in Time : O(n*log(logn))
//It is nearly equal to O(n) as for n = 10^18, loglog(n) ~ 7
//This method works only for n <= 10000000 
//as only 10^6 size of the array size is possible
void sieve(vector<bool>& v){  
    int n = v.size();

    if(n < 2) return;

    for(int i=2; i<=sqrt(n-1); i++){

        if(v[i]){
            //start with i*i in place of 2*i, slight optimization
            for(int j=i*i; j<n; j += i){
                v[j] = 0;
            }
        }
    }
}

int main(){
    int t; cin>>t;

    while(t--){
        
        int n; cin>>n;

        vector<bool> v(n+1, 1);
        sieve(v);

        for(int i=2; i<n+1; i++){
            if(v[i]) cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}