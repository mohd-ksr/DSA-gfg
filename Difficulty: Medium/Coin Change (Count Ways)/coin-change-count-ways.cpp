class Solution {
private:
    int dfs(vector<int>& coins, int n, int sum,  vector<vector<int>>&dp){
        if(sum==0)return 1;
        if(sum<0 || n==0)return 0;
        if(dp[n-1][sum]!=-1)return dp[n-1][sum];
        return dp[n-1][sum]=dfs(coins, n, sum-coins[n-1],dp)+dfs(coins, n-1, sum, dp);
    }
public:
    int count(vector<int>& coins, int sum) {
        vector<vector<int>>dp(coins.size(), vector<int>(sum+1,-1));
        return dfs(coins, coins.size(), sum,dp);
    }
};

















