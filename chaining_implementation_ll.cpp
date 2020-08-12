#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

class my_hash
{
    int size;
    list<int> *table;
    public :
    my_hash(int a)
    {
        size = a;
        table = new list<int>[size];
    }
    int hash_funtion(int n)
    {
        return n%size;
    }
    bool search(int n)
    {
        int i = hash_funtion(n);
        for(auto x: table[i])
        {
            if(n==x)
                return true;
        }
        return false;
    }
    void insert_ele(int n)
    {
        int i = hash_funtion(n);
        table[i].push_back(n);
    }
    void remove_ele(int n)
    {
        int i = hash_funtion(n);
        table[i].remove(n);
    }
    void show()
    {
        for(int i=0;i<size;i++)
        {
            for(auto x: table[i])
            {
                cout<<x<<" ";
            }
            cout<<endl;
        }

    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    my_hash hash_table(7);
    hash_table.insert_ele(0);
    hash_table.insert_ele(1);
    hash_table.insert_ele(2);
    hash_table.insert_ele(3);
    hash_table.insert_ele(4);
    hash_table.insert_ele(5);
    hash_table.insert_ele(6);
    hash_table.insert_ele(7);
    hash_table.insert_ele(8);
    hash_table.insert_ele(9);
    hash_table.insert_ele(10);
    hash_table.insert_ele(11);
    hash_table.insert_ele(12);
    hash_table.insert_ele(13);
    hash_table.show();
    cout<<hash_table.search(13);
    cout<<endl;
    hash_table.remove_ele(13);
    cout<<hash_table.search(13);
    //int t;cin>>t;
    /*while(t--)
    {

    }*/

    return 0;
}

