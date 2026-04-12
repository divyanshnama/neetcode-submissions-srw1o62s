class Solution {
public:
    int maxArea(vector<int>& heights) {
        int p1 = 0;
        int p2 = heights.size()-1;
        int result =0;

        while(p1<p2)
        {
            int area = min(heights[p1],heights[p2])*(p2-p1);
            result = max(area,result);

            if(heights[p1]<= heights[p2])
                p1++;
            else
                p2--;
        }
        return result;
    }
};
