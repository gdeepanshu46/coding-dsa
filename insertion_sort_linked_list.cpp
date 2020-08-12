#include <bits/stdc++.h>
using namespace std;

Node* insertion_sort(Node* head){

	if(head == NULL || head->next == NULL)
		return head;

	Node* nHead = new Node(head->data);
	nHead->next = NULL;

	Node* prev = NULL;

	Node* curr = head;
	curr = curr->next;

	while(curr != NULL){

		Node* temp = nHead;
		while(temp != NULL){
			if(curr->data < temp->data){
				if(temp == nHead){
					Node* temp = new Node(curr->data);
					temp->next = nHead;
					nHead = temp;
				}
				else{
					Node* temp = new Node(temp->data);
					temp->next = prev->next;
					prev->next = temp;
				}
			}
			else{
				prev = temp;
				temp = temp->next;
			}

		}

		
		curr = curr->next;
	} 


}

int main(){


	return 0;
}