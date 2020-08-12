#include <bits/stdc++.h>
using namespace std;

Node* merge(Node* A, Node* B){

	if(A == NULL)
		return B;
	if(B == NULL)
		return A;

	Node* p1;
	Node* p2;

	if(A->data < B->data){
		p1 = A;
		p2 = B;
	}
	else{
		p1 = B;
		p2 = A;
	}

	Node* nHead = p1;

	while(p1 != NULL && p1->next != NULL){
		if(p1->next->data < p2->data){

			p1 = p1->next;

		}
		else{
			Node* temp = p1->next;
			p1->next = p2;
			p1 = p2;
			p2 = temp;
		}
	}

	p1->next = p2; 

	return nHead; 
}

//Recursive
Node* merge(Node* head1, Node* head2)
{
	if(head1 == NULL)
		return head2;
	if(head2 == NULL)
		return head1;

	if(head1->data < head2->data) {
		head1->next = SortedMerge(head1->next,head2);
		return head1;
	} 
	else{
		head2->next = SortedMerge(head1,head2->next);
		return head2;
	}
}

int main(){


	return 0;
}
