#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
	TrieNode* child[26];
	bool isTerminal;

	TrieNode(){
		for(int i=0; i<26; i++){
			child[i] = NULL;
		}
		isTerminal = false;
	}
};

bool search_(TrieNode* root, string key){
	TrieNode* curr = root;
	
	for(int i=0; i<key.size(); i++){
		if(curr->child[key[i] - 'a'] == NULL){
			return false;
		}
		else{
			curr = curr->child[key[i] - 'a'];
		}
	}
	return curr->isTerminal;
}

void insert_(TrieNode* root, string key){
	TrieNode* curr = root;

	for(int i=0; i<key.size(); i++){
		if(curr->child[key[i] - 'a'] == NULL){
			curr->child[key[i] - 'a'] = new TrieNode();
		}
		
		curr = curr->child[key[i] - 'a'];
	}
	curr->isTerminal = true;
}


int main(){

	TrieNode* root = new TrieNode();

	insert_(root, "hello");
	insert_(root, "nyc");
	cout << search_(root, "helo") << endl;
	cout << search_(root, "ny");
	return 0;
}