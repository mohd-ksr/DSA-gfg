class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        vector<int>mapp(k);
        int ans=0;
        for(auto a:arr){
            int r = a%k;
            ans+=mapp[(k-r)%k];
            mapp[r]++;
        }
        return ans;
        
    }
};