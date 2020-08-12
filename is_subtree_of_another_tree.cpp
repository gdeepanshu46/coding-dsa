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

int main(){


	cout << isSubTree(T, S);


	return 0;
}