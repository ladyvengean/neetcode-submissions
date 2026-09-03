class Solution {
public:
    bool f(int i, string s, unordered_set<string>& dict, vector<int>& t){
        if(i == s.size()) return true;
        if(t[i] != -1){
            return t[i];
        }
        for(int j=i;j< s.size();j++){
            string s1 = s.substr(i, j-i+1);
            if(dict.count(s1)){
                if(f(j+1,s,dict, t)){
                    t[i] = true;
                    return true;
                }
            }
        }
        t[i] = false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> t(s.size(), -1);
        return f(0,s,dict,t);
    }
};
