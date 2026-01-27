class Solution {
private:
    int solve(int n, vector<int>& val, vector<int>& wt, int capacity,  vector<vector<int>>&dp){
        if(capacity==0 || n==0)return 0;
        if(dp[n-1][capacity]!=-1)return dp[n-1][capacity];
        if(wt[n-1]<=capacity){
            return dp[n-1][capacity]=max(val[n-1]+solve(n, val, wt, capacity-wt[n-1], dp), solve(n-1, val, wt, capacity, dp));
        }
        else return dp[n-1][capacity]=solve(n-1, val, wt, capacity, dp);
    }
public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<vector<int>>dp(val.size()+1, vector<int>(capacity+1, -1));
        return solve(val.size(), val, wt, capacity, dp);
    }
};