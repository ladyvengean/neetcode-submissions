class Solution {
public:
    void f(int i, string& digits, string& path, vector<string>& ans, vector<string>& mapping) {
        if (i == digits.size()) {
            ans.push_back(path);
            return;
        }

        int digit = digits[i] - '0';        
        string letters = mapping[digit];     

        for (int j = 0; j < letters.size(); j++) {   
            path.push_back(letters[j]);
            f(i + 1, digits, path, ans, mapping);      
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;   
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string path;
        f(0, digits, path, ans, mapping);
        return ans;
    }
};
