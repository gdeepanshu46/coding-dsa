#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v1{10,20,30,40};
    vector<int> v2{15,25,35,45};
    vector<int> v3(8);

    list<int> l;
    stack<int> st;
    deque<int> dq;
    queue<int> q;
    set<int> s;
    unordered_set<int> us;
    map<int,int> mp;
    unordered_map<int,int> um;
    multimap<int,int> mm;
    multiset<int,int> ms;

   string str= "abc";
   while(next_permutation(str.begin(),str.end()))
   {
       for(auto x:str)
    {
            cout<<x;
    }
    cout<<endl;
   }




    return 0;
}

