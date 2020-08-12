#include <bits/stdc++.h>
using namespace std;
#define MAX 100

struct trie{
	trie* child[256];
	bool isTerminal;

	trie(){
		for(int i=0; i<256; i++){
			child[i] = NULL;
		}
		isTerminal = false;
	}
};

bool search(trie* root, string word){
	for(int i=0; i<word.size(); i++){
		if(root->child[word[i]] == NULL){
			return false;
		}

		root = root->child[word[i]];
	}
	return root->isTerminal;
}

void insert(trie* root, string word){
	for(int i=0; i<word.size(); i++){
		if(root->child[word[i]] == NULL){
			root->child[word[i]] = new trie();
		}

		root = root->child[word[i]];
	}
	root->isTerminal = true;
}

set<string> output;

bool allNull(trie* tr){
	for(int i=0; i<256; i++){
		if(tr->child[i] != NULL)
			return false;
	}

	return true;
}

void check(char matrix[MAX][MAX], int visited[MAX][MAX], trie* tr, int r, int c, int i, int j, string temp){
	if(tr->isTerminal)
		output.insert(temp);


	if(tr->isTerminal && allNull(tr)){
		output.insert(temp);
		return;
	}

	if(i < 0 || i >= r || j < 0 || j >= c || visited[i][j] == 1 || tr->child[matrix[i][j]] == NULL)
		return;

	

	if(tr->child[matrix[i][j]] && visited[i][j] == 0){
		visited[i][j] = 1;
		trie* next = tr->child[matrix[i][j]];

		string str(1, matrix[i][j]);
		check(matrix, visited, next, r, c, i-1, j, temp + str);
		check(matrix, visited, next, r, c, i+1, j, temp + str);
		check(matrix, visited, next, r, c, i, j-1, temp + str);
		check(matrix, visited, next, r, c, i, j+1, temp + str);
		check(matrix, visited, next, r, c, i-1, j-1, temp + str);
		check(matrix, visited, next, r, c, i-1, j+1, temp + str);
		check(matrix, visited, next, r, c, i+1, j-1, temp + str);
		check(matrix, visited, next, r, c, i+1, j+1, temp + str);
	}
}

void word_boggle(char matrix[MAX][MAX], int visited[MAX][MAX], trie* tr, int r, int c){

	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(tr->child[matrix[i][j]] && visited[i][j] == 0){
				check(matrix, visited, tr, r, c, i, j, "");
			}
		}
	}
}


int main(){

	int t; cin>>t;

	while(t--){
		output.clear();
		int n; cin>>n; 

		set<string> v; 
		for(int i=0; i<n; i++){
			string temp;
			cin>>temp;
			v.insert(temp);
		}

		int r, c; cin>>r>>c;
		char matrix[MAX][MAX];
		int visited[MAX][MAX];

		memset(visited, 0, MAX*MAX*sizeof(int));

		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				cin>>matrix[i][j];
			}
		}

		trie* tr = new trie();

		for(auto x : v){
			insert(tr, x);
		}	

		word_boggle(matrix, visited, tr, r, c);

		set<string> o2, o3;

		for(auto x: output){
			o2.insert(x);
		}

		for(auto x: output){

			string rev = string(x.rbegin(),x.rend());
			if(v.count(rev)){
				o2.insert(rev);
			}
		}

		for(auto x : o2){
			o3.insert(x);
		}

		for(auto x : v){
			for(auto y : o2){
				if(y.find(x) != string::npos){
					o3.insert(x);
				}
			}
		}
		
		for(auto x : o3)
			cout << x << " " ;

		cout << endl;
	}

	



	return 0;
}