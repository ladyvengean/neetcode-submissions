class Solution {
public:
    void f(vector<int>& nums, vector<bool>& vis, vector<int>& path, vector<vector<int>>& ans){
        //base case
        if(path.size() == nums.size()){
            ans.push_back(path);
            return;
        }
        for(int j = 0;j < nums.size();j++){
            if(vis[j]){
                continue;
            }
            //order matters
            vis[j] = true;
            path.push_back(nums[j]);
            f(nums,vis,path,ans);\
            //backtrack
            path.pop_back();
            vis[j] = false;

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> ans;
        vector<bool> vis(nums.size(), false);
        f(nums,vis,path,ans);
        return ans;
    }
};
