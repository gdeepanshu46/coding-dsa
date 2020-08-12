#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;
const int d = 100;
bool can_place(int board[d][d],int n,int cur_row,int cur_col,int ele)
{
    if(cur_row<=n && cur_row>=0 && cur_col <=n && cur_col>=0 && board[cur_row][cur_col]==0)
    {
        for(int i=0;i<9;i++)
        {
            if(board[cur_row][i]==ele)
                return false;
            if(board[i][cur_col]==ele)
                return false;
        }
        int sq = sqrt(n);
        int row_temp = (cur_row/sq)*sq;
        int col_temp = (cur_col/sq)*sq;
        for(int i=row_temp;i<row_temp+sq;i++)
        {
            for(int j=col_temp;j<col_temp+sq    ;j++)
            {
                if(board[i][j]==ele)
                    return false;
            }
        }
        return true;
    }
    return false;
}

bool solve_sudoku(int board[d][d],int n,int cur_row,int cur_col)
{
    if(cur_row==n)
    {
        return true;
    }
    if(cur_col==n)
    {
       return solve_sudoku(board,n,cur_row+1,0);
    }
    if(board[cur_row][cur_col]!=0)
    {
        return solve_sudoku(board,n,cur_row,cur_col+1);
    }


    for(int i=1;i<=n;i++)
    {
        if(can_place(board,n,cur_row,cur_col,i))
        {
            board[cur_row][cur_col]=i;
            bool success = solve_sudoku(board,n,cur_row,cur_col+1);
            if(success)
            {
                return true;
            }
            board[cur_row][cur_col]=0;
        }
    }
    return false;
}

void print_board(int board[d][d],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<"  ";
        }
        cout<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    int board[d][d]=
    {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    bool ans = solve_sudoku(board,n,0,0);
    if(ans)
        print_board(board,9);
    else
        cout<<"error!";

    return 0;
}


