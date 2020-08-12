
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "(()()())";
    stack<char> st;
    st.push(s[0]);
    for(int i=1;i<s.size();i++)
    {
        if(st.empty())
            st.push(s[i]);
        else
        {
            if(s[i]!=st.top())
                st.pop();
            else
                st.push(s[i]);

        }


    }
    if(st.empty())
        cout<<"Bal";
    else
        cout<<"Not Bal";



    return 0;
}

