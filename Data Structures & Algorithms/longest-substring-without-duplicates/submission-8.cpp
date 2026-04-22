class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() ==0) return 0;
        unordered_set<char> st;
        int maxCount =0;
        int count =0;
        int left =0;
        for(int i =0;i<s.size();i++)
        {
            while (st.count(s[i])) {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[i]);
            maxCount = max(maxCount, i - left + 1);
        }
        return maxCount;
    }
};
