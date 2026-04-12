class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        vector<int> sol;

        for(int i =0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>> vec;
        for(auto &it : mp)
            vec.push_back({it.first,it.second});

       
        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });
         
       for (int i = 0; i < k; i++) {
            sol.push_back(vec[i].first);
        }

        return sol;
    }
};
