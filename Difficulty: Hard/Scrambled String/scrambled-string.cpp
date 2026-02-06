class Solution {
private:
    unordered_map<string, bool>dp;
    bool solve(string x, string y){
        if(x.compare(y)==0)return true;
        if(x.length()<=1)return false;
        if(dp.find(x+" "+y)!=dp.end())return dp[x+" "+y];
        int n=x.length();
        
        int  ans = false;
        for(int i=1; i<=n-1; i++){
            if((solve(x.substr(0,i), y.substr(n-i, i)) && solve(x.substr(i, n-i), y.substr(0, n-i))) || 
            (solve(x.substr(0,i), y.substr(0,i)) && solve(x.substr(i, n-i), y.substr(i, n-i)))){
                ans = true;
                break;
            }
        }
        return dp[x+" "+y]=ans;
    }
public:
    bool isScramble(string s1, string s2) {
        
        return solve(s1, s2);
        
    }
};
