class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;

        vector<int> counts1(26,0);
        vector<int> counts2(26,0);
        int k =s1.size();

        for(auto i : s1)
            counts1[i-'a']++;

        for (int i= 0;i<s2.size();i++)
        {
            counts2[s2[i]-'a']++;


            if(i>=k) 
            {
                counts2[s2[i-k]-'a']--;
            }

            if(counts1==counts2)return true;
        }
        return false;
    }
};
