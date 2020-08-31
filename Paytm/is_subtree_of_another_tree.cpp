#include <bits/stdc++.h>
using namespace std;

string inT, preT;
string inS, preS;

void inOrderT(Node* T){
	if(!T)
		return;

	inOrderT(T->left);
	inT.push(T->data);
	inOrderT(T->right);
}

void inOrderS(Node* S){
	if(!S)
		return;

	inOrderS(S->left);
	inS.push(S->data);
	inOrderS(S->right);
}

void preOrderT(Node* T){
	if(!T)
		return;

	preT.push(T->data);
	preOrderT(T->left);
	preOrderT(T->right);
}

void preOrderS(Node* S){
	if(!S)
		return;

	preS.push(S->data);
	preOrderS(S->left);
	preOrderS(S->right);
}

void isSubTree(Node* T, Node* S){

	inT.clear();
	inS.clear();
	preT.clear();
	preS.clear();

	inOrderT(T);
	inOrderS(S);

	preOrderT(T);
	preOrderS(S);

	if(inT.find(inS) != string::npos && preT.find(preT) != string::npos){
		return true;
	}
	else
		return false;

}




//Storing all nodes that can be root of both the trees i.e. val of both are same
vector<Node*> v;

//checking if two trees are identical
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


//Building vector of possible nodes in the main tree
void find(Node* T, Node* S){
    if(T == NULL || S == NULL)
        return;
    if(T->data == S->data){
        v.push_back(T);
    }
    find(T->left, S);
    find(T->right, S);
    
}

//checking for all nodes in vector, if any one of them is a subtree
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


	cout << isSubTree(T, S);


	return 0;
}