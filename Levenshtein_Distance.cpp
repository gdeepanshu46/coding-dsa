#include<bits/stdc++.h>
using namespace std;
int main()
 {
     int t;cin>>t;
     while(t--)
     {
        int l1, l2; cin>>l1>>l2;
        string s1, s2; cin>>s1>>s2;
        
        int edit[l1+1][l2+1] = {0};
        
        for(int i=0; i<=l1; i++){
            for(int j=0; j<=l2; j++){
                if(i == 0){
                    edit[i][j] = j;
                    continue;
                }
                if(j == 0){
                    edit[i][j] = i;
                    continue;
                }
                
                if(s1[i-1] == s2[j-1]){
                    edit[i][j] = edit[i-1][j-1];
                }
                else
                    edit[i][j] = 1 + min(edit[i-1][j-1], min(edit[i-1][j], edit[i][j-1]));
            }
        }
        
        cout << edit[l1][l2] << "\n";
     }  
	return 0;
}