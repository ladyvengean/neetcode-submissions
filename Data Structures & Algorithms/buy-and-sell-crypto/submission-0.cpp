class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = 0;
        int price = prices[0];
        for(int i=1;i < n;i++){
            int profit = prices[i] - price;
            if(profit > maxi){
                maxi = max(profit,maxi);

            }
            if(prices[i] < price){
                price = prices[i];
            }
        }
        return maxi;
    }
};
