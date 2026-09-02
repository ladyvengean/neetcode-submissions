class Solution {
public:
    string expand(string s, int i, int j){
        while(i >= 0 && j < s.size() && s[i] == s[j]){
            i--;
            j++;
        }
        return s.substr(i+1,j-i-1);
    }
    string longestPalindrome(string s) {
        string ans = "";
        for(int i =0;i < s.size();i++){
            string s1 = expand(s,i,i);
            string s2 = expand(s,i,i+1);
            if(s1.size() > ans.size()){
                ans = s1;
            }
            if(s2.size() > ans.size()){
                ans = s2;
            }
        }
        return ans;
    }
};
