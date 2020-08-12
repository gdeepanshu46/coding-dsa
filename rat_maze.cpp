#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> solution){
	for(int i=0; i<solution.size(); i++){
			for(int j=0; j<solution[0].size(); j++){
				cout << solution[i][j] << " ";
			}
			cout << endl;
		}
}

void rat_maze_helper(vector<vector<int>> maze, vector<vector<int>> solution, int row, int col, string temp){

	if(row == maze.size()-1 && col == maze[0].size()-1){

		solution[row][col] = 1;
		display(solution);
		cout << temp << endl;

		return;
	}

	if(row >= maze.size() || row <= -1 || col <= -1 || col >= maze[0].size() || maze[row][col] == 0 || solution[row][col] == 1){
		return;
	}
	
	solution[row][col] = 1;

	//exploring upwards
	rat_maze_helper(maze, solution, row-1, col, temp + "U");
	
	//exploring downwards
	rat_maze_helper(maze, solution, row+1, col, temp + "D");
	
	//exploring left
	rat_maze_helper(maze, solution, row, col-1, temp + "L");
	
	//exploring right
	rat_maze_helper(maze, solution, row, col+1, temp + "R");
	
	solution[row][col] = 0;

	return;
	
}

void rat_maze(vector<vector<int>> maze, int row, int col){
	vector<vector<int>> solution(row, vector<int>(col, 0));
	rat_maze_helper(maze, solution, 0, 0, "");
}

int main() {
   
   	int n = 3;
	vector<vector<int>> maze(n, vector<int>(n, 1));
	int row = maze.size();
	int col = maze[0].size();
	rat_maze(maze, row, col);

   
   return 0;
}