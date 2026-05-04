class Solution {
private:
    string to_binary(int n){
        string str = "";
        while(n){
            str.push_back('0'+(n&1));
            n>>=1;
        }
        return str;
    }
public:
    bool isBinaryPalindrome(int n) {
        // code here
        string str = to_binary(n);
        string rev = str;
        reverse(rev.begin(), rev.end());
        return rev==str;
    }
};