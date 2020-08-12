#include<bits/stdc++.h>
using namespace std;
#define ll long long


int modular_multi_inverse(int a,int mod)
{
    for(int i=1;i<mod;i++)
    {
        if(((i*a)%mod)==1)
            return i;
    }
    return -1;
}
int main()
{
    cout<<modular_multi_inverse(197,3000);
    return 0;
}

