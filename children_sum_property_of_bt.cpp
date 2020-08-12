
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node* root = NULL;

void create_bt()
{
    Node* p,*q;
    queue<Node*> que;
    int x;
    cout<<"Enter value of root ";
    cin>>x;
    root = new Node();
    root->data = x;
    root->left = NULL;
    root->right = NULL;
    que.push(root);
    while(!que.empty())
    {
        p = que.front();
        que.pop();
        cout<<"Enter left child of "<<p->data<<" ";
        cin>>x;
        if(x!=-1)
        {
            q = new Node();
            q->data = x;
            q->left = NULL;
            q->right = NULL;
            que.push(q);
            p->left = q;
        }
        cout<<"Enter right child of "<<p->data<<" ";
        cin>>x;
        if(x!=-1)
        {
            q = new Node();
            q->data = x;
            q->left = NULL;
            q->right = NULL;
            que.push(q);
            p->right = q;
        }
    }

}

bool bfs(Node *root)
{
     if((root->left==NULL) &&(root->right==NULL))
        return true;
    if((bfs(root->left) && bfs(root->right)) && ((root->left->data + root->right->data)== root->data))
        return true;
    else
        return false;

}
int main()
{
    create_bt();
    cout<<bfs(root);

}




