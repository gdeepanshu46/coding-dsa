#include<bits/stdc++.h>
using namespace std;
int main()
 {
     int t;cin>>t;
     while(t--)
     {
        string s; cin>>s;
        int maxi = 1;
        string longest = "";
        longest.push_back(s[0]);
        
        for(int i=0; i<s.size(); i++){
            int count = 1;
            int l = i-1;
            int r = i+1;
            string temp(1, s[i]);
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                temp.push_back(s[r]);
                string t(1, s[l]);
                temp.insert(0, t);
                count += 2;
                l--;
                r++;
                
                if(count > maxi){
                    
                    maxi = count;
                    longest = temp;
                }
            }
            
            count = 0;
            l = i-1;
            r = i;
            
            string temp2 = "";
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                
                temp2.push_back(s[r]);
                string t2(1, s[l]);
                temp2.insert(0, t2);
                count += 2;
                l--;
                r++;
                if(count > maxi){
                    maxi = count;
                    longest = temp2;
                }
            }
            
            
        }
        
        cout << longest << "\n";
     }
	
	return 0;
}