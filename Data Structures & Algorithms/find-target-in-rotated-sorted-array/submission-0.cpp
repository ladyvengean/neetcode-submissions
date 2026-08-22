class Solution {
public:
    int ind(vector<int>& nums,int target){
        int n = nums.size();
        int l = 0;
        int r = n-1;
        if(n == 1){
            return 0;
        }
        while(l <= r){
            int mid = l + (r-l)/2;
            int prev = nums[(mid + n - 1) % n];
            int next = nums[(mid + 1) % n];
            if(nums[l] <= nums[r]){
                return l;
            }
            if(nums[mid] <= prev && nums[mid] <= next){
                return mid;
            }
            else if(nums[l] <= nums[mid]){
                l = mid+1;
            }
            else{
                r = mid-1;
            }

        }
        return -1;
    }
    int bs(int l, int r, vector<int>& nums,int target){
        int n = nums.size();
        // int l = 0;
        // int r = n-1;
        while(l <=r){
            int mid = l + (r-l)/2;
            if(nums[mid] ==  target){
                return mid;
            }
            else if(nums[mid] < target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        //first index we need to find;
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int cut = ind(nums,target);
        int f = bs(l,cut-1,nums,target);
        if(f != -1){
            return f;
        }
        return bs(cut,r,nums,target);

    }
};
