class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i =0;
        int n = heights.size();
        int j = n-1;
        int res = 0;
        while(i < j){
            int cur = min(heights[i], heights[j]) * (j-i);
            res = max(res,cur);
            if(heights[i] <= heights[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return res;
    }
};
