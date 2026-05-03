class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size()>s2.size()) return false ;
        int i=0;
        int j=s1.size()-1;
        string s3 =s1;
        sort(s3.begin(),s3.end());
        while(j<s2.size())
        {
            string temp = s2.substr(i,s1.size());
            sort(temp.begin(),temp.end());
            if(temp==s3)
                return true;
            else {
                j++;
                i++;
            }
        }
        return false;
    }
};
