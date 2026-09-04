class Solution {
public:
    int subsetsum(vector<int>& nums, int sum, vector<vector<int>>& t){
        int n = nums.size();
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < sum+1; j++){
                if(i == 0 && j == 0) t[i][j] = true;
                else if(i == 0) t[i][j] = false;
                //else if(j == 0) t[i][j] = true;
            }
        }
        for(int i = 1; i < n+1; i++){
            for(int j = 0; j < sum+1; j++){
                if(nums[i-1] <= j){
                    t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i];

        if(abs(target) > sum) return 0;          // target unreachable
        if((sum + target) % 2 != 0) return 0;    // must split evenly

        int s = (sum + target) / 2;
        vector<vector<int>> t(n+1, vector<int>(s+1, 0));
        return subsetsum(nums, s, t);
    }
};