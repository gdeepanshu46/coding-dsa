#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e7+9;
long long fact(int n)
{
    if(n==1 || n==0)
        return 1;
    return n*fact(n-1);
}
long long rank_of_string(string s)
{
    int f=0;
    unordered_map<char,int> has;
    for(int i=0;i<s.size();i++)
    {
        if(has[s[i]]>0)
        {
            f=1;
            break;
        }
        else
            has[s[i]]++;
    }

    if(f==1)
        return 0;
    for(int i=1;i<256;i++)
        has[i] = has[i-1] + has[i];


    long long sum = 1;
    int n = s.size()-1;
    for(int i=0;i<s.size()-1;i++)
    {
        sum = (sum%mod + has[s[i]-1]*fact(n)%mod)%mod;
        sum = sum%mod;
        for(int j=s[i];j<256;j++)
            has[j]--;
        n--;
    }
    return sum;
}

int main()
 {
     string s;cin>>s;
     cout<<rank_of_string(s);

	return 0;
}
