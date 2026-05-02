class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> count;
        int maxf=0;
        int left=0;
        int right=0;
        int maxLength=0;
        while(right<s.size() && left<=right)
        {
            count[s[right]]++;
            maxf  = max(maxf,count[s[right]]);

            while((right-left+1)-maxf > k)
            {
                count[s[left]]--;
                left++;
            }
            maxLength = max(maxLength,right-left+1);
            right ++;
            
        }
        return maxLength;
    }
};
