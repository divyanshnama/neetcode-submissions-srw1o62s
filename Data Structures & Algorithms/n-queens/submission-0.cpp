class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> ans;
       vector<string> board(n);
       string s(n,'.');
       for(int i =0;i<n;i++)
            board[i]=s;

        vector<int> leftRow(n,0), upperDiagnal(2*n-1,0), lowerDiagnal(2*n-1,0);
        solve(0,board,leftRow,upperDiagnal,lowerDiagnal,ans,n);
        return ans;
    }
    void solve(int col,vector<string>& board,vector<int>& leftRow,
    vector<int>& upperDiagnal,vector<int>& lowerDiagnal,vector<vector<string>>& ans,
    int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }

        for(int row = 0;row<n;row++)
        {
            if(leftRow[row]==0 && upperDiagnal[n-1+row-col]==0 && lowerDiagnal[row+col]==0)
                {
                    board[row][col]='Q';
                    leftRow[row]=1;
                    upperDiagnal[n-1+row-col]=1;
                    lowerDiagnal[row+col]=1;
                    solve(col+1,board,leftRow,upperDiagnal,lowerDiagnal,ans,n);
                    board[row][col]='.';
                    leftRow[row]=0;
                    upperDiagnal[n-1+row-col]=0;
                    lowerDiagnal[row+col]=0;
                }
        }
    }
};
