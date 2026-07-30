class Solution {
public:
    int time=0;
    int orangesRotting(vector<vector<int>>& grid) {
        int rows= grid.size();
        int cols= grid[0].size();

        queue<pair<int,int>>q;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c]==2) q.push({r,c});
            }
        }

        while(!q.empty()){
            int size= q.size();

            for(int i=0; i<size; i++){
                auto node= q.front();
                q.pop();

                int rows=node.first;
                int cols=node.second;

                int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
                for(int i=0; i<4; i++){
                    int nr= rows+dir[i][0];
                    int nc= cols+dir[i][1];

                    if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() &&
                        grid[nr][nc]==1){
                            grid[nr][nc]=2;
                            q.push({nr,nc});
                        }
                }
                if(q.empty()) time--;
            }
            time++;
        }

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c]==1) return -1;
            }
        }

        return time;
    }
};
