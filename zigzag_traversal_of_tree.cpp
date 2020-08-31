#include <bits/stdc++.h>
using namespace std;

void zigZag(Node* root){

	if(root == NULL) return;

	queue<Node*> q;
	q.push(root);

	vector<Node*> v;
	while(!q.empty()){
		int n = q.size();
		v.clear();

		for(int i=0; i<n; i++){
			Node* temp = q.front();
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);

			v.push_back(temp);
			q.pop();
		}

		if(n%2 == 0){
			reverse(v.begin(), v.end());
			for(auto x : v)
				cout << x->data << " ";
		}
		else{
			for(auto x : v)
				cout << x->data << " ";
		}
	}
}

int main(){


	return 0;
}