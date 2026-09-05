class Solution {
public:
    bool canJump(vector<int>& nums) {
        //at each index just add the nums[i];
        int n = nums.size();
        int next = 0;
        int maxReach = 0;
        for(int i=0;i < n;i++){
            next = i + nums[i];
            if(maxReach < i){
                return false;
            }
            maxReach = max(maxReach, next);
            
        }
        return true;
        
    }
};
