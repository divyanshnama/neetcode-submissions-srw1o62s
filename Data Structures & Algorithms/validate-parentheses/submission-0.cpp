class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++)
        {
            // FIX 1: check empty before top()
            if(!st.empty() && 
               ((st.top() == '(' && s[i] == ')') ||
                (st.top() == '{' && s[i] == '}') ||
                (st.top() == '[' && s[i] == ']')))
            {
                st.pop();
            }
            else 
            {
                st.push(s[i]);
            }
        }
        if(!st.empty())return false;
        return true;
    }
};
