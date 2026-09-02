class Solution {
public:
    int f(int i,int j, vector<int>& coins, vector<vector<int>>& t){
        if(i == 0) return INT_MAX - 1;
        if(i == 0 || j == 0) return 0;
       
        if(t[i][j] != -1){
            return t[i][j];

        }
        //not take
        int notTake = f(i-1,j, coins,t);
        int take = INT_MAX;
        if(coins[i-1] <= j){
            take = 1 + f(i , j- coins[i-1], coins, t);
        }
        t[i][j] = min(take,notTake);
        return t[i][j];
    }
    int coinChange(vector<int>& coins, int amount) {
        //like knapsack
        int n = coins.size();
        vector<vector<int>> t(n+1,vector<int>(amount+1, -1));
        int ans = f(n,amount,coins,t);
        if(ans >= INT_MAX - 1){
            return -1;
        }
        return ans;

    }
};
