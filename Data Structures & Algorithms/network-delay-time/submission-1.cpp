class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {


        unordered_map<int,vector<pair<int ,int>>> adj;
         for (auto time : times) {
            int u = time[0];
            int v = time[1];
            int wt = time[2];

            adj[u].push_back({v, wt});
        }


        priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> q;


                vector<int> dist(n+1,INT_MAX);

                dist[k]= 0;

                q.push({0,k});

                while(!q.empty())
                {
                    int d =  q.top().first;
                    int node = q.top().second;

                    q.pop();

                    if(d >dist[node]) continue;

                    for(auto edge: adj[node])
                    {
                        int v =  edge.first;
                        int wt =  edge.second;

                        if(dist[node]+ wt <dist[v])
                        {
                            dist[v]=  dist[node]+ wt;
                            q.push({dist[v],v});
                        }
                    }
                }

        // Find the maximum shortest distance
        int ans = 0;

        for (int i = 1; i <= n; i++) {

            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    
    }
};
