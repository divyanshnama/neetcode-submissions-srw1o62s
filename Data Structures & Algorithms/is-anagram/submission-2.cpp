class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;

    vector<int> zeros(26,0);
    for(int i=0;i<s.size();i++)
    {
        zeros[s[i]-'a']++;
        zeros[t[i]-'a']--;
    }
    for(auto value:zeros)
    {
        if(value!=0) return false;
    }
    return true;
    }
};
