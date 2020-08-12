#include <bits/stdc++.h>
using namespace std;

Node* reverse_k(Node* head, int k){

	if(head == NULL || head->next == NULL)
		return head;

	Node* curr = head;
	Node* prev = NULL;
	Node* next = NULL;

	int count = 0;

	while(curr != NULL && count < k){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}

	if(curr != NULL){
		head->next = reverse_k(curr, k);
	}

	return prev;
}

int main(){


	return 0;
}