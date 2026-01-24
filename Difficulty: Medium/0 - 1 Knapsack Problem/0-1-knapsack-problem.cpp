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
        // vector<vector<int>>dp(val.size()+1, vector<int>(W+1, -1));
        // return solve(W, val, wt, val.size()-1, dp);
        
        int n = val.size();
        vector<vector<int>>dp(n+1, vector<int>(W+1));
        
        // Initialization
        for(int i=0; i<=n; i++){
            dp[i][0]=0;
        }
        for(int j=0; j<=W; j++){
            dp[0][j]=0;
        }
        
        // Filling
        for(int i=1; i<=n; i++){
            for(int j=1; j<=W; j++){
                if(wt[i-1]<=j){
                    dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][W];
    }
};









