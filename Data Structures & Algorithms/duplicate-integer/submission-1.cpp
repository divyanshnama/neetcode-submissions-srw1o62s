#include<bits/stdc++.h>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> un;
        for (int i =0;i<nums.size();i++)
        {
            un.insert(nums[i]);
        }

        if(un.size()<nums.size()) return true;
        else return false;
    }
};