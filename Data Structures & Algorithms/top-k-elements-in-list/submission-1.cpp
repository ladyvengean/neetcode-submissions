class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for (auto it : mp) {
            int freq = it.second;
            int num = it.first;
            minHeap.push({freq, num});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        while (!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return res;
    }
};
