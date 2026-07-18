class Solution {
   public:
    int maxArea = 0;
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();
        int area = 1;

        queue<pair<int, int>> q;
        vis[i][j] = 1;
        q.push({i, j});

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;

            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 &&
                    vis[nrow][ncol] == 0) {
                    area++;
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        maxArea = max(maxArea, area);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] == 1) {
                    bfs(grid, vis, i, j);
                }
            }
        }

        return maxArea;
    }
};
