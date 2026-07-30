class Solution {
public:
    void dfs(int city,vector<bool> &vis,vector<vector<int>> &c,int n){

        vis[city]=true;
        for(int j=0;j<n;j++){
            if(c[city][j]==1 && !vis[j]){
                dfs(j,vis,c,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& c) {
        int n=c.size();
        int m=c[0].size();
        vector<bool> vis(n,false);
        int prov=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,c,n);
                prov++;
                }
            }
        return prov;
    }
};