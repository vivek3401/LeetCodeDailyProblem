class Solution {
public:
    bool dfs(int i,vector<vector<int>> &adj,vector<bool> &vis,vector<bool> &recPath){
        vis[i]=true;
        recPath[i]=true;
        for(int v : adj[i]){
            if(!vis[v]){
                if(dfs(v,adj,vis,recPath)) return true;
             }
             else if(recPath[v]) return true;
        }
        recPath[i]=false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);
        vector<bool> recPath(n,false);
        for(auto node : prerequisites){
            int u=node[0];
            int v=node[1];
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,recPath)) return false;
            }
        }
        return true;
    }
};