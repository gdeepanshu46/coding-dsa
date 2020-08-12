#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;cin>>s;
    int h=0;
    for(int i=0;i<s.size();i++)
    {
        int one = 1;
        one = one<<(s[i]-97);
        if((one & h)>0)
        {
            cout<<s[i]<<" ";
        }
        else
        {
            h = h | one;
        }
    }




    return 0;
}
