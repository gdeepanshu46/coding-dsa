#include <bits/stdc++.h>
using namespace std;

Node* nextGreaterDelete(Node* head){

	if(head == NULL || head->next == NULL)
		return head;

	if(head->data < head->next->data){
		head = head->next;
		head->next = nextGreaterDelete(head->next);
		return head;
	}

	head->next = nextGreaterDelete(head->next);
	return head;
}

int main(){


	return 0;
}