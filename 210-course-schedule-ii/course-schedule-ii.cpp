class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> degre(n,0);
        vector<vector<int>> adj(n);
        for(auto node : prerequisites){
            int u=node[0];
            int v=node[1];
            adj[v].push_back(u);
            degre[u]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(degre[i]==0) q.push(i);
        }
        while(!q.empty()){
            int curr=q.front();
            ans.push_back(curr);
            q.pop();
            for(int v : adj[curr]){
                degre[v]--;
                if(degre[v]==0){
                    q.push(v);
                }
            }
        }
        if(ans.size()<n) return {};
        return ans;
    }
};