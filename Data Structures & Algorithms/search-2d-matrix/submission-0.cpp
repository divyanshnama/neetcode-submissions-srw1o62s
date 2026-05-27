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
                for(int j=0;j<=col;j++)
                {
                     if(target==matrix[i][j]) return true;
                }
            }
        }
        return false;
    }
};
