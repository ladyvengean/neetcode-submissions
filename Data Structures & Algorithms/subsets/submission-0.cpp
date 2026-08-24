class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res={{}};
        for(auto num : nums){
            int size = res.size();
            for(int i=0;i< size;i++){
                vector<int> cur = res[i];
                cur.push_back(num);
                res.push_back(cur);
            }
        }
        return res;
    }
};
