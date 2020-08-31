#include<bits/stdc++.h>
using namespace std;

//Time : O(n^2) | Space : O(1) | Expanding around the center
//For each and every index, consider it as the centre of palin.. and find the
//count of palin.. that can be formed. Do it for odd length as well as even length too.
string lps(string s){
    //max len of a palin..
    int maxi = 1;

    //longest palin..
    string longest = "";
    longest.push_back(s[0]);
    
    //check for each index of string considering it as centre
    for(int i=0; i<s.size(); i++){
        int count = 1;
        int l = i-1;
        int r = i+1;
        string temp(1, s[i]);

        //for odd length
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
        
        //for even length
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
    return longest;
}

//Time : O(n^2) | Space : O(n^2) | DP solution
string lps_(string s){
    int n = s.size();
    if(n == 0) return "";
    
    vector<vector<int>> dp(n, vector<int> (n, 0));
    int max_len = 1;
    int left = 0;
    int right = 0;
    
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int k = j-i;
            
            if(k == j) dp[k][j] = 1;
            else if(s[k] != s[j]) dp[k][j] = 0;
            else if(k == j-1) dp[k][j] = 1;
            else dp[k][j] = dp[k+1][j-1];
            
            if(dp[k][j]){
                if(j-k + 1 > max_len){
                    max_len = j-k + 1;
                    left = k;
                    right = j;
                }
            }
        }
    }
    return s.substr(left, right-left + 1);
}

int main()
 {
     int t;cin>>t;
     while(t--){
        string s; cin>>s;
        cout << lps(s) << endl;
        cout << lps_(s) << endl;
     }
	return 0;
}