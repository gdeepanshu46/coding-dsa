#include <bits/stdc++.h>
using namespace std;


//Efficient Approach

void inOrder(Node* root, string &str){

    if(root == NULL){
        str.push_back('$');
        return ;
    }

    inOrder(root->left, str);
    str += to_string(root->data);
    inOrder(root->right, str);
}


void preOrder(Node* root, string &str){

    if(root == NULL){
        str.push_back('$');
        return ;
    }

    str += to_string(root->data);
    inOrder(root->left, str);
    inOrder(root->right, str);
}


bool isSubTree_E(Node* T, Node* S){
    if(T == NULL && S == NULL)
        return true;
    if(S == NULL)
        return false;

    string inT, inS;
    inOrder(T, inT);
    inOrder(S, inS);

    string preT, preS;
    preOrder(T, preT);
    preOrder(S, preS);

    if((inT.find(inS) != string::npos) && (preT.find(preS) != string::npos))
        return true;
    else
        return false;
}

bool isSubTreeE(Node* T, Node* S){
    if(isSubTree_E(T, S))
        return true;
    else
        return false;
}


//My approach
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