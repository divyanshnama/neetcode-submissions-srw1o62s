class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(),-1);
        unordered_set<string> wordset(wordDict.begin(),wordDict.end());

        return dfs(s,wordset,0,dp);
    }

    bool dfs(string& s,unordered_set<string>& wordset,int i,vector<int>& dp)
    {
        if(i==s.size())
            return true;

        if (dp[i] != -1)
            return dp[i];

        for(int j =i;j<s.size();j++)
        {
            if(wordset.find(s.substr(i,j-i+1))!=wordset.end())
            {
                if(dfs(s,wordset,j+1,dp))
                    return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
};
