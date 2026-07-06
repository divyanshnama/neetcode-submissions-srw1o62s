class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans,n,0,0,"");
        return ans;
    }

    void solve(vector<string>& ans,int n,int open,int close,string curr)
    {
        if(curr.size()==n*2)
        {
            ans.push_back(curr);
            return;
        }

        if(open<n) solve(ans,n,open+1,close,curr+"(");
        if(close<open) solve(ans,n,open,close+1,curr+")");
    }
};
