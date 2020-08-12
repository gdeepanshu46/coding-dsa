#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;

struct Node
{
    int data;
    Node *left,*right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
void traversal(Node *root)
{

    if(root==NULL)
        return ;

    cout<<root->data<<" ";
    traversal(root->left);
    traversal(root->right);

}
int height(Node *root)
{
    if(root==NULL)
        return 0;
    return max(height(root->left),height(root->right))+1;
}
bool childrenSumProperty(Node *root)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return true;
    int sum =0;
    if(root->left!=NULL)
        sum+=root->left->data;
    if(root->right!=NULL)
        sum+=root->right->data;
    return (sum==root->data && childrenSumProperty(root->left) && childrenSumProperty(root->right));
}
//O(N*N) Solution
int isTreeBalanced__(Node *root)
{
    if(root==NULL)
        return 1;
    int left = height(root->left);
    int right = height(root->right);
    return (abs(left-right)<2) && isTreeBalanced__(root->left) && isTreeBalanced__(root->right);
}
//O(N) Solution
bool isTreeBalanced_(Node *root,int &height)
{
    if(root==NULL)
    {
        height = 0;
        return true;
    }
    int lh = 0;
    int rh = 0;
    bool lb = isTreeBalanced_(root->left,lh);
    bool rb = isTreeBalanced_(root->right,rh);
    if(abs(lh-rh)>1)
        return false;
    height = max(lh,rh)+1;
    return lb&&rb;
}

bool isTreeBalanced(Node *root)
{
    int height = 0;
    return isTreeBalanced_(root,height);
}

void max_sum_leaf_to_root_(Node *root,int &max_val,int sum)
{
    if(root==NULL)
        return ;
    sum += root->data;
    if(root->left==NULL && root->right==NULL)
    {
        max_val = max(max_val,sum);
        sum=0;
    }
    max_sum_leaf_to_root_(root->left,max_val,sum);
    max_sum_leaf_to_root_(root->right,max_val,sum);

}
int max_sum_leaf_to_root(Node* root)
{
    int max_val = 0;
    max_sum_leaf_to_root_(root,max_val,0);
    return max_val;
}
//any node to any node
void max_path_sum_(Node* root,int &sum,int &max_sum)
{
    if(root==NULL)
        return;

    max_path_sum_(root->left,sum,max_sum);
    sum+= root->data;
    max_sum = max(max_sum,sum);
    max_path_sum_(root->right,sum,max_sum);
}
int max_path_sum(Node* root)
{
    if(root==NULL)
        return 0;
    int max_sum=0;
    int sum =0;
    max_path_sum_(root,sum,max_sum);
}
bool root_to_left_sum(Node * root,int sum)
{
    if(root==NULL)
        return false;
    if(root->left==NULL && root->right==NULL && root->data == sum)
    {
        cout<<root->data<<" ";
        return true;
    }
    bool left = root_to_left_sum(root->left,sum-root->data);
    bool right = root_to_left_sum(root->right,sum-root->data);
}

//Diameter of a BT
int diameter_(Node * node, int &max_val)
{
    if(node==NULL)
        return 0;
    int left = diameter_(node->left,max_val);
    int right = diameter_(node->right,max_val);
    max_val = max(max_val,left+right+1);
    return max(left,right)+1;

}
int diameter(Node* node)
{
   // Your code here
   if(node==NULL)
        return 0;
    int max_val = 0;
    int temp =  diameter_(node,max_val);
    return max_val;
}

//Maximum Path sum
int maxPathSum_(Node * node, int &max_val)
{
    if(node==NULL)
        return 0;
    int left = maxPathSum_(node->left,max_val);
    int right = maxPathSum_(node->right,max_val);
    int temp = max(max(node->data,node->data+left),node->data+right);
    max_val = max(max(max_val,temp),left+right+node->data);
    return temp;

}

int maxPathSum(struct Node *node)
{
     if(node==NULL)
        return 0;
    int max_val = 0;
    int temp =  maxPathSum_(node,max_val);
    return max_val;
}

void sumBranches(Node* root, int sum = 0){
    if(root == NULL)
        return;

    if(root->left == NULL && root->right == NULL){
        cout << sum + root->data << " ";
        return;
    }

    sumBranches(root->left, sum + root->data);
    sumBranches(root->right, sum + root->data);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    //cout<<isTreeBalanced(root);
    
    sumBranches(root, 0);


    return 0;
}


