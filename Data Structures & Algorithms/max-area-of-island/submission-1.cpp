class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int m, int n){
        if(i < 0 || j < 0 || i >= m || j >= n || vis[i][j] == 1 || grid[i][j] == 0){
            return 0;
        }
        vis[i][j] = 1;
        int dr[] = {1,0,-1,0};
        int dc[] = {0,1,0,-1};
        int cnt = 1; //
        for(int k = 0; k < 4; k++){
            int newr = i + dr[k];
            int newc = j + dc[k];
            cnt += dfs(newr, newc, grid, vis, m, n);
        }
        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int maxArea = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    maxArea = max(maxArea, dfs(i, j, grid, vis, m, n));
                }
            }
        }
        return maxArea;
    }
};