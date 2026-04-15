class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if (nums.empty()) return 0;

        set<int> st;
        for (auto &i : nums)
            st.insert(i);

        int maxLength = 1;
        int length = 1;

        auto prev = st.begin();
        auto curr = next(prev);

        while (curr != st.end()) {
            if (*curr - *prev == 1)
                length++;
            else {
                maxLength = max(length, maxLength);
                length = 1;
            }
            prev = curr;
            ++curr;
        }

        maxLength = max(length, maxLength);

        return maxLength;
    }
};