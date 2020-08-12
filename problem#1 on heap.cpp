#include<bits/stdc++.h>
using namespace std;
int main()
 {
     int t;cin>>t;
     while(t--)
     {
        long int m,n;
        cin>>m>>n;
        vector<long int> v1(m),v2(n);
        for(auto i=0;i<m;i++)
            cin>>v1[i];
        for(auto i=0;i<n;i++)
            cin>>v2[i];
        make_heap(v2.begin(),v2.end(),greater<long int>());
        for(auto i=0;i<m;i++)
        {
            if(v1[i]>v2[0])
            {
                pop_heap(v2.begin(),v2.end(),greater<long int>());
                swap(v1[i],v2[n-1]);
                push_heap(v2.begin(),v2.end(),greater<long int>());
            }
        }
        sort(v2.begin(),v2.end());

        for(auto x:v1)
            cout<<x<<" ";
        for(auto y:v2)
            cout<<y<<" ";

        cout<<"\n";
     }

	return 0;
}
