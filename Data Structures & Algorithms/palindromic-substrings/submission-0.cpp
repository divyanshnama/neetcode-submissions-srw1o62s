class Solution {
public:
    int countSubstrings(string s) {
        int count  =0;
        int  n  = s.size();
        int left=0;
        int right =0;

        for(int i = 0;i<n;i++)
        {
            left =i;
            right =i;

            while(i>=0 &&  i<n &&  left>=0 && right<n && s[left]==s[right])
            {
                count++;
                left--;
                right++;
            }


            left=i;
            right=i+1;

            while(i>=0 &&  i<n &&  left>=0 && right<n && s[left]==s[right])
            {
                count++;
                left--;
                right++;
            }
        }

        return count;
    }
};
