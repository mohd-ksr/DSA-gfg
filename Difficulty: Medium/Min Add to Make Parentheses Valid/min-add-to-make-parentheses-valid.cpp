class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        int count=0;int ans=0;
        for(auto &ch:s){
            if(ch=='(')count++;
            else count--;
            if(count<0){
                count=0;
                ans++;
            }
        }
        return abs(count)+ans;
    }
};