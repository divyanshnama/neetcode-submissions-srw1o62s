class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const auto& a, const auto& b) { return a[1] < b[1]; });
        int end = intervals[0][1];
        int remove =0;
        for(int i =1;i<intervals.size();i++)
        {
            if(end>intervals[i][0])
                remove++;
            else{
                end= intervals[i][1];
            }
        }
        return remove;
    }
};
