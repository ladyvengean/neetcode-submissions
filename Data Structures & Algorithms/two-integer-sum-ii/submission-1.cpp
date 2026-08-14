class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i=0;
        int j = n-1;
        while(i < j){
            int cur = numbers[i] + numbers[j];
            if(cur > target){
                j--;
            }
            else if(cur < target){
                i++;
            }
            else{
                return {i+1,j+1};
            }
        }
        return {};
    }
};
