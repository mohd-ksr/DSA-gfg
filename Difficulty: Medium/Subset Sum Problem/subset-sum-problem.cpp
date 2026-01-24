class Solution {
private:    
    bool solve(vector<int>& arr, int n, int sum, vector<vector<int>>&dp){
        if(sum==0)return true;
        if(n<0)return false;
        if(dp[n][sum]!=-1)return dp[n][sum];
        if(arr[n]<=sum)return dp[n][sum]=solve(arr, n-1, sum-arr[n], dp) || solve(arr, n-1, sum, dp);
        else return dp[n][sum]=solve(arr, n-1, sum, dp);
    }
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        vector<vector<int>>dp(arr.size()+1, vector<int>(sum+1, -1));
        return solve(arr, arr.size()-1, sum, dp);
    }
};