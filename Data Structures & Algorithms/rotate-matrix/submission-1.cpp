class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose and then reverse
        int n = matrix.size();


        //transpose
        for(int i = 0;i<n;i++)
        {
            for(int j =i+1;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        //reverse
        for(int i =0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }

    }
};

//reverse
/*
    void reverseRow(vector<int>& row) {
        int left = 0;
        int right = row.size() - 1;
        while(i<j)
        {
            swap(matrix[i],matrix[j]);
            i++;
            j--
        }
    }
    */