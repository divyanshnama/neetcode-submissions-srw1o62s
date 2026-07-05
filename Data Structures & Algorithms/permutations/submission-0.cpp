class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> temp;
        vector<int> freq(nums.size(), 0);
        solve(nums,temp,sol,freq);
        return sol;
    }
    void solve(vector<int>& nums,vector<int>& temp,vector<vector<int>>& sol,vector<int>& freq)
    {
        if (temp.size()==nums.size())
        {
            sol.push_back(temp);
            return;
        }
        for(int i =0;i<nums.size();i++)
        {
            if(freq[i]==0)
            {
                temp.push_back(nums[i]);
                freq[i]=1;
                solve(nums,temp,sol,freq);
                temp.pop_back();
                freq[i]=0;
            }
        }
    }
};
