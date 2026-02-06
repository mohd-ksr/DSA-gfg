class Solution {
private:
    int solve(int n, int k, vector<vector<int>>&dp){
        if(k<=1 || n==1)return k;
        int ans = INT_MAX;
        if(dp[n][k]!=-1)return dp[n][k];
        // for(int i=1; i<=k; i++){
        //     // int temp = 1 + max(solve(n-1, i-1, dp), solve(n,k-i, dp));
        //     int b,nb;
        //     if(dp[n-1][i-1]!=-1){
        //         b=dp[n-1][i-1];
        //     }
        //     else{
        //         b=solve(n-1, i-1, dp);
        //     }
            
        //     if(dp[n][k-i]!=-1){
        //         nb=dp[n][k-i];
        //     }
        //     else{
        //         nb=solve(n, k-i, dp);
        //     }
        //     ans = min(ans, 1+max(b, nb));
        // }
        
        int s = 0, e = k;
        while(s<=e){
            int mid = s+(e-s)/2;
            
            int b = solve(n-1, mid-1, dp);
            int nb = solve(n, k-mid, dp);
            
            if(b<nb){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            
            ans = min(ans, 1+max(b,nb));
        }
        return dp[n][k]=ans;
    }
public:
    int eggDrop(int n, int k) {
       vector<vector<int>>dp(n+1, vector<int>(k+1, -1));
       return solve(n, k, dp);
       
    }
};





















