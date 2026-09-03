class Solution {
public:
    bool subsetsum(vector<int>& nums, int sum, vector<vector<int>>& t){
        int n = nums.size();
        //t is n and sum/2;
        for(int i = 0;i < n+1;i++){
            for(int j =0; j< sum+1;j++){
                if(i == 0){
                    t[i][j] = false;
                }if(j == 0){
                    t[i][j] = true;
                }
            }
        }
        for(int i =1;i < n+1;i++){
            for(int j =1;j< sum+1;j++){
                if(nums[i-1] <= j){
                    t[i][j] = t[i-1][j- nums[i-1]] || t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        // subset sum
        int n = nums.size();
        // check if there is a subarray for sum(nums) /2;
        int sum = 0;
        //vector<vector<int>> t(n+1, vector<int>(sum/2 + 1, false));
        for(int i =0 ;i < n;i++){
            sum += nums[i];

        }
        vector<vector<int>> t(n+1, vector<int>(sum/2 + 1, false));
        if(sum % 2 != 0){
            return false;
        }

        return subsetsum(nums,sum/2,t);
    }
};
