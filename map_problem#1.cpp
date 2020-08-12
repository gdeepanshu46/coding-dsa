#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> v1(n),v2(m),v3,v4;
    stack<int> st;
    map<int,int> mp;
    for(int i =0;i<n;i++)
        cin>>v1[i];
    int count=1,temp;
    for(int i=0;i<m;i++)
    {
        cin>>v2[i];
        mp[v2[i]]=count;
        count++;
    }

    for(int i=0;i<n;i++)
    {
        if(mp.count(v1[i])==1)
        {
            if(st.empty())
            {
                st.push(v1[i]);
            }
            else
            {
                temp = st.top();
                if(mp[temp]<=mp[v1[i]])
                {
                    st.push(v1[i]);
                }
                else
                {
                    st.pop();
                    st.push(v1[i]);
                    st.push(temp);
                }

            }

        }
        else
        {
            v3.push_back(v1[i]);
        }
    }

    while(!st.empty())
    {
        v4.push_back(st.top());
        st.pop();
    }
    reverse(v4.begin(),v4.end());
    sort(v3.begin(),v3.end());
    for(auto x:v4)
        cout<<x<<" ";
    for(auto x:v3)
        cout<<x<<" ";

    return 0;
}


