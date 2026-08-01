class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &dp , vector<int> &nums){
        if(i==j){
            return nums[i];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int left=nums[i]-solve(i+1,j,dp,nums);
        int right=nums[j]-solve(i,j-1,dp,nums);
        return dp[i][j]=max(left,right);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return solve(0,n-1,dp,nums)>=0;
        
    }
};