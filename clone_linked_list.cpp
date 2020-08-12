#include <bits/stdc++.h>
using namespace std;


Node* copyList(Node* head){

	if(head == NULL || head->next == NULL)
		return head;

	Node* curr = head;

	while(curr != NULL){

		Node* next_ = curr->next;
		curr->next = new Node(curr->val);

		curr->next->next = next_;

		curr = next_;
	}

	curr = head;

	while(curr != NULL){
	    if(curr->random != NULL)
		    curr->next->random = curr->random->next;

		curr = curr->next->next;
	}
	
	curr = head;

	Node* nHead = head->next;
	curr = nHead;
	Node* prev = head;

	while(curr != NULL){
		if(curr->next == NULL){
			prev->next = NULL;
			break;
		}

		Node* next_ = curr->next->next;
		prev->next = curr->next;
		prev = prev->next;
		curr->next = next_;
		curr = next_;
		
	}

	return nHead;
}

int main(){


	return 0;
}