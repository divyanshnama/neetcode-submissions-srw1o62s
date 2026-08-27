class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        if(s1.size()+s2.size()!=s3.size()) return false ;
        return solve(s1,s2,s3,0,0,dp);
    }

    bool solve(string s1, string s2, string s3,int i,int j,vector<vector<int>>& dp)
    {
        int k = i+j;
        if(s3.size()==k) return true;

        if(dp[i][j]!=-1) return dp[i][j];

        bool ans = false;

        //take chars from s1
        if(i<s1.size() && s1[i]==s3[k])
            ans = solve(s1,s2,s3,i+1,j,dp);
        
        if(j<s2.size() && s2[j]==s3[k])
            ans= solve(s1,s2,s3,i,j+1,dp);

        return dp[i][j] = ans;
    }
};
