//KMP works in O(m + n) time, it works on the fact that for any index if values in 
//two string does'nt match, then check in place of starting from the beginning, check if
//their exists a previous pattern in the string to be searched and move to that index.
//longest prefix suffix array is build on the required string for checking the pattern.

#include<bits/stdc++.h>
using namespace std;

vector<int> prefix_suffix(string s){
    int n = s.size();

    if(n == 0) return {};
    vector<int> v(n, -1);

    int i=1;
    int j=0;

    while(i<n){
    
        if(s[i] == s[j]){
            
            v[i] = j;
            i++;
            j++;
        }
        else if(j != 0){
            j = v[j-1] + 1;
        }
        else{
            v[i] = -1;
            i++;
        }
    }
    return v;
}

bool kmp(string txt, string search){

    //if both strings are empty return true;
    if(txt.empty() && search.empty()) return 1;

    //build the prefix suffix array for the seaching string
    auto v = prefix_suffix(search);

    
    int n = txt.size();
    int m = search.size();

    int i=0, j=0;

    while(i < n && j < m){
        if(txt[i] == search[j]){
            i++;
            j++;
        }
        else if(j != 0){
            j = v[j-1] + 1;
        }
        else{
            i++;
        }
    }

    if(j == m)
        return true;
    else
        return false;
}

int main(){

    string txt, search;
    cin >> txt >> search;

    cout << kmp(txt, search);
    
    return 0;
}
