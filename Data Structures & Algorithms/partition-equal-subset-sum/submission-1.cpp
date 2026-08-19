class Solution {
public:
    vector<vector<int>> dp;

    bool canPartition(vector<int>& nums) {
        int total = 0;

        for (auto x : nums)
            total += x;

        if (total % 2 != 0)
            return false;

        int target = total / 2;

        dp.assign(nums.size(), vector<int>(target + 1, -1));

        return solve(0, target, nums);
    }

    bool solve(int i, int sum, vector<int>& nums) {

        // Found required sum
        if (sum == 0)
            return true;

        // No elements left
        if (i == nums.size())
            return false;

        if(sum<0) return false;

        // Already calculated
        if (dp[i][sum] != -1)
            return dp[i][sum];

        // Don't take current element
        bool not_take = solve(i + 1, sum, nums);

        // // Take current element
        // bool take = false;

        // if (nums[i] <= sum)
            bool take = solve(i + 1, sum - nums[i], nums);

        return dp[i][sum] = take || not_take;
    }
};