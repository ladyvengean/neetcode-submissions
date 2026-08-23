class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int,int>>> mh;

        for(auto& point : points){
            int dist = point[0] * point[0] + point[1]*point[1];
            mh.push({dist,{point[0], point[1]}});
            if(mh.size() > k){
                mh.pop();
            }
        }
        vector<vector<int>> res;
        while(!mh.empty()){
            res.push_back({mh.top().second.first, mh.top().second.second});
            mh.pop();
        }
        return res;
    }
};
