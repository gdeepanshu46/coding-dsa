#include<bits/stdc++.h>
using namespace std;
#define ll long long
int modular_expo(ll a,ll n,ll mod=64735492)
{
    if(n==0)
        return 1;
    if(n%2==0)
        return modular_expo((a%mod)*(a%mod)%mod,n/2,mod);
    else
        return (a*modular_expo((a%mod)*(a%mod)%mod,(n-1)/2,mod))%mod;

}
int main()
{
    cout<<modular_expo(71045970,41535484);
    return 0;
}
