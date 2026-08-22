class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> mh;
        for(int num: stones){
            mh.push(num);
        }
        while(mh.size() > 1){
            int first = mh.top();
            mh.pop();
            int second = mh.top();
            mh.pop();
            if(first > second){
                mh.push(abs(first-second));
            }
        }
        mh.push(0);
        return mh.top();
    }
};
