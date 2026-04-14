class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix;
        vector<int> suffix(nums.size(),1);
        prefix.push_back(1);
        int product =1;
        for (int i =1;i<nums.size();i++)
            {
                product = nums[i-1]*product;
                prefix.push_back(product);
            }
        product =1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            product=nums[i+1]*product;
            suffix[i]=product;
        }

        for(int i=0;i<nums.size();i++)
        {
            nums[i]=suffix[i]*prefix[i];
        }
        return nums;
    }
};
