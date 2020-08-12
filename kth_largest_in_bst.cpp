#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

void find(Node *root,int k,int &count)
{
    if(root!=NULL)
    {
        find(root->right,k,count);
        if(count+1 == k)
            cout << root->key<<"\n";
        count++;
        find(root->left,k,count);
    }
}
void kthLargest(Node *root, int k)
{
    int count=0;
    find(root,k,count);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    return 0;
}

