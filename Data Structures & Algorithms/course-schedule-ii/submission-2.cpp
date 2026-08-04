class Solution {
private:
    bool check=false;

    void topodfs(int u, unordered_map<int,bool> &visited, unordered_map<int,bool> &vis_dfs, unordered_map<int,list<int>> &adj, stack<int> &s){
        visited[u]=true;
        vis_dfs[u]=true;
        for(auto v:adj[u]){
            if(!visited[v]){
                topodfs(v,visited,vis_dfs,adj,s);
            }
            else if(visited[v] && vis_dfs[v]){
                check=true;
            }
        }
        vis_dfs[u]=false;
        s.push(u);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        unordered_map<int,list<int>> adj;
        for(int i=0; i<prerequisites.size(); i++){
            int u= prerequisites[i][0];
            int v= prerequisites[i][1];
            adj[v].push_back(u);
        }
        unordered_map<int,bool> visited;
        unordered_map<int,bool> vis_dfs;
        stack<int> s;
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                topodfs(i,visited,vis_dfs,adj,s);
            }
        }
        if(check) return {};

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
