class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows= board.size();
        int cols= board[0].size();

        queue<pair<int,int>>q;
        vector<vector<bool>> converted(rows, vector<bool>(cols, false));

        for(int r=1; r<rows-1; r++){
            for(int c=1; c<cols-1; c++){
                if(board[r][c]=='O'){
                    board[r][c]='X';
                    converted[r][c]=true;
                }
            }
        }

        for(int r=0; r<rows; r++){
            if(board[r][0]=='O') q.push({r,0});
            if(board[r][cols-1]=='O') q.push({r,cols-1});
        }

        for(int c=0; c<cols; c++){
            if(board[0][c]=='O') q.push({0,c});
            if(board[rows-1][c]=='O') q.push({rows-1,c});
        }

        vector<vector<bool>> vis(rows, vector<bool>(cols, false));

        while(!q.empty()){
            auto node= q.front();
            q.pop();
            int row= node.first;
            int col= node.second;
            vector<pair<int,int>> dir ={{-1,0},{1,0},{0,-1},{0,1}};
            for(auto [dr,dc]: dir){
                int nr= row+dr;
                int nc= col+dc;
                if(nr>=0 && nc>=0 && nr<board.size() && nc<board[0].size() &&
                    converted[nr][nc] && !vis[nr][nc] ){
                        board[nr][nc]='O';
                        vis[nr][nc]=true;
                        converted[nr][nc]=false;
                        q.push({nr,nc});
                    }
            }
        }

    }
};
