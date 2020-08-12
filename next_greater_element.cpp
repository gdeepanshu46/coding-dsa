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
        long int n;cin>>n;
        vector<long int> v(n),v1;
        for(long int i=0;i<n;i++)
            cin>>v[i];
        stack<long int> st;
        st.push(v[n-1]);
        v1.push_back(-1);
        for(long int i=n-2;i>=0;i--)
        {
            while(!st.empty())
            {
                if(v[i]<st.top())
                {
                   v1.push_back(st.top());
                    st.push(v[i]);
                    break;
                }
                else
                {
                    st.pop();
                }
            }
            if(st.empty())
            {
                v1.push_back(-1);
                st.push(v[i]);
            }
        }
        for(auto it = v1.rbegin();it!=v1.rend();it++)
            cout<<*it<<" ";
        cout<<endl;

    }



    return 0;
}


