class Solution {
public:
    void f(int i, vector<int>& nums, int sum, int target, 
           vector<int>& path, vector<vector<int>>& ans) {
        if (sum == target) {
            ans.push_back(path);
            return;
        }
        if (sum > target || i >= nums.size()) {
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j-1]) continue;
            if (sum + nums[j] > target) break;

            path.push_back(nums[j]);
            f(j + 1, nums, sum + nums[j], target, path, ans);  
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        f(0, candidates, 0, target, path, ans);
        return ans;
    }
};