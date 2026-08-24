class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //ngr
        //return index
        stack<pair<int,int>> st;
        int n = temperatures.size();
        vector<int> res; 
        for(int i= n-1;i>= 0;i--){
            if(st.size() == 0){
                res.push_back(0);
            }
            else if(st.size() > 0 && st.top().first > temperatures[i]){
                res.push_back(st.top().second - i);
            }
            else if(st.size() > 0 && st.top().first <= temperatures[i]){
                while(st.size() > 0 && st.top().first <= temperatures[i]){
                    st.pop();
                }
                if(st.size() == 0){
                    res.push_back(0);
                }
                else{
                    res.push_back(st.top().second - i);
                }
            }
            st.push({temperatures[i],i});
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
