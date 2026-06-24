class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;  
        vector<vector<int>> ans;     
        isSubset(nums, 0, temp,ans); 
        return ans;
    }
    void isSubset(vector<int> &nums, int i, vector<int> temp,vector<vector<int>>& ans){

       if(i==nums.size())
        {
            ans.push_back(temp);
            return;
        }
        
        isSubset(nums,i+1,temp,ans); // when element is not included
        temp.push_back(nums[i]);
        isSubset(nums,i+1,temp,ans);// when elemnt is included
   }
};
