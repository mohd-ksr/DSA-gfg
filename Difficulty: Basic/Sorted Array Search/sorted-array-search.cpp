class Solution {
  public:
    bool searchInSorted(vector<int>& arr, int k) {
        // code here
        int s=0, e = arr.size()-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid]==k)return true;
            else if(arr[mid]>k)e=mid-1;
            else s=mid+1;
        }
        return false;
    }
};
//Time complexity O(logn)