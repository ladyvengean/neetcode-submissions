class Solution {
public:
    int f(int i,int buy, vector<int>& prices, vector<vector<int>>& t){
        if(i >= prices.size()){
            return 0;
        }
        if(t[i][buy] != -1){
            return t[i][buy];
        }
        int profit = 0;
        if(buy){
            profit = max(-prices[i] + f(i+1,0,prices,t), 0 + f(i+1,1,prices,t));
        }
        else{
            profit = max(prices[i] + f(i+2,1,prices,t), f(i+1,0,prices,t));
        }
        t[i][buy] = profit;
        return t[i][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> t(n+1,vector<int>(2,-1));
        return f(0,1,prices,t);
    }
};
