class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i =0 ;i < m;i++){
            for(int j =0 ;j < n;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 2;
                }
            }
        }
        int tm = 0;
        int du[] = {1,0,-1,0};
        int dv[] = {0,1,0,-1};
        while(!q.empty()){
            int u = q.front().first.first;
            int v = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm,t);
            for(int i =0 ;i < 4;i++){
                int n1 = u + du[i];
                int n2 = v + dv[i];
                if(n1 >= 0 && n2 >= 0 && n1 < m && n2 < n && vis[n1][n2] == 0 && grid[n1][n2] == 1){
                    q.push({{n1,n2} , t+1});
                    vis[n1][n2] = 2;
                    grid[n1][n2] = 2;
                }
            }


        }
        for(int i =0;i < m;i++){
            for(int j =0;j < n ;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return tm;
    }
};
