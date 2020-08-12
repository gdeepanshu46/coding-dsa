#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

void pascals_triangle(int n)
{
    for(int j=0;j<=n;j++)
    {
        int m = 1;
        for(int i=0;i<=j;i++)
        {
            cout<<m<<" ";
            m = m*(j-i)/(i+1);
        }
        cout<<"\n";
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    pascals_triangle(n);
    return 0;
}


