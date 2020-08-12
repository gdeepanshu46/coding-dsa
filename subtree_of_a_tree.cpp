#include <bits/stdc++.h>
using namespace std;

vector<Node*> v;

bool isSubTree_(Node* T, Node* S) {
    // Your code here
    // return 1 if S is subtree of T else 0
    
    if(T == NULL && S == NULL){
        return true;
    }
    
    if(T == NULL && S != NULL)
        return false;
        
    if(T != NULL && S == NULL)
        return false;
    
    
    
    return (T->data == S->data) && isSubTree_(T->left, S->left) && isSubTree_(T->right, S->right);
}



void find(Node* T, Node* S){
    if(T == NULL || S == NULL)
        return;
    if(T->data == S->data){
        v.push_back(T);
    }
    find(T->left, S);
    find(T->right, S);
    
}

bool isSubTree(Node* T, Node* S){
    
    
    find(T, S);
    for(auto x: v){
        bool ans = isSubTree_(x, S);
        if(ans)
            return true;
    }
    v.clear();
   return false;
}

int main(){


	return 0;
}