#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;
const ll m = 7;

class hashing
{
    int *hash_table;
    int size_v;

public:
    hashing(int n)
    {
        size_v = n;
        hash_table = new int[size_v];
        for(int i=0;i<n;i++)
            hash_table[i]=-1;
    }
    int hash_function(int key)
    {
        return key%m;
    }

    bool search_ele(int key)
    {
        int ind = hash_function(key);
        int j = ind+1;
        if(hash_table[ind]==key)
            return true;
        while(j!=ind)
        {
            if(hash_table[j]==key)
                return true;
            else if(hash_table[j]==-1)
                return false;

            j++;
        }
    }

    void insert_ele(int key)
    {
        int ind = hash_function(key);
        if(hash_table[ind]==-1 || hash_table[ind]==-2)
        {
            hash_table[ind]=key;
            return;
        }
        int j=ind+1;
        while(j!=ind)
        {
            if(hash_table[j]==-1 || hash_table[j]==-2)
            {
                hash_table[j] = key;
                return ;
            }

            j++;
        }

    }
    void delete_ele(int key)
    {
        int ind = hash_function(key);
        if(hash_table[ind]==key)
        {
            hash_table[ind]=-2;
            return;
        }
        int j=ind+1;
        while(j!=ind)
        {
            if(hash_table[j]==key)
            {
                hash_table[ind]=-2;
                return;
            }
            else if(hash_table[j]==-1 || hash_table[j]==-2)
            {
                return;
            }
            j++;
        }
    }
    void show()
    {
        for(int i=0;i<size_v;i++)
            cout<<hash_table[i]<<" ";
        cout<<endl;
    }
//
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    hashing h_table(7);
    h_table.insert_ele(50);
    h_table.insert_ele(51);
    h_table.insert_ele(49);
    h_table.insert_ele(16);
    h_table.insert_ele(56);
    h_table.insert_ele(15);
    h_table.insert_ele(19);

    h_table.show();


    return 0;
}
