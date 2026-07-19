class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n = arr.size();
        vector<int> inc(n), dec(n);

        inc[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] <= arr[i + 1])
                inc[i] = inc[i + 1];
            else
                inc[i] = i;
        }
        dec[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= arr[i + 1])
                dec[i] = dec[i + 1];
            else
                dec[i] = i;
        }

        vector<bool> ans;

        for (auto &query : queries) {
            int l = query[0], r = query[1];
            int peak = inc[l];

            if (dec[peak] >= r)
                ans.push_back(true);
            else
                ans.push_back(false);
        }

        return ans;
    }
};