class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> rows,cols;
        map<pair<int,int>, unordered_set<int>> box;

        for(int r=0; r<board.size(); r++){
            for(int c=0; c<board[0].size(); c++){
                if(board[r][c]=='.') continue;

                int rr = r/3;
                int cc = c/3;
                pair<int,int>squareNum = {rr,cc};

                if(rows[r].count(board[r][c]) || cols[c].count(board[r][c]) || 
                    box[squareNum].count(board[r][c])){
                        return false;
                    }
                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                box[squareNum].insert(board[r][c]);
            }
        }
        return true;
    }
};
