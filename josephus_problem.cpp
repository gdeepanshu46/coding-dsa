#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

void dg(){  
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
int main()
{
    //dg();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
        list<int> l;
        for(int i=1;i<=n;i++)
            l.push_back(i);


        auto it = l.begin();
        while(l.size()>0)
        {
            if(l.size()==1)
            {
                cout<<l.front()<<endl;
                break;
            }
            for(int i=0;i<k-1;i++)
            {
                it++;
                if(it==l.end())
                    it=l.begin();
            }
            it = l.erase(it);
            if(it==l.end())
                it=l.begin();


        }

    return 0;
}

