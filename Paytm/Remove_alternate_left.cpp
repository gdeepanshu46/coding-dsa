#include<bits/stdc++.h>
using namespace std;

int Alter(int n)
{
    if(n<10  && n >-10)
    return n;
    
    string s1=to_string(n);
    string ans;
    for(int i=0;i<s1.size();i+=2)
    {
        ans=ans+s1[i];
    }
    n=stoi(ans);
    return n;
}

int main()
{
    int t;
    cin >>t;
    while(t--){
    int n;
    cin>>n;
    cout<< Alter(n);}
    return 0;
}