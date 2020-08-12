#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

bool cmp(string a,string b)
{
    string a_ = a+b;
    string b_ = b+a;
    int a__ = stoi(a_);
    int b__ = stoi(b_);
    if(a__>b__)
        return true;
    else
        return false;
}

string largestNumber(const vector<int> &A) {
    int n=A.size();
    vector<string> v(n);
    for(int i=0;i<n;i++)
    {
        v[i]= to_string(A[i]);
    }
    sort(v.begin(),v.end(),cmp);

    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> A{99,98,97,998,19};
    largestNumber(A);

    return 0;
}

