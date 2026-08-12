class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i< n;i++){
            mp[nums[i]]++;
        }
        bool ans = false;
        for(auto it: mp){
            int item = it.first;
            int freq = it.second;
            if(freq > 1){
                ans = true;
                break;
            }
        }
        return ans;
        
    }
};