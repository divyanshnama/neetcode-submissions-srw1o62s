class Solution {
public:
    int jump(vector<int>& nums) {
        int jump =0,l =0,r=0;
        int farthest = 0;
        while(r<nums.size()-1)
        {
            
            for(int i =l;i<=r;i++)
            {
                farthest = max(nums[i]+i,farthest);
            }
            jump++;
            l=r+1;
            r=farthest;
        }
        return jump;
    }
};
