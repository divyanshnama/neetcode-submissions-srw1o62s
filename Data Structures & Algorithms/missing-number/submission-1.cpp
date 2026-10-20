class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i =0;
        int j =i+1;
        while(j<nums.size())
        {
            int diff = nums[j]-nums[i];
            if(diff>1) return j;
            i++;
            j++;
        }
        if(nums[0]==0) return nums.size();
        else return 0;
    }
};
