#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;
const ll size = 7;

int hash_function(int n)
{
    return n%size;
}
void insert_ele(vector<vector<int>> &v,int n)
{
    int ind = hash_function(n);
    v[ind].push_back(n);
}

bool search_ele(vector<vector<int>> &v,int n)
{
    int ind = hash_function(n);
    for(auto x:v[ind])
    {
        if(n==x)
            return true;
    }
    return false;
}

void remove_ele(vector<vector<int>> &v,int n)
{
    int ind = hash_function(n);
    for(auto it=v[ind].begin();it!=v[ind].end();it++)
    {
        if(*it == n)
        {
            v[ind].erase(it);
            break;
        }

    }

}

void show(vector<vector<int>> &v)
{
    for(int i=0;i<size;i++)
    {
        for(auto x : v[i])
            cout<<x<<" ";
        cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int> > hash_table(size);
    insert_ele(hash_table,0);
    insert_ele(hash_table,1);
    insert_ele(hash_table,2);
    insert_ele(hash_table,3);
    insert_ele(hash_table,4);
    insert_ele(hash_table,5);
    insert_ele(hash_table,6);
    insert_ele(hash_table,7);
    insert_ele(hash_table,8);
    insert_ele(hash_table,9);
    insert_ele(hash_table,10);
    insert_ele(hash_table,11);
    insert_ele(hash_table,12);
    insert_ele(hash_table,13);
    show(hash_table);
    cout<<search_ele(hash_table,13);
    cout<<endl;
    remove_ele(hash_table,13);
    cout<<search_ele(hash_table,13);
    //int t;cin>>t;
    /*while(t--)
    {

    }*/

    return 0;
}

