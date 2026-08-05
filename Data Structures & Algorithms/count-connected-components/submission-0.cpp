class Solution {
public:
    void dfs(int node ,unordered_map<int,vector<int>>& adj,vector<int>& vis)
    {
        vis[node]=1;

        for(auto& nei : adj[node])
        {
            if(!vis[nei])
            {
                dfs(nei,adj,vis);
            }
        }
        return;
    }

    int countComponents(int n, vector<vector<int>>& edges) {

        unordered_map<int,vector<int>> adj;

        for(auto& edge :edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> vis(n,0);
        int count = 0;
        for(int i = 0;i<n;i++)
        {
            if(vis[i]==0)
            {
                count++;
                dfs(i,adj,vis);
            }
        }
        return count;
        
    }
};
