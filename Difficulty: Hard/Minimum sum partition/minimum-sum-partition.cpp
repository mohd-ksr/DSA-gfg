class Solution {

  public:
    int minDifference(vector<int>& arr) {
        int sum = 0;
        for(int &a:arr)sum+=a;
        
        int halfSum = sum/2;
        int n = arr.size();
        vector<vector<bool>>dp(n+1, vector<bool>(halfSum+1, false));
        
        for(int i=0; i<=n; i++){
            dp[i][0]=true;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=halfSum; j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        vector<int>cand;
        for(int j=0; j<=halfSum; j++){
            if(dp[n][j])cand.push_back(j);
        }
        
        int mini = INT_MAX;
        
        for(auto &c:cand){
            mini = min(mini, sum-2*c);
        }
        
        return mini;
        
    }
};





