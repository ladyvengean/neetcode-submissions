class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> mh;
        for(auto it: nums){
            mh.push(it);
            if(mh.size() > k){
                mh.pop();
            }
        }
        return mh.top();
    }
};
