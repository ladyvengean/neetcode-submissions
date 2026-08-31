class Solution {
public:
    void f(int open, int close, int n, string& cur, vector<string>& ans) {
        // base case
        if (open == n && close == n) {
            ans.push_back(cur);
            return;
        }

        // take '(' 
        if (open < n) {
            cur += '(';
            f(open + 1, close, n, cur, ans);
            cur.pop_back();
        }

        // take ')' 
        if (close < open) {
            cur += ')';
            f(open, close + 1, n, cur, ans);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        f(0, 0, n, cur, ans);  
        return ans;
    }
};