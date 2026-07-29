class Solution {
private:
    void bfs(vector<vector<char>>& grid, int r, int c){
        queue<pair<int,int>> q;
        grid[r][c]= '0';
        q.push({r,c});
        int dir[4][2]= {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty()){
            auto node= q.front();
            q.pop();
            int rows= node.first;
            int cols= node.second;
            for(int i=0; i<4; i++){
                int nr= rows+dir[i][0];
                int nc= cols+dir[i][1];
                if(nr >=0 && nc>=0 && nr < grid.size() && nc <grid[0].size()
                    && grid[nr][nc]=='1'){
                        grid[nr][nc]='0';
                        q.push({nr,nc});
                    }
            }
        }

    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int rows= grid.size();
        int cols= grid[0].size();
        int islands=0;

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c]=='1'){
                    bfs(grid,r,c);
                    islands++;
                }
            }
        }
        return islands;
    }
};