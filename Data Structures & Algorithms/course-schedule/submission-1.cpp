class Solution {
private:
    bool dfs(int u, int parent, unordered_map<int,bool> &visited, unordered_map<int,bool> &dfs_vis, unordered_map<int, list<int>>&adj){

        dfs_vis[u]= true;
        visited[u]=true;
        bool ans=true;
        for(auto v: adj[u]){
            if(!visited[v]){
                ans = dfs(v,u,visited,dfs_vis, adj);
            }
            if(visited[v] && dfs_vis[v]){
                return false;
            }
        }
        dfs_vis[u]=false;
        return ans;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;

        for(int i=0; i<prerequisites.size(); i++){
            int u= prerequisites[i][0];
            int v= prerequisites[i][1];
            adj[u].push_back(v);
        }

        unordered_map<int,bool> dfs_vis;
        unordered_map<int,bool> visited;
        bool ans=true;
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                ans = dfs(i,-1,visited,dfs_vis,adj);
            }
            if(!ans) return false;
        }
        return ans;
    }
};
