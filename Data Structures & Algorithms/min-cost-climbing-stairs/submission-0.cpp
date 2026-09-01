class Solution {
public:
    int f(vector<int>& cost, vector<int>& t, int i){
        if(i == 0) return cost[0];
        if(i == 1) return cost[1];
        if(t[i] != -1){
            return t[i];
        }
        t[i] = cost[i] + min(f(cost,t,i-1), f(cost,t,i-2));
        return t[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> t(n+1,-1);
        return min(f(cost,t,n-1), f(cost,t,n-2));
    }
};
