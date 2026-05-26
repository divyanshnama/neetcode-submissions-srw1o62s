class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low =0;
        int high = nums.size() -1;
        return binary_search(low,high,nums,target);
    }

    int binary_search(int low,int high,vector<int> &nums,int target)
    {
        if(low>high) return -1;
        int mid = low +(high-low)/2;
        if(nums[mid]==target) return mid;
        if (nums[mid]<target)
           return binary_search(mid+1,high,nums,target);
        else
           return  binary_search(low,mid-1,nums,target);
    }
};
