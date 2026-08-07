class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n =edges.size();
        vector<int> parent(n+1,-1);

        for(auto& edge : edges)
        {
            int parent_x = find(parent,edge[0]);
            int parent_y = find(parent,edge[1]);

            if(parent_x== parent_y)
                return edge;
            else
                parent[parent_x]=parent_y; //union
        }        
    }

    int find(vector<int>& parent,int x )
    {
        if(parent[x]==-1)
        {
            return x;
        }
        return parent[x] = find(parent,parent[x]);
    }
};
