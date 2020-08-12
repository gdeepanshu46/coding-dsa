#include <bits/stdc++.h>
using namespace std;


Node* reverse(Node* head){
	if(head == NULL || head->next == NULL)
		return head;

	Node* res = reverse(head->next);

	head->next->next = head;
	head->next = NULL;

	return res;
}

//O(N) solution
//find mid of list using hare and tortoise
//we have two lists now
//reverse second list
//merge them alternatively
void reorder(Node* head){

	if(head == NULL || head->next == NULL)
		return;

	Node* slow = head;
	Node* fast = head->next;

	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next;
	}
	Node* nHead = slow->next;

	nHead = reverse(nHead);

	Node* p1 = head;
	Node* p2 = nHead;

	while(p1 != NULL && p2 != NULL){
		Node* temp = p1->next;
		p1->next = p2;
		p2 = temp;
		p1 = p1->next;
	}
}


//O(N*N) solution
Node* find_last(Node* head){

	while(head->next->next != NULL){
		head = head->next;
	}

	Node* last = head->next;
	head->next = NULL;

	return last;
}

Node* reorder(Node* head){

	if(head == NULL || head->next == NULL)
		return head;

	Node* curr = head;

	while(curr != NULL && curr->next != NULL){
		Node* last = find_last(curr);

		Node* next = curr->next;
		curr->next = last;
		last->next = temp;

		curr = curr->next->next;
	}

	return res;
}

int main(){


	return 0;
}
