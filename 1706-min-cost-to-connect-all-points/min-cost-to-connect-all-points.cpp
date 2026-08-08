class Solution {
public:
    int manDis(vector<vector<int>>& points,int p1,int p2){
        return abs(points[p1][0]-points[p2][0])+abs(points[p1][1]-points[p2][1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int minCost=0;
        int n=points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<bool> vis(n,false);
        pq.push({0,0});
        while(!pq.empty()){
            int u=pq.top().second;
            int w=pq.top().first;
            pq.pop();
            if(vis[u]) continue;
            vis[u]=true;
            minCost+=w;
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    int dis=manDis(points,u,i);
                    pq.push({dis,i});
                }
            }
        }
        return minCost;
    }
};