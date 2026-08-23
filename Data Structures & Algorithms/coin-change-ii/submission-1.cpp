class Solution {
   public:
    int change(int amount, vector<int>& coins) { 
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return solve(coins.size()-1, coins, amount,dp); 
        }

    int solve(int i, vector<int>& coins, int amount,vector<vector<int>>& dp) {
        if (i == 0) return amount % coins[i] == 0 ? 1 : 0;

        if (amount == 0) return 1;

        if(dp[i][amount]!=-1) return dp[i][amount];
        int nonPick = solve(i-1, coins, amount,dp);
        int pick = 0;
        if (amount >= coins[i]) pick = solve(i, coins, amount - coins[i],dp);
        return dp[i][amount]=pick + nonPick;
    }
};
