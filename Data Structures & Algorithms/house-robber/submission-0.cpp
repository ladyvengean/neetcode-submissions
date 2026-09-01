class Solution {
public:
    int f(vector<int>& nums, vector<int>& t, int i){
        if(i == 0){
            return nums[0];
        }
        if(i == 1){
            return max(nums[0], nums[1]);
        }
        if(t[i] != -1){
            return t[i];
        }
        t[i] = max(nums[i] + f(nums,t,i-2), f(nums,t,i-1));
        return t[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n+1,-1);
        if(n == 0){
            return 0;
        }
        return f(nums,t,n-1);
    }
};
