class Solution {
public:
    void f(int i, vector<int> nums, int target,int sum, vector<int>& path, vector<vector<int>>& ans){
        //base case
        if(i >= nums.size() || sum > target){
            return;
        }
        // got the ans
        if(sum == target){
            //path.push_back(nums[i]);
            ans.push_back(path);
            return;
        }
        //take
        path.push_back(nums[i]);
        f(i, nums, target,sum+nums[i],path, ans);
        path.pop_back();
        

        //not take
        f(i+1,nums, target,sum,path,ans);
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        f(0, nums,target,0,path,ans);
        return ans;
    }
};
