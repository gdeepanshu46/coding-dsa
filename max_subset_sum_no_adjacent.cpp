#include<bits/stdc++.h>
using namespace std;
int main()
 {
     int t;cin>>t;
     while(t--)
     {
        int n; cin>>n; 
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        if(n==1){
            cout << arr[0] << endl;
            continue;
        }
        
        if(n==2){
            cout << max(arr[0], arr[1]) << endl;
            continue;
        }
            
        int a_i_2 = arr[0];
        int a_i_1 = max(arr[0], arr[1]);
        int maxi = 0;
        
        for(int i=2; i<n; i++){
            maxi = max(a_i_1, a_i_2 + arr[i]);
            a_i_2 = a_i_1;
            a_i_1 = maxi;
        }
        
        cout << maxi << endl;
     }
	
	return 0;
}