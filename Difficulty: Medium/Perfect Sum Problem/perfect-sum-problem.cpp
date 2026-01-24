class Solution {
private:
    int solve(vector<int>& arr, int n, int target,  vector<vector<int>>&dp){
        if(n==0)return (target==0?1:0);
        if(dp[n][target]!=-1)return dp[n][target];
       
        if(arr[n-1]<=target){
            return dp[n][target]=solve(arr, n-1, target-arr[n-1], dp) + solve(arr, n-1, target, dp);
        }
        
        else return dp[n][target]=solve(arr, n-1, target, dp);
         
    }
public:
    int perfectSum(vector<int>& arr, int target) {
        vector<vector<int>>dp(arr.size()+1, vector<int>(target+1, -1));
        return solve(arr, arr.size(), target, dp);
    }
};