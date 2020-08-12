#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(Node** mhead, Node* head){
	if(head == NULL){
		return 1;
	}

	bool res = isPalindrome(mhead, head->next);

	if(res == false){
		return false;
	}

	*left = (*left)->next;

	return ((*left)->data == head->data);


	return res && (head->data == temp->data);
}

int main(){


	return 0;
}