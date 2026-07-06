class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        isSubset(nums,0,temp,ans);
        return ans;

    }
    void isSubset(vector<int> &nums, int i, vector<int> temp,vector<vector<int>>& ans){

       if(i==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        isSubset(nums,i+1,temp,ans);// when elemnt is included
        temp.pop_back();

        while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        isSubset(nums,i+1,temp,ans); // when element is not included



       
        
        
   }
};
