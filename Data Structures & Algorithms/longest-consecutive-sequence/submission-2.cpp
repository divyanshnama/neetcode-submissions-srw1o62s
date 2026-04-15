class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        set<int> st(nums.begin(), nums.end()); // automatically removes duplicates
        vector<int> result(st.begin(), st.end());
        int longest = 1;  // longest streak found so far
        int count = 1;    // current streak length

        for (int i = 1; i < result.size(); i++) {
            if (result[i] == result[i - 1] + 1) {
                count++;  // continue the streak
            } else {
                longest = max(longest, count);
                count = 1;  // reset streak
            }
            
        }
        longest = max(longest, count);

        return longest;
    }
};