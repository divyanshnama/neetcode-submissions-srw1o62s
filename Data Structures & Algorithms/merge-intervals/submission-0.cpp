class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        int mini = intervals[0][0];
        int maxi = intervals[0][1];
        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> ans;
        for(int i =1;i<intervals.size();i++)
        {
            if(end >= intervals[i][0])
            {
                start = min(start,intervals[i][0]);
                end = max(end,intervals[i][1]);
                continue;
            }
                ans.push_back({start,end});
                start= intervals[i][0];
                end= intervals[i][1];
            
        }
        ans.push_back({start,end});
        return ans;
    }
};
