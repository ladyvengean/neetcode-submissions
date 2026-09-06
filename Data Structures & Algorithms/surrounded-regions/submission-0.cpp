class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis){
        int m= board.size();
        int n = board[0].size();
        vis[row][col] = 1;
        int du[] = {1,0,-1,0};
        int dv[] = {0,1,0,-1};
        for(int i=0;i < 4;i++){
            int n1 = row + du[i];
            int n2 = col + dv[i];
            if(n1 >= 0 && n2 >= 0 && n1 < m && n2 < n && vis[n1][n2] == 0 && board[n1][n2] == 'O'){
                dfs(n1,n2,board,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        if( m == 0){
            return;
        }
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int j = 0; j < n;j++){
            if(board[0][j] == 'O' && vis[0][j] == 0){
                dfs(0,j,board,vis);
            }
            if(board[m-1][j] == 'O' && vis[m-1][j] ==0){
                dfs(m-1,j,board,vis);
            }
        }
        for(int i=0;i< m;i++){
            if(board[i][0] == 'O' && vis[i][0] == 0){
                dfs(i,0,board, vis);
            }
            if(board[i][n-1] == 'O' && vis[i][n-1] == 0){
                dfs(i,n-1,board,vis);
            }
        }
        for(int i=0;i < m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j] == 0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }

    }
};
