#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* lchild;
    node* rchild;
};
node* root = NULL;

void create_bt()
{
    node* p,*q;
    queue<node*> que;
    int x;
    cout<<"Enter value of root ";
    cin>>x;
    root = new node();
    root->data = x;
    root->lchild = NULL;
    root->rchild = NULL;
    que.push(root);
    while(!que.empty())
    {
        p = que.front();
        que.pop();
        cout<<"Enter left child of "<<p->data<<" ";
        cin>>x;
        if(x!=-1)
        {
            q = new node();
            q->data = x;
            q->lchild = NULL;
            q->rchild = NULL;
            que.push(q);
            p->lchild = q;
        }
        cout<<"Enter right child of "<<p->data<<" ";
        cin>>x;
        if(x!=-1)
        {
            q = new node();
            q->data = x;
            q->lchild = NULL;
            q->rchild = NULL;
            que.push(q);
            p->rchild = q;
        }
    }

}
void inorder(node* root)
{
    if(root)
    {
        cout<<root->data<<" ";
        inorder(root->lchild);
        inorder(root->rchild);
    }
}
int main()
{
    create_bt();
    inorder(root);

}
