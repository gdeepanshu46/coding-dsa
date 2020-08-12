#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

vector<int> nextPermutation(vector<int> &A) {
    int n=A.size();
    int f=0;
    stack<pair<int,int>> st;
    st.push({A[n-1],n-1});
    int index;
    for(int i=n-2;i>=0;i--)
    {
        if(A[i]<st.top().first)
        {
            f=1;
            while( !st.empty() && A[i]<st.top().first)
            {
                auto temp = st.top();
                st.pop();
                index = temp.second;
            }
            swap(A[i],A[index]);
            sort(A.begin()+i+1,A.end());
        }
        else
        {
            st.push({A[i],i});
        }


    }
    if(f==0)
    {
        sort(A.begin(),A.end());
        return A;
    }
    return A;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v{5,10,7,3,1};
    vector<int> temp = nextPermutation(v);
    for(auto x:temp)
        cout<<x<<" ";


    return 0;
}


