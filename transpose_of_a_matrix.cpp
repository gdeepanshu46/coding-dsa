#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;cin>>n>>m;
    vector<vector<int>> v(n,vector<int> (m,0)),v1(m,vector<int> (n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            v1[i][j]= v[j][i];
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<v1[i][j]<<" ";
        }
        cout<<"\n";
    }



	return 0;
}
