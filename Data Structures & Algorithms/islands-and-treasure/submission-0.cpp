class Solution {
public:
    int INF = 2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows= grid.size();
        int cols= grid[0].size();
        queue<pair<int,int>>q;

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c]==0) q.push({r,c});
            }
        }

        int dir[4][2]= {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty()){
            auto node= q.front();
            q.pop();
            int row= node.first;
            int col= node.second;

            for(int i=0; i<4; i++){
                int nr= row+ dir[i][0];
                int nc= col+dir[i][1];

                if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && 
                    grid[nr][nc]!=-1 && grid[nr][nc]!=0 && grid[nr][nc]==INF){
                        grid[nr][nc]= 1+grid[row][col];
                        q.push({nr,nc});
                    }
            }
        }
    }
};
