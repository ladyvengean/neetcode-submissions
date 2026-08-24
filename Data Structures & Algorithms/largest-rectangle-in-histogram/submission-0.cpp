class Solution {
public:
    vector<int> ngr(vector<int>& heights){
        vector<int> right;
        stack<pair<int,int>> st;
        int n = heights.size();
        for(int i = n - 1; i >= 0; i--){
            if(st.empty()){
                right.push_back(n); 
            }
            else if(st.top().first < heights[i]){
                right.push_back(st.top().second);
            }
            else {
                while(!st.empty() && st.top().first >= heights[i]){
                    st.pop();
                }
                if(st.empty()){
                    right.push_back(n);
                }
                else {
                    right.push_back(st.top().second);
                }
            }
            st.push({heights[i], i});
        }
        reverse(right.begin(), right.end());
        return right;
    }

    vector<int> ngl(vector<int>& heights){
        vector<int> left;
        stack<pair<int,int>> st;
        int n = heights.size();
        for(int i = 0; i < n; i++){
            if(st.empty()){
                left.push_back(-1);
            }
            else if(st.top().first < heights[i]){
                left.push_back(st.top().second);
            }
            else {
                while(!st.empty() && st.top().first >= heights[i]){
                    st.pop();
                }
                if(st.empty()){
                    left.push_back(-1);
                }
                else {
                    left.push_back(st.top().second);
                }
            }
            st.push({heights[i], i});
        }
        return left;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> right = ngr(heights);
        vector<int> left = ngl(heights);

        vector<int> width;
        for(int i = 0; i < heights.size(); i++){
            width.push_back(right[i] - left[i] - 1); 
        }

        vector<int> area;
        for(int i = 0 ; i < heights.size(); i++){
            area.push_back(heights[i] * width[i]);
        }

        return *max_element(area.begin(), area.end());
    }
};
