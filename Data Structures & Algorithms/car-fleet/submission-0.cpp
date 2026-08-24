class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
       vector<pair<int,int>> pairr;
       for(int i=0;i < n;i++){
        pairr.push_back({position[i], speed[i]});
       }
       sort(pairr.begin(), pairr.end());
       vector<double> arr;
       for(auto p : pairr){
        arr.push_back((double)(target- p.first) / p.second);
       }
       int ans = 0;
       double prev = 0;
       for(int i =n-1 ;i >= 0;i--){
        if(arr[i] > prev){
            ans++;
            prev = arr[i];
        }
       }
       return ans;
    }
};
