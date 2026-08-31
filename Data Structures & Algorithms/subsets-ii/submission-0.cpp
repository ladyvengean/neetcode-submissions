class Solution {
public:
    void f(int i, vector<int>& nums, vector<int>& path, vector<vector<int>>& ans){
        //base case
        ans.push_back(path);
        // if(i >= nums.size()){
        //     ans.push_back(path);
        //     return;
        // }
        for(int j = i;j < nums.size();j++){
            if(j > i && nums[j] == nums[j-1]) continue;

            path.push_back(nums[j]);
            f(j+1, nums,path,ans);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector<vector<int>> ans;
        f(0,nums,path,ans);
        return ans;
    }
};
