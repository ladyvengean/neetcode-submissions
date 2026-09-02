class Solution {
public:
    int expand(string s, int i, int j){
        int cnt = 0;
        while(i >= 0 && j < s.size() && s[i]== s[j]){
            cnt++;
            i--;
            j++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int final = 0;
        for(int i =0;i < s.size();i++){
            int s1 = expand(s,i,i);
            int s2 = expand(s,i,i+1);
            final += s1+s2;

        }
        return final;
    }
};
