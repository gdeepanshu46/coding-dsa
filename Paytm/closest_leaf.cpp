#include <bits/stdc++.h>
using namespace std;


  
// A utility function to find distance of closest leaf of the tree 
// rooted under given root 
int closestDown(Node *root) 
{ 
    // Base cases 
    if (root == NULL) 
        return INT_MAX; 

    if (root->left == NULL && root->right == NULL) 
        return 0; 
  
    // Return minimum of left and right, plus one 
    return 1 + min(closestDown(root->left), closestDown(root->right)); 
} 
  
// Returns distance of the cloest leaf to a given key 'k'.  The array 
// ancestors is used to keep track of ancestors of current node and 
// 'index' is used to keep track of curremt index in 'ancestors[]' 
int findClosestUtil(Node *root, char k, Node *ancestors[], 
                                               int index) 
{ 
    // Base case 
    if (root == NULL) 
        return INT_MAX; 
  
    // If key found 
    if (root->key == k) 
    { 
        //  Find the cloest leaf under the subtree rooted with given key 
        int res = closestDown(root); 
  
        // Traverse all ancestors and update result if any parent node 
        // gives smaller distance 
        for (int i = index-1; i>=0; i--) 
            res = min(res, index - i + closestDown(ancestors[i])); 
        return res; 
    } 
  
    // If key node found, store current node and recur for left and 
    // right childrens 
    ancestors[index] = root; 
    return min(findClosestUtil(root->left, k, ancestors, index+1), 
                  findClosestUtil(root->right, k, ancestors, index+1)); 
  
} 
  
// The main function that returns distance of the closest key to 'k'. It 
// mainly uses recursive function findClosestUtil() to find the closes 
// distance. 
int findClosest(Node *root, char k) 
{ 
    // Create an array to store ancestors 
    // Assumptiom: Maximum height of tree is 100 
   	Node *ancestors[100]; 
  
    return findClosestUtil(root, k, ancestors, 0); 
} 

int main(){


	return 0;
}