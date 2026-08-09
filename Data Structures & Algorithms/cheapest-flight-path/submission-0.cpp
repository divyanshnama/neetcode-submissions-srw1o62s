class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         unordered_map<int, vector<pair<int, int>>> adj;
         vector<int> dist(n,INT_MAX);
        for(auto flight:flights )
        {
            adj[flight[0]].push_back({flight[1],flight[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        dist[src]=0;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops =it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops>k) continue;
            for(auto iter : adj[node])
            {
                int adjNode = iter.first;
                int edW = iter.second;

                if(cost+edW <dist[adjNode]  && stops <= k)
                {
                    dist[adjNode] = cost+edW;
                    q.push({stops+1,{adjNode,cost+edW}});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        else
            return dist[dst];

        
    }
};
