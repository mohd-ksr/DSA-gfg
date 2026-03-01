/*You are required to complete this function*/

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int sum = 0;
        unordered_map<int, int>mapp;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(sum==0)ans=max(ans,i+1);
            if(mapp.find(sum)!=mapp.end())ans=max(ans,i-mapp[sum]);
            else mapp[sum]=i;
        }
        return ans;
    }
    
};






