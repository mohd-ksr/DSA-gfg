class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int maxi = INT_MIN;
        int s_maxi = INT_MIN;
        for(int n:arr){
            if(n>maxi){
                s_maxi = maxi;
                maxi = n;
            }
            else if(n<maxi && n>s_maxi){
                s_maxi = n;
            }
        }
        return s_maxi;
    }
};