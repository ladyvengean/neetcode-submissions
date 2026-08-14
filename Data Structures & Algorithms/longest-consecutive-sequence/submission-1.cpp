class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 1;
        if(n == 0){
            return 0;
        }
        unordered_set<int> s(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            if(!s.count(nums[i] -1)){
                int len = 1;
                while(s.count(nums[i] + len)){
                    len++;
                }
                longest = max(longest,len);
            }
        }
        return longest;
    }
};
