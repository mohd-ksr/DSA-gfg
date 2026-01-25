class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int sum = 0;
        for(auto &a:arr)sum+=a;
        
        if(sum<diff || (sum+diff)%2!=0)return 0;
        
        int target = (sum+diff)/2;
        
        vector<int>dp(target+1, 0);
        dp[0]=1;
        
        for(auto &x:arr){
            for(int j=target; j>=x; j--){
                dp[j] += dp[j-x];
            }
        }
        
        return dp[target];
    }
};