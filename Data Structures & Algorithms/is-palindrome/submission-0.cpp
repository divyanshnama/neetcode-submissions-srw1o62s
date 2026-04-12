class Solution {
public:
    bool isPalindrome(string s) {
        string  y="";
        for(char c : s)
        {
            if(isalnum(c))
            {        
                y+=tolower(c);
            }
            
        }
        int i =0;
        int j = y.size()-1;
        while(i<j)
        {
            if(y[i]==y[j])
            {
                i++;
                j--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
