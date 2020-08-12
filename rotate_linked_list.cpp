#include <bits/stdc++.h>
using namespace std;

Node* rotate(Node* head, int k){

	Node* curr = head;

	for(int i=1; i<k; i++){
		curr = curr->next;
	}

	Node* nHead = curr->next;

	Node* temp = curr->next;

	curr->next = NULL;

	while(temp->next != NULL){
		temp = temp->next;
	}

	temp->next = head;

	return nHead;
}


int main(){


	return 0;
}
