class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<vector<int>>ans;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int s = q.size();
            vector<int>level;
            while(s--){
                int ind = q.front();q.pop();
                level.push_back(arr[ind]);
                int left = 2*ind + 1;
                int right = 2*ind + 2;
                if(left<n)q.push(left);
                if(right<n)q.push(right);
            }
            sort(level.begin(), level.end());
            ans.push_back(level);
        }
        return ans;
    }
};
