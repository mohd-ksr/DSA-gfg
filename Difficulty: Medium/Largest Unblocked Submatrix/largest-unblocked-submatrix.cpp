class Solution {
  public:
    int largestArea(int n, int m, vector<vector<int>> &arr) {
        int k = arr.size();
        if(k==0)return n*m;
        vector<int>r(k);
        vector<int>c(k);
        for(int i=0; i<k; i++){
            r[i]=arr[i][0];
            c[i]=arr[i][1];
        }
        sort(r.begin(), r.end());
        sort(c.begin(), c.end());
        int h = r[0]-1;
        int w = c[0]-1;
        for(int i=1; i<k; i++){
            h = max(h, r[i]-r[i-1]-1);
            w = max(w, c[i]-c[i-1]-1);
        }
        h = max(h, n-r[k-1]);
        w = max(w, m-c[k-1]);
        return h*w;
    }
};