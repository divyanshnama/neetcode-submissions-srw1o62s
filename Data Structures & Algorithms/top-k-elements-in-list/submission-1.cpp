class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int> mp;
        for (auto num : nums) {
            mp[num]++;
        }
        // Step 2: create buckets (size = nums.size() + 1)
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);  // bucket[i] = numbers with freq i

        for (auto &p : mp) {
            buckets[p.second].push_back(p.first);
        }

        // Step 3: collect k most frequent (start from highest freq)
        vector<int> ans;
        for (int i = n; i >= 0 && ans.size() < k; i--) {
            for (auto num : buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k) return ans;
            }
        }
    }
};
