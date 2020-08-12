
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
int dfs(Node *root)
{
     if(root==NULL)
        return 0;
    return max(bfs(root->left),bfs(root->right))+1;
}

int bfs(Node *root)
{
     if(root==NULL)
        return 0;
    queue<Node *> q;
    int c=0;
    q.push(root);
    while(!q.empty())
    {
        int q_count = q.size();
        c++;
        for(int i=0;i<q_count;i++)
        {

            Node *curr = q.front();
            q.pop();

            if(curr->left!=NULL)
            {
                q.push(curr->left);

            }

            if(curr->right!=NULL)
            {
                q.push(curr->right);

            }
        }
    }
    return c;
}
int main()
{
    create_bt();
    cout<<dfs(root);

}



