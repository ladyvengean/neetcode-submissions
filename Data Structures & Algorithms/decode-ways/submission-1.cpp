class Solution {
public:
    int f(int i, vector<int>& t, string& s){
        //base case1
        if(i == s.size()){
            return 1;
        }
        
        //base case2
        if(s[i] == '0') return 0;
        if(t[i] != -1){
            return t[i];
        }
        //take as single or double
        //single
        int ways = f(i+1,t,s);

        //two digit
        if((i+1) < s.size()){
            int twodig = (s[i] - '0')* 10 + (s[i+1] - '0');
            if(twodig >= 10 && twodig <= 26){
                ways += f(i+2,t,s);
            }
        }
        t[i] = ways;
        return t[i];
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> t(n,-1);
        return f(0,t,s);

    }
};
