#include <bits/stdc++.h>
using namespace std;

//print unique elements
Node* removeDuplicates(Node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}

	Node* res = removeDuplicates(head->next);

	if(res->data == head->data){
		head->next = head->next->next;
	}

	return head;
}

//remove all duplicates
Node* removeDuplicatesAll(Node* head){
	if(head == NULL || head->next == NULL)
		return head;

	if(head->data != head->next->data){
		head->next = removeDuplicatesAll(head->next);
		return head;
	}

	Node* tracker = head;

	while(tracker != NULL && (tracker->data == head->data)){
		tracker = tracker->next; 
	}

	return removeDuplicatesAll(tracker);
}


int main(){


	return 0;
}