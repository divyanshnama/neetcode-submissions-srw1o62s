class Solution {
public:
    bool isAnagram(string s, string t) {
        int sizeS = s.size();
        int sizeT = t.size();

        if(sizeS != sizeT) return false;

        vector<int> count(26,0);

        for(int i = 0; i<s.length(); i++)
        {
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }

        for(auto val: count){
            if(val!=0) return false;
        }

        return true;


    }
};
