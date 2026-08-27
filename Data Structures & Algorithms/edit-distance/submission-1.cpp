class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return solve(word1,word2,0,0,dp);
    }

    int solve(string& w1, string& w2,int i,int j,vector<vector<int>>& dp)
    {
        if(w1.size()==i)  return w2.size()-j;
        if(w2.size()==j) return w1.size()-i;

        if(w1[i]==w2[j]) return solve(w1,w2,i+1,j+1,dp);

        if(dp[i][j]!=-1) return dp[i][j];
        
        int insert = solve(w1,w2,i,j+1,dp);
        int remove = solve(w1,w2,i+1,j,dp);
        int replace = solve(w1,w2,i+1,j+1,dp);

        return dp[i][j]=1+ min({insert,remove,replace});
    }
};
