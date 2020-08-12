#include <bits/stdc++.h>
using namespace std;

//recursive
Node* reverse_(Node* head){

	if(head == NULL || head->next == NULL){
		return head;
	}

	int res = reverse_(head->next);

	head->next->next = head;
	head->next = NULL;

	return res;
}


//iterative 
Node* reverse(Node* head){

	Node* curr = head;
	Node* prev = NULL;
	
	while(curr != NULL){
		Node* nextNode = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nextNode;
	}
	//prev is the new root 
	return prev;
}


int main(){


	return 0;
}