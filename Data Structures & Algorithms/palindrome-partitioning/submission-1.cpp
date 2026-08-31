class Solution {
public:
    bool isPali(string s, int l, int r){
        int n = s.size();
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void f(int i, vector<string>& path, vector<vector<string>>& ans, string s){
        //base case
        if(i == s.size()){
            ans.push_back(path);
            return;
        }
        //base case2
        for(int j = i;j < s.size();j++){
            string cur = s.substr(i, j-i+1);
            if(isPali(cur, 0, cur.size() - 1)){
                path.push_back(cur);
                f(j+1,path,ans,s);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> ans;
        f(0,path,ans,s);
        return ans;
    }
};
