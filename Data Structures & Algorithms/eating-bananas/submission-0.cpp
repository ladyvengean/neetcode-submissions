class Solution {
public:
    bool isValid(vector<int>& piles, int h, int mid){
        int sum=0;
        for(int i =0 ; i< piles.size();i++){
            sum += (piles[i] + mid-1)/mid;
        }
        if(sum <= h){
            return true;
        }
        return false;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int i = 1;
        int j = *max_element(piles.begin(),piles.end());
        int ans = 0;
        while(i <= j){
            int mid = i + (j-i)/2;
            if(isValid(piles,h, mid)){
                ans = mid;
                j = mid-1;
            }
            else{
                i = mid+1;
            }
        }
        return ans;
    }
};
