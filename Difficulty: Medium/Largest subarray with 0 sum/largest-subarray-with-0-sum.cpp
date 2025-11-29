/*You are required to complete this function*/

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n=arr.size();
        // int maxi=0;
        // for(int i=0; i<n; i++){
        //     int sum=0;
        //     for(int j=i; j<n;j++){
        //         sum+=arr[j];
        //         if(sum==0 && maxi<(j-i+1)) maxi=j-i+1;
        //     }
        // }
        // return maxi;
        
        // int sum=0;
        // int ans=0;
        // unordered_map<int,int>map;
        // for(int i=0; i<n;i++){
        //     sum+=arr[i];
        //     if(sum==0)ans=max(ans,i+1);
        //     if(map.find(sum)!=map.end()){
        //         ans=max(ans,i-map[sum]);
        //     }
        //     else map[sum]=i;
        // }
        // return ans;
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






