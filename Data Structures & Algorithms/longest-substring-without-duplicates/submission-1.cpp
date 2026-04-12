class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        int start= 0;
        int end  =0;
        unordered_set<char> st;
        int maxLength =0;

        while (start<n)
        {
            if(st.find(s[start])==st.end())
            {
                st.insert(s[start]);
                maxLength = max(start-end+1,maxLength);
                start++;
            }
            else {
                st.erase(s[end]);
                end++;
            }
        }
        return maxLength;
        
    }
};
