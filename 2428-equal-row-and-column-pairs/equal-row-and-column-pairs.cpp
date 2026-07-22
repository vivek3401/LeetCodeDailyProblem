class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        map<vector<int>,int> mp;
        for(int i=0;i<n;i++){
            mp[grid[i]]++;
        }
        int ans=0;
        for(int j=0;j<n;j++){
            vector<int> cols;
            for(int i=0;i<n;i++){
                cols.push_back(grid[i][j]);
            }
            ans+=mp[cols];
        }
        return ans;
    }
};