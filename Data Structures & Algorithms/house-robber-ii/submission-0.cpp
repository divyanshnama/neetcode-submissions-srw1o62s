class Solution {
public:
    vector<int> memo;

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        // Case 1: Rob from 0 to n-2
        int case1 = solve(nums, 0, n - 2);

        // Case 2: Rob from 1 to n-1
        int case2 = solve(nums, 1, n - 1);

        return max(case1, case2);
    }

    int solve(vector<int>& nums, int start, int end) {
        memo.assign(nums.size(), -1);
        return dfs(nums, start, end);
    }

    int dfs(vector<int>& nums, int i, int end) {
        if (i > end) return 0;

        if (memo[i] != -1)
            return memo[i];

        int pick = nums[i] + dfs(nums, i + 2, end);
        int notPick = dfs(nums, i + 1, end);

        return memo[i] = max(pick, notPick);
    }
};