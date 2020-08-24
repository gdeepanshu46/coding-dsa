#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char ch;
	int val;
	Node *next, *prev;

	Node(char c, int v){
		ch = c;
		val = v; 
		next = prev = NULL;
	}
};

map<char, Node*> mp;
Node* head = NULL;
Node* tail = NULL;
int cache_size = 3;

void update(char c, int val){
	Node* temp = mp[c];
	temp->val = val;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	temp->next = head;
	temp->prev = NULL;
	head->prev = temp;
	head = temp;
	return;
}


void insert(char c, int val){
	// storing key, value pair
    //if no element is present, insert it
	if(head == NULL){
		head = new Node(c, val);
		head->next = NULL;
		head->prev = NULL;
		mp.insert({c, head});
		tail = head;
		return;
	}

	//if ele is already present, update it
	if(mp.count(c)){
		Node* temp = mp[c];
    	temp->val = val;
    	temp->prev->next = temp->next;
    	temp->next->prev = temp->prev;
    	temp->next = head;
    	temp->prev = NULL;
    	head->prev = temp;
    	head = temp;
		return;
	}

	//if cache memory is full, and ele is new, delete least required ele
	if(mp.size() == cache_size){

		char tail_c = tail->ch;
		tail = tail->prev;
		Node* temp = tail->next;
		delete temp;
		tail->next = NULL;
		mp.erase(tail_c);
	}

	//insert ele at start
	Node* newNode = new Node(c, val);
	newNode->next = head;
	newNode->prev = NULL;
	head->prev = newNode;
	head = newNode;
	mp.insert({c, newNode});
}

int get_val(char c){
	// this function should return value corresponding to key
    if(mp.count(c) == 0) return -1;

	if(head->ch == c){
		return head->val;
	}

	if(tail->ch == c){
		Node* temp = tail;
		temp->prev->next = NULL;
		tail = temp->prev;
		temp->next = head;
		temp->prev = NULL;
		head->prev = temp;
		head = temp;
		return temp->val;
	}

	Node* temp = mp[c];
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	temp->next = head;
	head->prev = temp;
	temp->prev = NULL;
	head = temp;

	return mp[c]->val;
}

void traverse(){

	Node* h = head;
	while(h != NULL){
		cout << h->ch << " " << h->val << endl;
		h = h->next;
	}
	cout << endl;
}


int main(){

	insert('a', 1);
	insert('b', 2);
	insert('c', 3);

	traverse();

	cout << get_val('c') << endl;

	traverse();

	insert('d', 4);

	traverse();


	return 0;
}