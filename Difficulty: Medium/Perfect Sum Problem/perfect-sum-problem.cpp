class Solution {
  public:
    int perfectSum(vector<int>& arr, int sum) {
        // code here
        vector<int>dp(sum+1, 0);
        dp[0]=1;
        for(auto x:arr){
            for(int j=sum; j>=x; j--){
                dp[j] += dp[j-x];
            }
        }
        return dp[sum];
    }
};