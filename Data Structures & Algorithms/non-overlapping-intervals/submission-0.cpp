class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int cnt=0;
        for(auto interval : intervals){
            if(res.empty() || res.back()[1] <= interval[0]){
                res.push_back(interval);
            }
            else{
                res.back()[1] = min(interval[1], res.back()[1]);
                cnt++;
            }
        }
        return cnt;
    }
};
