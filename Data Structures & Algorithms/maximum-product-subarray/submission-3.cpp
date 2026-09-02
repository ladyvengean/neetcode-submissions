class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi  = INT_MIN;
        int suffix = 0;
        int prefix = 0;
        int n = nums.size();
        for(int i=0;i < nums.size();i++){
        
            if(prefix == 0) prefix= 1;
            if(suffix == 0) suffix = 1;

            prefix *= nums[i];
            suffix *= nums[n-i-1];
            maxi = max(maxi, max(prefix,suffix));
        }
        return maxi;
    }
};
