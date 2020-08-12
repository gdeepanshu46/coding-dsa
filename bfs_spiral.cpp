
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

void bfs(Node *root)
{
     if(root==NULL)
        return;
    queue<Node *> q;
    vector<Node *>v;
    int f=0;
    q.push(root);
    cout<<root->data<<" ";
    while(!q.empty())
    {
        int q_count = q.size();
        for(int i=0;i<q_count;i++)
        {
            Node *curr = q.front();
            q.pop();
            //cout<<curr->data<<" ";

            if(curr->left!=NULL)
            {
                q.push(curr->left);
                v.push_back(curr->left);
            }

            if(curr->right!=NULL)
            {
                q.push(curr->right);
                v.push_back(curr->right);
            }
        }
        if(f==0)
        {
            reverse(v.begin(),v.end());
            for(auto x: v)
                cout<<x->data<<" ";
            f=1;
            v.clear();

        }
        else
        {
            for(auto x: v)
                cout<<x->data<<" ";
            v.clear();
            f=0;
        }



    }
}
int main()
{
    create_bt();
    bfs(root);

}


