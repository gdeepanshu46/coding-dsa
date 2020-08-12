#include <bits/stdc++.h>
using namespace std;

int board[11][11];

//func to check if it is possible to place queen at a particular row and col
bool isPossible(int n, int row, int col){

	//3 cases to check if a queen can be placed at a particular position

	//check its current column
	for(int i=row-1; i>=0; i--){
		if(board[i][col] == 1)
			return false;
	}

	//check top-left diagonal 
	for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
		if(board[i][j] == 1)
			return false;
	}

	//check top-right diagonal
	for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
		if(board[i][j] == 1)
			return false;
	}

	//else return true;
	return true;
}

void n_queens_helper(int n, int row){

	//base case: if all the n queens are placed correctly at n rows
	if(row == n){
		cout << "[";
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				//cout << board[i][j] << " ";
				if(board[i][j] == 1){
					cout << j + 1 << " ";
				}
			}
			
		}
		cout << "]";
		cout << " ";
		return;
	}

	for(int j=0; j<n; j++){
		if(isPossible(n, row, j)){
			board[row][j] = 1;
			n_queens_helper(n, row+1);
			board[row][j] = 0;
		}
	}
	
}

void n_queens(int n){

	//fill board with 0's
	memset(board, 0, 11*11*sizeof(int));

	//call helper funtion starting from the first row
	n_queens_helper(n, 0);
}


int main(){


	int n = 4;

	n_queens(n);


	return 0;
}