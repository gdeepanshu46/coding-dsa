
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

int maxi(Node *root)
{
    if(root==NULL)
        return 0;
    return max(max(maxi(root->left),maxi(root->right)),root->data);
}
int mini(Node *root)
{
    if(root==NULL)
        return 0;
    return min(min(maxi(root->left),maxi(root->right)),root->data);
}

void bfs(Node *root)
{
     if(root==NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        cout<<curr->data<<" ";

        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
    }
}
int main()
{
    create_bt();
    cout<<maxi(root);
}


