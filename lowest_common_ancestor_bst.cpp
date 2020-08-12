#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

//for BST
Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   if(root==NULL)
        return root;
    if(root->data>n1 && root->data>n2)
        return LCA(root->left,n1,n2);
    else if(root->data<n1 && root->data<n2)
        return LCA(root->right,n1,n2);
    else
    {
        return root;
    }
}
//for Binary tree **Generalized can also be used for bst**
Node* lca(Node *root, int n1, int n2)
{
   //Your code here
  if(root==NULL)
    return root;
    if(root->data == n1 || root->data == n2)
        return root;
    Node *left =  lca(root->left,n1,n2);
    Node *right =  lca(root->right,n1,n2);
    if(left !=NULL && right!=NULL)
    {
        return root;
    }
    if(left==NULL && right==NULL)
        return NULL;
    if(left!=NULL)
        return left;
    else
        return right;


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    return 0;
}



