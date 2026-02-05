// User function Template for C++

class Solution {
private:
    bool isPalindrom(string &s, int i, int j){
        while(i<j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
    
    int solve(string &s, int i, int j, vector<vector<int>>&dp){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(isPalindrom(s, i, j))return dp[i][j]=0;
        
        int ans = INT_MAX;
        for(int k=i; k<j; k++){
            if(isPalindrom(s, i, k)){
                int right = solve(s, k+1, j, dp);
                ans = min(ans, 1+right);
            }
            
        }
        return dp[i][j]=ans;
    }
public:
    int palPartition(string &s) {
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return solve(s, 0, n-1, dp);
    }
};



