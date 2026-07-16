class Solution {
private:
    int n;
    int sum;
    vector<vector<int>>dp;
    int solve(int dc, int tempSum){
        if(dc == n){
            return tempSum == sum;
        }
        if(dp[dc][tempSum]!=-1)return dp[dc][tempSum];
        int ans = 0;
        for(int i=0; i<10; i++){
            if(i==0){
                if(dc!=0)ans+=solve(dc+1, tempSum+i);
                else continue;
                
            }
            else ans+=solve(dc+1, tempSum+i);
        }
        return dp[dc][tempSum] = ans;
    }
public:
    int countWays(int n, int sum) {
        this->n = n;
        this->sum = sum;
        dp.resize(n+1, vector<int>(82, -1));
        int ans = solve(0, 0);
        return ans==0? -1:ans;
        
    }
};