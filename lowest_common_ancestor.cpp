#include <bits/stdc++.h>
using namespace std;


//Naive approach 
bool left_lca(Node* root, vector<Node*> &v, int a){
	if(root == NULL){
		return false;
	}

	v.push_back(root->data);

	if(root->data == a){
		return true;
	}

	v.erase(v.size()-1);
	return false;
}

Node* lca(Node* root, int a, int b){
	vector<Node*> v1;
	vector<Node*> v2;

	bool left = left_lca(root, v1, a);
	bool right = right_lca(root, v2, b);

	if(left == false || right == false)
		return NULL;

	for(int i=0; i<v1.size() && i<v2.size(); i++){
		if(v1[i+1] != v2[i+1]){
			return v1[i];
		}
	}
}


//Efficient approach
Node* lca(Node* root, int a, int b){
	if(!root)
		return NULL;

	if(root->data == a || root->data == b)
		return root;

	Node* left = lca(root->left, a, b);
	Node* right = lca(root->right, a, b);

	if(left != NULL && right != NULL)
		return root;

	if(left != NULL)
		return left;

	if(right != NULL)
		return right;

	return NULL;
}

int count = 0;

int distance_(Node* root, int a){
	if(root == NULL)
		return 0; 

	count++;

	if(root->data == a)
		return 1;

	if(distance_(root->left, a) || distance_(root->right, b)){
		return 1;
	}

	count--;
	return 0;
}

int min_distance(Node* root, int a, int b){
	Node* lca = lca(root, a, b);

	int left = distance_(lca, a);
	int right = distance_(lca, b);

	return left + right - 2;
}



int main(){

	cout << lca(root, a, b);


	return 0;
}