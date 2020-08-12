#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr1[5] = {2,1,3,5,4};
    char arr2[5] = {'A','B','C','D','E'};
    vector<pair<int,char>> v;
    for(int i=0;i<5;i++)
    {
        v.push_back(make_pair(arr1[i],arr2[i]));
    }
    sort(v.begin(),v.end());
    for(auto x:v)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }



    return 0;
}

