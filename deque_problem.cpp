#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        int n,k;cin>>n>>k;
        vector<int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        deque<int> dq;
        int first = v[0];
        for(int i=0;i<k;i++)
        {
            first = max(v[i],first);
        }
        dq.push_back(first);
        cout<<dq.front()<<" ";
        for(int i=k;i<v.size();i++)
        {
            if(dq.size()==k)
                dq.pop_front();
            while(!dq.empty())
            {
                if(v[i]<dq.back())
                {
                    break;
                }
                else
                {
                    dq.pop_back();
                }
            }

            dq.push_back(v[i]);
            cout<<dq.front()<<" ";
        }
        cout<<endl;
    }


    return 0;
}


