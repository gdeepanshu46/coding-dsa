#include <bits/stdc++.h>
using namespace std;

bool isA(vector<vector<char>>& matrix, int i, int j){
	return matrix[i][j] == '.';
}

bool isI(vector<vector<char>>& matrix, int i, int j){
	return matrix[i+1][j] == '.';
}

bool isO(vector<vector<char>>& matrix, int i, int j){
	return (matrix[i+1][j+1] == '.' &&  matrix[i][j+1] == '*');
}

bool isU(vector<vector<char>>& matrix, int i, int j){
	return matrix[i][j+1] == '.';
}

string constellation(vector<vector<char>>& matrix){
	int r = matrix.size();
	int c = matrix[0].size();

	string res;

	int i = 0;
	while(i < c){
		if(matrix[0][i] == '#'){
			res.push_back('#');
			i++;
		}
		else{
			int p = 0;
			int q = i;

			if(isA(matrix, p, q)) res.push_back('A');
			else if(isI(matrix, p, q)) res.push_back('I');
			else if(isO(matrix, p, q)) res.push_back('O');
			else if(isU(matrix, p, q)) res.push_back('U');
			else res.push_back('E');
			i += 3;
		}
	}
	return res;
}

int main(){

	int row = 3;
	int col; cin>>col;
	vector<vector<char>> matrix(row, vector<char> (col, 0));

	for(auto &x : matrix){
		for(auto &y : x)
			cin>>y;
	}

	 cout << constellation(matrix) << endl;


	return 0;
}