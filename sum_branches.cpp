#include <bits/stdc++.h>
using namespace std;

void sumBranches(node* root, int sum = 0){
	if(root == NULL)
		return;

	if(root->left == NULL && root->right == NULL){
		cout << sum + root->data << " ";
		return;
	}

	sumBranches(root->left, sum + root->data);
	sumBranches(root->right, sum + root->data);
}


int main(){


	return 0;
}