#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

int prodOfDivisors_(int n)
{
    int temp =n ;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            temp= (temp*n)%mod;
        }
    }
    return temp;
}

vector<int> prodOfDivisors(vector<int> v)
{
    for(int i=0;i<v.size();i++)
    {
        v[i]= prodOfDivisors_(v[i]);
    }
    return v;
}
vector<vector<int>> subarrays(vector<int> v)
{
    vector<vector<int>> final;
    vector<int> temp;
    int n=v.size();
    int c=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int ind = j;
            if(i<=n-j)
            {
                for(int k=0;k<i;k++)
                {
                    temp.push_back(v[ind++]);
                }
                final.push_back(temp);
                temp.clear();

            }
        }
    }
    return final;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v{1,2,3,4,5};
    vector<vector<int>> final;
    vector<int> temp;
    final= subarrays(v);
    int maxi;

    for(int i=0;i<final.size();i++)
    {
        maxi = INT_MIN;
        for(int j=0;j<final[i].size();j++)
            maxi = max(maxi,final[i][j]);
        temp.push_back(maxi);
    }
    for(auto x:temp)
        cout<<x<<" ";
    cout<<endl;
    vector<int> v_temp ;
    v_temp = prodOfDivisors(temp);
    sort(v_temp.begin(),v_temp.end(),greater<int>());
    for(auto x:v_temp)
        cout<<x<<" ";




    return 0;
}


