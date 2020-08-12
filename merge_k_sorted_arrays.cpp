
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

//code not complete only logic written

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v(k),v2(k*k);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    fill(v.begin(),v.end(),0);
    int *a = new int[k*k];
    for(int i=0;i<k;i++)
    {
        pq.push({arr[i][0],i});
    }
    while(!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        if(v[temp.second]<k-1)
        {
            v[temp.second]++;
            pq.push({arr[temp.second][v[temp.second]],temp.second});
        }
        v2.push_back(temp.first);

    }
    return 0;
}

