class Solution {
public:
    int f(string& X, string& Y, int m, int n, vector<vector<int>>& t){
        if(m == 0 || n == 0){
            return 0;
        }
        if(t[m][n] != -1){
            return t[m][n];
        }
        if(X[m-1] == Y[n-1]){
            t[m][n] = 1 + f(X,Y, m-1, n-1,t);
        }
        else{
            t[m][n] = max(f(X,Y, m-1,n,t), f(X,Y,m,n-1,t));
        }
        return t[m][n];
    }
    int longestCommonSubsequence(string text1, string text2) {
        //lcs
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> t(m+1,vector<int>(n+1,-1));
        return f(text1, text2, m,n,t);
    }
};
