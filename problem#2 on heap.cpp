#include<bits/stdc++.h>
using namespace std;
int main()
 {
     int t;cin>>t;
     while(t--)
     {
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        priority_queue<int,vector<int>,greater<int>()> pq;
        for(int i=0;i<=k;i++)
            pq.push(v[i]);
        int ind=0;
        for(int i=k+1;i<n;i++)
        {
            v[ind]=pq.pop();
            ind++;
            pq.push(v[i]);
        }
        while(!pq.empty())
        {
            v[ind]=pq.pop();
            ind++;
        }
        for(int i=0;i<n;i++)
            cout<<v[i]<<" ";
        cout<<"\n";
     }

	return 0;
}
