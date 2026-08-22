class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }

    int solve(int day,int buy,vector<int>& prices,vector<vector<int>>& dp)
    {
        if(day>=prices.size())
            return 0;
        if(dp[day][buy]!=-1) return dp[day][buy];
        if(buy)
        {
            int take = -prices[day] + solve(day+1,0,prices,dp);
            int skip = solve(day+1,1,prices,dp); 
            return dp[day][buy] = max(take,skip);
        }
        else{
            int sell = prices[day]+solve(day+2,1,prices,dp);
            int skip = solve(day+1,0,prices,dp);
            return dp[day][buy] = max(sell,skip);
        }
    }
};
