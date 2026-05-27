class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size()-1;
        int col = matrix[0].size()-1;
        for(int i =0;i<=rows;i++)
        {
            if(target==matrix[i][col])return true;
            else if(target>matrix[i][col]) continue;
            else{
               int l = 0;
               int r = col;
               while(l<=r)
               {
                int mid = l +(r-l)/2;
                if(matrix[i][mid]==target) return true;
                else if(matrix[i][mid] < target) l=mid+1;
                else 
                    r=mid-1;
               }
            }
        }
        return false;
    }
};
