#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<vector<int>> v(n,vector<int> (n));
    for(auto i=0;i<n;i++)
        for(auto j=0;j<n;j++)
            cin>>v[i][j];
    for(auto i=0;i<n;i++)
    {
        if(i%2==0)
        {
            for(auto j=0;j<n;j++)
                cout<<v[i][j]<<" ";
        }
        else
        {
            for(auto j=n-1;j>=0;j--)
                cout<<v[i][j]<<" ";
        }
    }

	return 0;
}
