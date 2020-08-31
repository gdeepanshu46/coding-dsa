#include <bits/stdc++.h>
using namespace std;


//left view of tree using recursion (more efficient)
int max_ = INT_MIN;

void leftView_(Node* root, int level){
	if(root == NULL) return;

	if(level > max_){
		max_ = level;
		cout << root->data << " ";
	}

	leftView_(root->left, level + 1);
	leftView_(root->right, level + 1);
}

void leftView(Node* root){
    leftView_(root, 0);
    max_ = INT_MIN;
}


//left view using level order traversal
void left_view_(Node* root){
	if(!root) return;

	queue<Node*> q;
	q.push(root);

	while(!q.empty()){

		cout << q.front()->data << " ";
		int n = q.size();
		for(int i=0; i<n; i++){
			
			Node* temp = q.front();
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);

			q.pop();
		}
	}
}

//Right View of Tree using recursion
int max_ = INT_MIN;

void rightView_(Node* root, int level){
	if(root == NULL) return;

	if(level > max_){
		max_ = level;
		cout << root->data << " ";
	}

	rightView_(root->right, level + 1);
	rightView_(root->left, level + 1);
}

void rightView(Node* root){
    rightView_(root, 0);
    max_ = INT_MIN;
}

//using Level Order Traversal
void right_view_(Node* root){
	if(!root) return;

	queue<Node*> q;
	q.push(root);

	while(!q.empty()){

		int n = q.size();
		cout << q.back()->data << " ";
		
		for(int i=0; i<n; i++){
			
			Node* temp = q.front();
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);

			q.pop();
		}	
	}
}

int main(){


	return 0;
}