#include <bits/stdc++.h>
using namespace std;

ListNode* reverse(ListNode* head){
	if(head == NULL || head->next == NULL)
		return head;

	ListNode* nHead = reverse(head->next);

	head->next->next = head;
	head->next = NULL;

	return nHead;
}

ListNode* addLargeNumbers(ListNode* first, ListNode* second){

	if(first == NULL)
		return second;
	if(second == NULL)
		return first;

	first = reverse(first);
	second = reverse(second);


	ListNode* f = first;
	ListNode* s = second;

	ListNode* nHead = NULL;
	ListNode* prev = NULL;

	int carry = 0;

	while(f != NULL && s != NULL){

		int sum = f->data + s->data + carry;

		carry = (sum >= 10)? 1:0;
		sum = sum%10;

		ListNode* newNode = new Node(sum);
		newNode->next = NULL;
		if(f == first){
			nHead = newNode;
		}
		else
			prev->next = newNode;

		prev = newNode; 

		f = f->next;
		s = s->next; 
	}

	while(f != NULL){
		int sum = f->data + carry;

		carry = (sum >= 10)? 1:0;
		sum = sum%10;

		ListNode* newNode = new Node(sum);
		newNode->next = NULL;

		if(f == first){
			nHead = newNode;
		}
		else
			prev->next = newNode;

		prev = newNode; 

		f = f->next;
	}

	while(s != NULL){
		int sum = s->data + carry;

		carry = (sum >= 10)? 1:0;
		sum = sum%10;

		ListNode* newNode = new Node(sum);
		newNode->next = NULL;

		if(s == second){
			nHead = newNode;
		}
		else
			prev->next = newNode;

		prev = newNode; 

		s = s->next;
	}

	if(carry > 0){
		ListNode* newNode = new Node(carry);
		newNode->next = NULL;

		prev->next = newNode;
		prev = newNode;
	}

	nHead = reverse(nHead);

	return nHead;
}

int main(){


	return 0;
}