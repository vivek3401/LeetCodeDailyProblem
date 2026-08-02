class Solution {
public:
    int solve(int i,int j,vector<int> &nums,vector<vector<int>> &dp){

        if(i==j) return nums[j];
        if(dp[i][j]!=-1) return dp[i][j];
        int left=nums[i]-solve(i+1,j,nums,dp);
        int right=nums[j]-solve(i,j-1,nums,dp);
        return dp[i][j]=max(left,right);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return solve(0,n-1,piles,dp)>=0;
    }
};