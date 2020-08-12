#include <bits/stdc++.h>
using namespace std;

class TrieNode{
public:
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data){
		this -> data = data;
		children = new TrieNode*[26];
		for(int i=0; i<26; i++)
			children[i] = NULL;
		isTerminal = false;
	}
};

class Trie{
	TrieNode *root;

public:
	Trie(){
		root = new TrieNode('\0');
	}

	void insertWord(TrieNode *root, string word){

		if(word.size() == 0){
			root -> isTerminal = true;
			return;
		}

		int index = word[0] - 'a';
		TrieNode *child;

		if(root -> children[index] != NULL){
			child = root -> children[index];
		}
		else{
			child = new TrieNode(word[0]);
			root -> children[index]  = child;
		}

		insertWord(child, word.substr(1));
	}
	void insertWord(string word){
		insertWord(root, word);
	}

	bool searchWord(TrieNode *root, string word){
		if(word.size() == 0){
			return root -> isTerminal;
		}

		int index = word[0] - 'a';
		TrieNode *child;

		if(root -> children[index] != NULL){
			child = root -> children[index];
		}
		else{
			return false;
		}

		return searchWord(child, word.substr(1));
	}

	// User function
	bool searchWord(string word){
		if(searchWord(this -> root, word))
			return true;
		else
			return false;
	}	



	void removeWord(TrieNode *root, string word){
		if(word.size() == 0){
			root -> isTerminal = false;
			return;
		}

		int index = word[0] - 'a';
		TrieNode *child; 

		if(root -> children[index] != NULL){
			child = root -> children[index];
		}
		else{
			return ;
		}

		removeWord(child, word.substr(1));

		if(child -> isTerminal == false){
			for(int i=0; i<26; i++){
				if(child -> children[i] != NULL)
					return;				
			}

			delete child;
			root -> children[index] = NULL;
		}
	}

	// User function
	void removeWord(string word){
		removeWord(this -> root, word);
	}


};



int main(){

	Trie t; 

	t.insertWord("and");

	cout << t.searchWord("and") << endl;

	t.removeWord("and");

	cout << t.searchWord("and") << endl;



	return 0;
}