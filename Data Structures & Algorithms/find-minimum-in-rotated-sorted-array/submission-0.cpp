class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int i =0;
        int j = n-1;
        int ans = 0;
        while(i <= j){
            int mid = i + (j-i)/2;
            int prev = nums[(mid-1 + n)% n];
            int next = nums[(mid+1) % n];
            if(nums[i] <= nums[j]){
                return nums[i];
            }
            else if(nums[mid] <= prev && nums[mid] <= next){
                return nums[mid];
            }
            else if(nums[i] <= nums[mid]){
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
        return -1;
    
    }
};
