class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        int sum = 0;
        solve(nums, target, 0, temp, ans, sum);
        return ans;
    }
    void solve(vector<int>& nums, int target, int i, vector<int>& temp, vector<vector<int>>& ans,
               int sum) {
        if (sum == target) {
            ans.push_back(temp);
            return;
        }

        if (i == nums.size() || sum > target) return;

        // include current element
        temp.push_back(nums[i]);
        solve(nums, target, i, temp, ans, sum + nums[i]);

        temp.pop_back();

        // exclude current element
        solve(nums, target, i + 1, temp, ans, sum);
    }
};
