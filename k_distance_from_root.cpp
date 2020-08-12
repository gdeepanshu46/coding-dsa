
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

void dfs(Node *root,int k)
{
    if(root==NULL)
        return;
    if(k==0)
        cout<<root->data<<" ";
    dfs(root->left,k-1);
    dfs(root->right,k-1);
}

int bfs(Node *root,int k)
{
    if(root==NULL)
        return 0;
    queue<Node *> q;
    vector<Node *> v;
    q.push(root);
    int res = 0;
    while(!q.empty())
    {
        res++;
        int q_count = q.size();

       for(int i=0;i<q_count;i++)
       {
            Node *curr = q.front();
            q.pop();

            if(curr->left!=NULL)
            {
                if(res==k)
                    v.push_back(curr->left);
                q.push(curr->left);
            }

            if(curr->right!=NULL)
            {
                if(res==k)
                    v.push_back(curr->right);
                q.push(curr->right);
            }

       }
       if(res==k)
       {
           for(auto x:v)
            cout<<x->data<<" ";
       }

    }
    return res;
}
int main()
{
    create_bt();
    cout<<bfs(root,2);

}




