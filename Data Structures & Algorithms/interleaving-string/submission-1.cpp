class Solution {
public: 
    bool f(int i, int j, vector<vector<int>>& t, string s1, string s2, string s3){
        int n = s1.size();
        int m = s2.size();
        if( i == n  && j == m){
            return true;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }
        bool ans = false;
        if(i < n && s1[i] == s3[i+j] && f(i+1,j,t,s1,s2,s3)){
            ans = true;
        }
        if(j < m && s2[j] == s3[i+j] && f(i,j+1,t,s1,s2,s3)){
            ans = true;
        }
        t[i][j] = ans;
        return t[i][j];
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1 + n2 != (int)s3.size()) return false;
        vector<vector<int>> t(n1+1, vector<int>(n2+1, -1));
        return f(0,0,t,s1,s2,s3);
    }
};
