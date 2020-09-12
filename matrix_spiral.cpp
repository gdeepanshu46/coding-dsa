#include <bits/stdc++.h>
using namespace std;

vector<int> spiral(vector<vector<int>>& inputMatrix){
    int numRows = inputMatrix.size();
    int numCols = inputMatrix[0].size(); 
    
    vector<int> result;

    int topRow = 0;
    int btmRow = numRows - 1;
    int leftCol = 0;
    int rightCol = numCols - 1;
    

    while (topRow <= btmRow && leftCol <= rightCol){
        // copy the next top row
        for(int i=leftCol; i <= rightCol; i++) 
            result.push_back(inputMatrix[topRow][i]);
        topRow++;

        // copy the next right hand side column
        for(int i=topRow; i <= btmRow; i++) 
            result.push_back(inputMatrix[i][rightCol]);
        rightCol--;

        // copy the next bottom row
        if (topRow <= btmRow){
            for(int i=rightCol; i >= leftCol; i--)
                result.push_back(inputMatrix[btmRow][i]);
            btmRow--;
         }

        // copy the next left hand side column
        if (leftCol <= rightCol){
            for(int i=btmRow; i >= topRow; i--) 
                result.push_back(inputMatrix[i][leftCol]);
            leftCol++;
        }
    }

    return result;
}

int main(){

	  int row, col; cin>>row>>col;
	  vector<vector<int>> input(row, vector<int>(col));
	  for(int i=0; i<row; i++){
	    for(int j=0; j<col; j++){
	      cin>>input[i][j];
	    }
	  }
	  
	  vector<int> res = spiral(input);
	  
	  for(auto x : res)
	    cout << x << " ";


	return 0;
}