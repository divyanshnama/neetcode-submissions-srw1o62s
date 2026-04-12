class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<string> sorted;

        for (int i = 0; i < strs.size(); i++) {
            string res = strs[i];
            sort(res.begin(), res.end());  
            sorted.push_back(res);
        }
        vector<vector<string>> ans;
        vector<bool> used(strs.size(), false);
        for (int i = 0;i<sorted.size();i++)
        {
            if (used[i]) continue;  // skip already grouped
            vector<string> tempans;
            tempans.push_back(strs[i]);
            used[i] = true;
            string temp =  sorted[i];
            for(int j=i+1;j<sorted.size();j++)
            {
                
                string temp2 = sorted[j];
                if(temp.length()==temp2.length())
                {
                    if(!used[j] && temp==temp2)
                    {
                        tempans.push_back(strs[j]);
                        used[j] = true; // mark as used
                    }
                }
            }
            ans.push_back(tempans);
        }
        return ans;
    }
};
