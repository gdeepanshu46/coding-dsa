#include <bits/stdc++.h>

using namespace std;
vector<int> e[100000];
int n;
void dfs(bool b[],int u)
{
    b[u]=true;
    for(int i=0;i<e[u].size();i++)
    {
        int v=e[u][i];
        if(b[v]==false)
           dfs(b,v);
    }
}
int main()
{
   cin>>n;

   for(int i=0;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        e[a].push_back(b);
    }
   bool b[n];
   vector<int> res;
   for(int i=0;i<n;i++)
   {
        memset(b,false,sizeof(b));
        dfs(b,i);
        int f=0;
        for(int j=0;j<n;j++)
        {
            if(b[j]==false)
              f=1;
        }
        if(f==0)
            res.push_back(i);
   }
   if(res.size()==0)
      cout<<"-1\n";
   else
      {
          for(int i=0;i<res.size();i++)
            cout<<res[i]<<" ";
          cout<<"\n";
      }
   return 0;
}