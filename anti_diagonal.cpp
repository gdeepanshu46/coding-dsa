#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;
vector<vector<int>> diagonal(vector<vector<int> > &A) {
    vector<vector<int>> v;
    int size= A.size();
    int start_row = 0;
    for(int i=0;i<size;i++)
    {
        vector<int> temp;
        int x=i;
        int y=start_row;
        while(x>=0 && x<size && y>=0 && y<size)
        {
            temp.push_back(A[x][y]);
            x--;y++;
        }
        reverse(temp.begin(),temp.end());
        v.push_back(temp);
    }
    for(int i=1;i<size;i++)
    {
        vector<int> temp;
        int x=size-1;
        int y=i;
        while(x>=0 && x<size && y>=0 && y<size)
        {
            temp.push_back(A[x][y]);
            x--;y++;
        }
        reverse(temp.begin(),temp.end());
        v.push_back(temp);
    }
    return v;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=2;
    vector<vector<int>> v(n,vector<int> (n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>v[i][j];
    auto ans = diagonal(v);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }




    return 0;
}


