#include<bits/stdc++.h>
using namespace std;
#define ll long long
int modular_expo(ll a,ll n,ll mod=1e9+7)
{
   ll res=1;
   while(n>0)
   {
       if(n%2==1)
            res = (res%mod)*(a%mod)%mod;
       a = ((a%mod)*(a%mod)%mod)%mod;
       n /= 2;
   }
   return res;
}
int main()
{
    cout<<modular_expo(1000000000,1000000000);
    return 0;
}
