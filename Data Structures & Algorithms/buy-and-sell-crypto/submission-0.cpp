class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit =0;
        int mini=prices[0];
        for (int i =1;i<n;i++)
        {
            mini = min(prices[i],mini);
            maxProfit =max(maxProfit,prices[i]-mini);
        }
        return maxProfit;
        
    }
};
