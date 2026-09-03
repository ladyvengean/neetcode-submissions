class Solution {
public:
    int f(int i, vector<int>& nums, vector<int>& t){
        if(t[i] != -1) return t[i];
        int best  = 1;
        for(int k = 0;k < i;k++){
            if(nums[k] < nums[i]){
                best = max(best ,  1 + f(k, nums,t));
            }
        }
        t[i] = best;
        return t[i];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n,-1);
        int ans = 0;
        for(int i =0;i < n;i++){
            ans = max(ans,f(i,nums,t));
        }
        return ans;
    }
};
