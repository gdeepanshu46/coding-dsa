//Time : O(n^3) as for O(n^2) for each and every element will check O(n) times more. 
//Space : O(n^2) for visited array

#include <bits/stdc++.h>
using namespace std;

//total count of such unique words
int count_ = 0;

//Recursive function for checking all possibilities
void helper(vector<vector<char>>& v, vector<vector<int>>& visited, string s, int i, int j, int ind){
	int n = v.size();
	int m = v[0].size();

	
	//if i and j becomes out-of-bound or 
	//we are coming back to the same val, we have started, return
	if(i < 0 || i >= n || j < 0 || j >= m || visited[i][j] == 1)
		return;

	//if last char of str matches with char in matrix, increment count & return
	if(ind == s.size()-1 && s[ind] == v[i][j]){
		visited[i][j] = 1;
		count_++;
		return;
	}

	
	//if char at str matches with char at matrix, increment ind and try all paths
	//also set visited[i][j] to 1 as already used
	if(s[ind] == v[i][j]){
		visited[i][j] = 1;
		helper(v, visited, s, i, j+1, ind+1); //moving right
		helper(v, visited, s, i, j-1, ind+1); //moving left
		helper(v, visited, s, i+1, j, ind+1); //moving down 
		helper(v, visited, s, i-1, j, ind+1); //moving up
		// visited[i][j] = 0;
	}
}


int count(vector<vector<char>>& v, string s){

	int n = v.size();
	int m = v[0].size();

	//matrix for marking an ele to be visited or not
	vector<vector<int>> visited(n, vector<int> (m, 0));

	//check for each ele, if it forms the given str
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(visited[i][j]) continue;
			if(v[i][j] == s[0]){
				helper(v, visited, s, i, j, 0);
			}
		}
	}

	//Reset global var again to 0
	int cnt = count_;
	count_ = 0;

	return cnt;
}

int main(){
	int n, m; cin >> n >> m;
	string s; cin >> s;
	vector<vector<char>> v(n, vector<char> (m));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
			cin>>v[i][j];
	}
	cout << count(v, s)<< endl;

	return 0;
}