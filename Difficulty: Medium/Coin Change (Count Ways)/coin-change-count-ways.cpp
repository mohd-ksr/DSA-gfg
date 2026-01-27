class Solution {
private:
    int solve(int ind, vector<int>& coins, int sum,  vector<vector<int>>&dp){
        if(sum==0)return 1;
        if(ind<=0)return 0;
        
        if(dp[ind-1][sum]!=-1)return dp[ind-1][sum];
        if(coins[ind-1]<=sum){
            return dp[ind-1][sum]=solve(ind, coins, sum-coins[ind-1], dp)+solve(ind-1, coins, sum, dp);
        }
        else return dp[ind-1][sum]=solve(ind-1, coins, sum, dp);
    }
public:
    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));
        return solve(n, coins, sum, dp);
    }
};