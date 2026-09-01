class Solution {
public:
    int f(vector<int>& nums, vector<int>& t,int start,int i){
        if(i == start){
            return nums[start];
        }
        if (i == start + 1) return max(nums[start], nums[i]);
        if(t[i] != -1){
            return t[i];
        }
        t[i] = max(nums[i] + f(nums,t,start,i-2), f(nums,t,start,i-1));
        return t[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> t1(n+1,-1);
        int taken = f(nums,t1, 0, n-2);
        vector<int> t2(n+1,-1);
        int nottaken = f(nums,t2, 1, n-1);
        return max(taken, nottaken);
    }
};
