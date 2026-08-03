class Solution {
private:
    void bfs(queue<pair<int,int>> &q,
    vector<vector<bool>>&visited, vector<vector<int>>& heights){
        while(!q.empty()){
            int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            auto node= q.front();
            q.pop();
            int row= node.first;
            int col=node.second;
            visited[row][col]=true;

            for(int i=0; i<4; i++){
                int nr= row+dir[i][0];
                int nc= col+dir[i][1];
                if(nr>=0 && nc>=0 && nr<heights.size() && nc<heights[0].size()
                    && !visited[nr][nc] && heights[nr][nc]>=heights[row][col]){
                        q.push({nr,nc});
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows= heights.size();
        int cols= heights[0].size();
        vector<vector<bool>> visPac(rows, vector<bool>(cols,false));
        vector<vector<bool>> visAlt(rows, vector<bool>(cols,false));

        queue<pair<int,int>> alt, pac;

        for(int c=0; c<cols; c++){
            pac.push({0,c});
            alt.push({rows-1,c});
        }

        for(int r=0; r<rows; r++){
            pac.push({r,0});
            alt.push({r,cols-1});
        }

        bfs(pac, visPac, heights);
        bfs(alt, visAlt, heights);

        vector<vector<int>> ans;

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(visPac[r][c]&& visAlt[r][c]) ans.push_back({r,c});
            }
        }
        return ans;
    }
};
