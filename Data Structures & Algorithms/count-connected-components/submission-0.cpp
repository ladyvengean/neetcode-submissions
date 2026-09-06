class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(vis[it] == -1){
                dfs(it,adj,vis);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,-1);
        int cnt = 0;
        for(int i =0 ;i < n;i++){
            if(vis[i] == -1){
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt;
    }
};
