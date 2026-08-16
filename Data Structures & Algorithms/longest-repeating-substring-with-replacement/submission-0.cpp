class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i=0;
        int j =0;
        vector<int> hash(26,0);
        int maxl = 0;
        int maxf = 0;
        while(j < n){
            hash[s[j]- 'A']++;
            maxf = max(maxf,hash[s[j]-'A']);
            if((j-i+1) - maxf > k){
                hash[s[i] - 'A']--;
                i++;
            }
            if((j-i+1) - maxf <= k){
                maxl = max(maxl, (j-i+1));
                j++;
            }
        }
        return maxl;
    }
};
