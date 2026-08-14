class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        int n = strs.size();
        for(int i =0;i < n;i++){
            ans += to_string(strs[i].size());
            ans += '#';
            ans += strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {
        //4#hello5#world
        vector<string> res;
        int i = 0;
        int n = s.size();
        while(i < n){
            int j =i;
            while(s[j] != '#'){
                j++;
            }
            //if its #
            int len = stoi(s.substr(i,j-i));
            string word = s.substr(j+1, len);
            res.push_back(word);
            i = j+1+len;

        }
        return res;


    }
};
