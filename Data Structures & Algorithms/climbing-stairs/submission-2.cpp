class Solution {
public:
    vector<int> memo;

    int solve(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;

        if (memo[n] != -1) return memo[n];

        memo[n] = solve(n - 1) + solve(n - 2);
        return memo[n];
    }

    int climbStairs(int n) {
        memo.assign(n + 1, -1);  
        return solve(n);          
    }
};