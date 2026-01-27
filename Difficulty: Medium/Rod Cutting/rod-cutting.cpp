// User function Template for C++

class Solution {
private:
    int solve(int ind, vector<int> &price, int n, vector<vector<int>>&dp){
        if(n==0 || ind<=0)return 0;
        if(dp[ind-1][n]!=-1)return dp[ind-1][n];
        if(ind<=n){
            return dp[ind-1][n]=max(price[ind-1]+solve(ind, price, n-ind, dp), solve(ind-1, price, n, dp));
        }
        else return dp[ind-1][n]=solve(ind-1, price, n, dp);
        
    }
public:
    int cutRod(vector<int> &price) {
        // code here
        vector<vector<int>>dp(price.size()+1,vector<int>(price.size()+1, -1));
        int n = price.size();
        return solve(n,price,n, dp);
    }
};