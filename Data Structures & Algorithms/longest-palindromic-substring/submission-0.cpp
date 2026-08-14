class Solution {
public:
    string longestPalindrome(string s) {
       int start =0;
       int maxLen = 1;
       int left=0,right=0;
       int n = s.size();

       for(int i =0;i<s.size();i++)
       {
        //for odd length
        left =i;
        right =i;

        while(left>=0 && right <n && s[left]==s[right])
        {
            int len=  right-left+1;
            if(len>maxLen)
            {
                maxLen=len;
                start = left;
            }
            left--;
            right++;




        }
        //for even length
        left =i;
        right =i+1;

        while(left>=0 && right <n && s[left]==s[right])
        {
            int len=  right-left+1;
            if(len>maxLen)
            {
                maxLen=len;
                start = left;
            }
            left--;
            right++;


        }
       }
       return s.substr(start,maxLen); 
    }
};
