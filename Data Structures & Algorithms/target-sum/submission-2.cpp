class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum =0;
        for(auto i:nums)
            sum+=i;
            int offset=sum;
        vector<vector<int>> dp(nums.size(),vector<int>(sum*2+1,-1));
        return solve(nums,target,0,0,dp,offset);  
    }

    int solve(vector<int>& nums,int target,int i,int sum,vector<vector<int>>& dp,int offset)
    {
        if(i==nums.size() )
            return sum==target;
        if(dp[i][sum + offset]!=-1) return dp[i][sum+offset];
        int plus = solve(nums,target,i+1,sum+nums[i],dp,offset);
        int minus  = solve(nums,target,i+1,sum-nums[i],dp,offset);
        return dp[i][sum+offset]=plus+minus;
    }
};
