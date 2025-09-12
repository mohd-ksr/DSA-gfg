// class Solution {
// public:
//     int getMinDiff(vector<int> &arr, int k) {
//         int n = arr.size();
//         if(n==1)return 0;
//         int ans = arr[n-1]-arr[0];
//         sort(arr.begin(), arr.end());
//         for(int i=1; i<n; i++){
//             if(arr[i]-k < 0)continue;
//             int mini = min(arr[0]+k, arr[i]-k);
//             int maxi = max(arr[i-1]+k, arr[n-1]-k);
//             ans = min(ans, maxi - mini);
//         }
//         return ans;
//     }
// };

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        if (n == 1) return 0;
        
        sort(arr.begin(), arr.end());
        
        int ans = arr[n-1] - arr[0]; // initial difference
        
        for (int i = 1; i < n; i++) {
            if (arr[i] - k < 0) continue; // skip invalid (negative heights)
            
            int minVal = min(arr[0] + k, arr[i] - k);
            int maxVal = max(arr[n-1] - k, arr[i-1] + k);
            
            ans = min(ans, maxVal - minVal);
        }
        
        return ans;
    }
};
