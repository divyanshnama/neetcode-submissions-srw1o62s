class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
       vector<vector<int>> visP = solve(heights,0);
       vector<vector<int>> visA = solve(heights,1);

       vector<vector<int>> ans;

       int n = heights.size();
       int m = heights[0].size();

       for(int  i =0;i<n;i++)
       {
        for(int j =0;j<m;j++)
        {
            if(visA[i][j]==1 && visP[i][j]==1)
                ans.push_back({i,j});
        }
       }

       return ans;
    }

     vector<vector<int>> solve(vector<vector<int>>& heights,int type)
     {
        int n = heights.size();
        int m = heights[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i =0;i<n;i++)
        {
            for(int j =0; j<m;j++)
            {
                if(type ==0 && (i==0 || j==0))
                    {
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                if(type ==1 && (i==n-1 || j==m-1))
                    {
                        q.push({i,j});
                        vis[i][j]=1;
                    }
            }
        }

        int del_row[]= {0,1,0,-1};
        int del_col[] ={-1,0,1,0};

        while(!q.empty())
        {
            int r  = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i =0;i<4;i++)
            {
                int nr = r + del_row[i];
                int nc = c + del_col[i];

                if(nr>=0 && nr < n && nc >= 0 && nc <m &&
                    vis[nr][nc]!=1 && heights[nr][nc] >= heights[r][c])
                    {
                        vis[nr][nc] =1;
                        q.push({nr,nc});
                    }
            }
        }

        return vis;

     }
};
