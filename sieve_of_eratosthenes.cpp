#include<bits/stdc++.h>
using namespace std;

void sieve_of_eratosthenes(int n)
{
    int primes[n+1];
    for(int i=0;i<=n;i++)
        primes[i]=1;
    primes[0]=0;
    primes[1]=0;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(primes[i])
        {
            for(int j=2;j*i<=n;j++)
            {
                primes[i*j]=0;
            }
        }
    }
    for(int i=0;i<=n;i++)
        if(primes[i])
            cout<<i<<" ";
    cout<<endl;
}
int main()
{
    int n;cin>>n;
    sieve_of_eratosthenes(n);
    return 0;
}
