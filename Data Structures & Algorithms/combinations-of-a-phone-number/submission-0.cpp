class Solution {
public:
    vector<string> letterCombinations(string digits) {
         if (digits.empty())
            return {};
       unordered_map<char,string> m;
       vector<string> ans;
       string temp;
       
       m['2']="abc";
       m['3']="def";
       m['4']="ghi";
       m['5']="jkl";
       m['6']="mno";
       m['7']="pqrs";
       m['8']="tuv";
       m['9']="wxyz"; 

       solve(0 ,digits,m,ans,temp);
       return ans ;
    }

    void solve(int i ,string& digits, unordered_map<char,string>& m,
    vector<string>& ans,string& temp)
    {
        if(i==digits.size())
        {
            ans.push_back(temp);
            return;
        }
        string str = m[digits[i]];
        for(int j=0;j<str.size();j++)
        {
            temp.push_back(str[j]);
            solve(i+1,digits,m,ans,temp);
            temp.pop_back();
        }
    }
};
