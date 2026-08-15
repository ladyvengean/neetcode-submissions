class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i=0;
        int j = 0;
        int len = 0;
        unordered_map<char, int> mp;
        while(j < n){
            mp[s[j]]++;
            if(mp.size() == (j-i+1)){
                len = max(len, (j-i+1));
                j++;
            }
            else if(mp.size() < (j-i+1)){
                //means characters have started to duplicate
                while(mp.size() < (j-i+1)){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return len;
    }
};
