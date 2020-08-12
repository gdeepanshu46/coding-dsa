#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

class Node
{
    public:
    int data;
    int lCount;
    Node *left,*right;
    public:
    Node(int ele)
    {
        data = ele;
        left = NULL;
        right = NULL;
        lCount = 0;
    }

};

bool search_(Node *root,int key)
{
    if(root==NULL)
        return true;
    if (root->data==key)
        return true;
    else if(root->data>key)
        return search_(root->left,key);
    else if(root->data<key)
        return search_(root->right,key);
}

Node *insert_(Node *root,int key)
{
    if(root==NULL)
        return new Node(key);
    if(root->data>key)
        root->left = insert_(root->left,key);

    else if(root->data<key)
        root->right = insert_(root->right,key);
    return root;
}

void traverse_(Node *root)
{
    if(root==NULL)
        return ;
    traverse_(root->left);
    cout<<root->data<<" ";
    traverse_(root->right);
}

int floor(Node *root,int key)
{
    if(root==NULL)
        return INT_MAX;
    if(root->data==key)
        return key;
    else if(root->data>key)
        return floor(root->left,key);
    else
    {
        int floorValue = floor(root->right,key);
        return (floorValue<=key)? floorValue: root->data;
    }
}

Node* successor(Node* root){
    if(!root)
        return NULL;

    root = root->right;

    while(root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

Node* delete_(Node* root, int key){
    if(!root){
        return NULL;
    }

    if(key > root->data)
        root->right = delete_(root->right, key);
    
    else if(key < root->data)
        root->left = delete_(root->left, key);

    else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node* suc = successor(root);
            root->data = suc->data;
            root->right = delete_(root->right, suc->data);
        }

        
    }
    return root;
}

int ceil(Node *root,int key)
{
    if(root==NULL)
        return -1;
    if(root->data==key)
        return key;
    else if(root->data<key)
        return ceil(root->right,key);
    else
    {
        int ceilValue = ceil(root->left,key);
        return (ceilValue>=key)? ceilValue: root->data;
    }
}

void greaterValues(Node *root,int &temp)
{
    if(root==NULL)
        return ;

    greaterValues(root->left,temp);
    int t = temp;
    temp+=root->data;
    root->data+= t;
    greaterValues(root->right,temp);
}

void verticalOrderSum_(Node *root,int h_dist,multimap<int,int> &mm)
{
    if(root==NULL)
        return;

    verticalOrderSum_(root->left,h_dist-1,mm);
    mm.insert({h_dist,root->data});
    verticalOrderSum_(root->right,h_dist+1,mm);
}
// root: root node of the tree
void verticalOrderSum(Node *root)
{
    //Your code here
    multimap<int,int> mm;
    verticalOrderSum_(root,0,mm);
    for(auto x:mm)
        cout<<x.second<<" ";
}
//Both topView & BottomView requires level order traversal as elements chosen should be either on top or bottom
//only difference btw the two is in topView we enter a val at an index
//only once while in case of bottomView we keep updating this index value
void topView(Node *root)
{
    map<int,int> m;
    if(root==NULL)
        return;
    queue<pair<Node *,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        pair<Node *,int> p = q.front();
        Node * ptr = p.first;
        int hd = p.second;
        q.pop();

        m.insert({hd,ptr->data});
        if(ptr->left!=NULL)
            q.push({ptr->left,hd-1});
        if(ptr->right!=NULL)
            q.push({ptr->right,hd+1});
    }
    for(auto x:m)
       cout<<x.first<<" "<<x.second<<endl;

}
void bottomView(Node *root)
{
    map<int,int> m;
    if(root==NULL)
        return;
    queue<pair<Node *,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        pair<Node *,int> p = q.front();
        Node * ptr = p.first;
        int hd = p.second;
        q.pop();

        m[hd]=ptr->data;
        if(ptr->left!=NULL)
            q.push({ptr->left,hd-1});
        if(ptr->right!=NULL)
            q.push({ptr->right,hd+1});
    }
    for(auto x:m)
       cout<<x.second<<" ";

}
void rightView(Node *root)
{
   // Your Code here
    queue<Node *> q;
    q.push(root);
    while(!q.empty())
    {
        int count = q.size();
        for(int i=0;i<count;i++)
        {
            Node* temp = q.front();
            q.pop();
            if(i==(count-1))
            {
                cout<<temp->data<<" ";
            }
            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
        }

    }
}

void verticalOrderTraversal(Node *root)
{
    map<int,vector<int>> m;
    if(root==NULL)
        return;
    queue<pair<Node *,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        pair<Node *,int> p = q.front();
        Node * ptr = p.first;
        int hd = p.second;
        q.pop();

        m[hd].push_back(ptr->data);
        if(ptr->left!=NULL)
            q.push({ptr->left,hd-1});
        if(ptr->right!=NULL)
            q.push({ptr->right,hd+1});
    }
    for(auto x:m)
    {
        for(int i=0;i<x.second.size();i++)
        {
            cout<<x.second[i]<<" ";
        }
    }
}

void closest(Node* root, int val, int& mini){
    if(root == NULL)
        return;

    if(val == root->data){
        mini = 0;
        return;
    }
    else if(val > root->data){
        mini =  min(mini, abs(root->data - val));
        closest(root->right, val, mini);
    }
    else{
        mini =  min(mini, abs(root->data - val));
        closest(root->left, val, mini);
    }
}

int closest_val(Node* root, int val){
    int mini = INT_MAX;
    closest(root, val, mini);
    return mini;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *root = new Node(50);
    root = insert_(root,40);
    root = insert_(root,30);
    root = insert_(root,60);
    root = insert_(root,70);
    root = insert_(root,45);
    root = insert_(root,55);
    traverse_(root);
    cout << endl;
    root = delete_(root, 50);
    traverse_(root);
    cout << endl;

    cout << closest_val(root, 100);


    return 0;
}

