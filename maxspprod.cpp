#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

int maxSpecialProduct(vector<int> &A) {
    int n = A.size();
    vector<int> left(n);
    vector<int> right(n);
    stack<pair<int,int>> st;
    st.push({A[0],0});
    left[0]=0;

    for(int i=1;i<n;i++)
    {
        while(!st.empty())
        {
            if(A[i]<st.top().first)
            {
                left[i]=st.top().second;
                st.push({A[i],i});
                break;
            }
            else
            {
                st.pop();
                if(st.empty())
                {
                    left[i]=0;
                    st.push({A[i],i});
                    break;
                }
            }
        }
    }
    while(!st.empty())
        st.pop();
    st.push({A[n-1],n-1});
    right[n-1]=0;
    for(int i=n-2;i>=0;i--)
    {
        while(!st.empty())
        {
            if(A[i]<st.top().first)
            {
                right[i]=st.top().second;
                st.push({A[i],i});
                break;
            }
            else
            {
                st.pop();
                if(st.empty())
                {
                    right[i]=0;
                    st.push({A[i],i});
                    break;
                }
            }
        }
    }

    long long int maxi = 0;
    long long int temp;
    for(int i=0;i<n;i++)
    {
        temp = (left[i]*right[i]);
        maxi = max(maxi,temp);
    }

    return maxi%1000000007;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v{2,1,3,5,4};
    cout<<maxSpecialProduct(v);


    return 0;
}

