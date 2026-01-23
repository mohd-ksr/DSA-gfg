class Solution {
private:
    int solve(int w, vector<int> &val, vector<int> &wt, int n,  vector<vector<int>>&dp){
        if(n<0 || w==0)return 0;
        if(dp[n][w]!=-1)return dp[n][w];
        if(w>=wt[n])return dp[n][w]=max(val[n]+solve(w-wt[n], val, wt, n-1, dp), solve(w, val, wt, n-1, dp));
        else return dp[n][w]=solve(w, val, wt, n-1, dp);
    }
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<vector<int>>dp(val.size()+1, vector<int>(W+1, -1));
        return solve(W, val, wt, val.size()-1, dp);
    }
};