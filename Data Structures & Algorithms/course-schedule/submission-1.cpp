class Solution {
private:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1; // mark as "in current path"
        for (int it : adj[node]) {
            if (vis[it] == 1) {
                return false; // found a node currently on our path -> cycle
            }
            if (vis[it] == 0) {
                if (!dfs(it, adj, vis)) return false;
            }
            // vis[it] == 2 means already fully processed & safe, skip it
        }
        vis[node] = 2; // done processing this node, mark as safe
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }
        vector<int> vis(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (!dfs(i, adj, vis)) return false;
            }
        }
        return true;
    }
};