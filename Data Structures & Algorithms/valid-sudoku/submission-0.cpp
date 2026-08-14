class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<unordered_set<char>> s1(9);
        vector<unordered_set<char>> s2(9);
        vector<unordered_set<char>> s3(9);
        for(int i=0;i < 9;i++){
            for(int j=0;j < 9;j++){
                char num = board[i][j];
                if(num == '.') continue;
                int b = (i/3) * 3 + (j/3);
                if(s1[i].count(num) || s2[j].count(num) || s3[b].count(num)){
                    return false;
                }
                s1[i].insert(num);
                s2[j].insert(num);
                s3[b].insert(num);
            }
        }
        return true;
    }
};
