#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;
const int d = 8;
bool can_place(int board[d][d],int n,int cur_row,int cur_col)
{
    if(cur_row<n && cur_row>=0 && cur_col <n && cur_col>=0 && board[cur_row][cur_col]==0)
    {
        return true;
    }
    return false;
}

bool knight_moves(int board[d][d],int n,int move,int cur_row,int cur_col)
{
    if(move==n*n)
    {
        return true;
    }
    int row_dir[] = {1,2,2,1,-1,-2,-2,-1};
    int col_dir[] = {-2,-1,1,2,2,1,-1,-2};
    for(int i=0;i<8;i++)
    {
        int nxt_row = cur_row + row_dir[i];
        int nxt_col = cur_col + col_dir[i];
        if(can_place(board,n,nxt_row,nxt_col))
        {
            board[nxt_row][nxt_col]=move+1;
            bool success = knight_moves(board,n,move+1,nxt_row,nxt_col);
            if(success)
            {
                return true;
            }
            board[nxt_row][nxt_col]=0;
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
    int board[d][d]={0};
    board[0][0]=1;
    bool ans = knight_moves(board,n,1,0,0);
    if(ans)
        print_board(board,n);
    else
        cout<<"error!";

    return 0;
}


