class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
         int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st; // stores indices

    // Traverse twice (simulate circular)
    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] <= arr[i % n]) {
            st.pop();
        }
        if (i < n) { // only store results in first pass
            if (!st.empty()) ans[i] = arr[st.top()];
        }
        st.push(i % n);
    }

    return ans;
        
    }
};