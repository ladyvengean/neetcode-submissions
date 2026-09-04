class Solution {
public:
    int f(int i, int j, vector<vector<int>>& t, int m, int n){
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(i >= m || j >= n){
            return 0;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }
        t[i][j] = f(i+1,j, t,m,n) + f(i, j+1, t,m,n);
        return t[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m+1,vector<int>(n+1,-1));
        return f(0,0, t, m, n);
    }
};
