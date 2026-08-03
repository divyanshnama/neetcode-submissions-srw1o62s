class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for (auto& it : prerequisites) {
            int a = it[0];
            int b = it[1];
            //b-->a
            adj[b].push_back(a);
            // degree a ka increase ho rha h 
            indegree[a]++;
        }

        queue<int> q;

        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) q.push(i);
        }
        int count=0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        if (count== numCourses)
            return true;
        else
            return false;
    }
};
