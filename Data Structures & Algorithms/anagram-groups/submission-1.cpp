class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string,vector<string>> mp;
        for (auto str : strs)
        {
            string key = str;
            sort(key.begin(),key.end());
            mp[key].push_back(str);
        }
        

        vector<vector<string>> ans;
        for(auto &p : mp)
        {
            cout << p.first << " -- ";
            for (auto &word : p.second) {   // print each string
            cout << word << " # ";
        }
            ans.push_back(p.second);
        }
        return ans;
        
    }
};
