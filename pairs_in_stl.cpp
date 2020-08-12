#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pair<int,int> p1,p2;
    p1 = {10,20};
    p2 = {10,21};

    //cout<<p1.first<<" "<<p1.second;
    cout<<(p1==p2)<<endl;
    cout<<(p1!=p2)<<endl;
    cout<<(p1<p2)<<endl;
    cout<<(p1>p2)<<endl;

    return 0;
}


