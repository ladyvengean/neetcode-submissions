class Solution {
public:
    
    void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<int>>& heights, int m, int n){
        vis[i][j] = 1;
        int du[] = {1,0,-1,0};
        int dv[] = {0,1,0,-1};
        for(int k =0 ;k < 4;k++){
            int n1 = i + du[k];
            int n2 = j+ dv[k];
            if(n1 >= 0 && n2 >= 0 && n1 < m && n2 < n && !vis[n1][n2] && heights[n1][n2] >= heights[i][j]){
                dfs(n1,n2,vis,heights,m,n);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pac(m,vector<bool>(n,false));
        vector<vector<bool>> atl(m,vector<bool>(n,false));

        //first row n last row
        for(int j=0;j < n;j++){
            dfs(0,j,pac,heights,m,n);
            dfs(m-1,j,atl,heights,m,n);
        }
        for(int i =0; i< m;i++){
            dfs(i,0,pac,heights,m,n);
            dfs(i,n-1,atl,heights,m,n);
        }
        vector<vector<int>> res;
        for(int i=0;i < m;i++){
            for(int j =0; j< n;j++){
                if(pac[i][j] && atl[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};
