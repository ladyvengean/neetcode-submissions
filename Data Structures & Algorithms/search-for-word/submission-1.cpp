class Solution {
public:
    bool f(int row, int col, int i, vector<vector<char>>& board, string word){
        int rows = board.size();
        int cols = board[0].size();

        //base case
        if(row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != word[i]){
            return false;
        }
        if(i == word.size() - 1){
            return true;
        }
        char temp = board[row][col];
        board[row][col] = '#';
        bool found = f(row+1, col,i+1, board, word) || f(row-1, col,i+1, board, word) || f(row, col+1,i+1, board, word) || f(row, col-1,i+1, board, word);
        board[row][col] = temp;
        return found;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows= board.size();
        int cols = board[0].size();
        for(int i =0;i<rows;i++){
            for(int j=0;j< cols;j++){
                if(f(i,j,0,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};
