class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxProfit =0;
      for (int i =0;i<prices.size();i++)
      {
        mini = min(prices[i],mini);
        maxProfit = max(prices[i]-mini,maxProfit);
      }
      return maxProfit;  
    }
};
