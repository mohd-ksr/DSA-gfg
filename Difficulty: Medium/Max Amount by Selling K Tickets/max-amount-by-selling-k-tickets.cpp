class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        // code here
        const int mod = 1e9+7;
        int n = arr.size();
        // unordered_map<int, int>mapp;
        priority_queue<int>pq;
        for(int i=0; i<n; i++){
            pq.push(arr[i]);
        }
        int ans = 0;
        while(k!=0){
            auto el = pq.top();
            if(el<0)return ans;
            pq.pop();
            ans = (ans+el)%mod;
            k--;
            el--;
            pq.push(el);
        }
        return ans;
    }
};