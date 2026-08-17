class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {

        
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans  = solve(n-1,coins,amount,dp);
        return (ans >=1e9) ? -1:ans;
    }

    int solve(int i,vector<int>& coins,int amount,vector<vector<int>>& dp)
    {
        if(i==0) 
        {
            if(amount % coins[i]==0) return amount/coins[i];

            return 1e9; 
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int not_take = solve(i-1,coins,amount,dp);
        int take  =1e9;
        if(amount>=coins[i])
            take =1+solve(i,coins,amount-coins[i],dp);

         return dp[i][amount] = min(take,not_take);
    }
};
