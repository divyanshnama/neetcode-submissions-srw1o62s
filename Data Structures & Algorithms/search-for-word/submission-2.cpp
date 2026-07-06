class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m =board.size();
        int n = board[0].size();
        for(int  i =0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(board[i][j]==word[0])
                    if(search(board,word,i,j,0,m,n)) return true ;
            }
        }

        return false;
    }

    bool search(vector<vector<char>>& board, string& word,int i,int j ,int k,int m,int n)
    {
        if(k==word.size()) return true;
        if(i==m || j==n || j<0 || i<0 || board[i][j]!=word[k]) return false;
        char ch =board[i][j];
        board[i][j]='#';
        bool op1 =search(board,word,i+1,j,k+1,m,n);
        bool op2 =search(board,word,i-1,j,k+1,m,n);
        bool op3 =search(board,word,i,j+1,k+1,m,n);
        bool op4 =search(board,word,i,j-1,k+1,m,n);
        board[i][j]=ch;

        return op1 || op2 || op3 || op4 ;
    }
};
