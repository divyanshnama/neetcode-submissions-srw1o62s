class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result ;
        vector<int> subset;
        backtrack(result,subset,nums,0);
        return result;
    }

void backtrack(vector<vector<int>>& resultSets,
               vector<int>& tempSet,
               vector<int>& nums,
               int start) {
    
    resultSets.push_back(tempSet);

    for (int i = start; i < nums.size(); i++) {

        tempSet.push_back(nums[i]);

        backtrack(resultSets, tempSet, nums, i + 1);

        tempSet.pop_back();
    }
}
};
