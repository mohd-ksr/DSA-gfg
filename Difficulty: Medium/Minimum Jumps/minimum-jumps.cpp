class Solution {
private:
    int findMaxInd(vector<int>& arr, int &s, int &e, int &n){
        if(s==e)return s;
        int maxInd=-1;
        int maxFar = 0;
        for(int i=s; i<=e; i++){
            if(maxFar < (i + arr[i])){
                maxFar = i + arr[i];
                maxInd = i;
            }
        }
        return maxInd;
    }
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        int ind = 0;
        int ans = 0;
        while(ind<n){
            if(arr[ind]>=(n-ind-1)){
                ans++;
                break;
            }
            if(arr[ind]==0){
                ans = -1;
                break;
            }
            int s = ind+1, e = ind+arr[ind];
            ind = findMaxInd(arr,s,e,n);
            ans++;
        }
        return ans;
    }
};

// Time Complexity O(n)
// Space Complexity O(1);

