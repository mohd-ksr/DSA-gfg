class Solution {
  public:
    string largestSwap(string &s) {
        int n = s.size();
        vector<int> last(10, -1);
        
        for (int i = 0; i < n; i++) {
            last[s[i] - '0'] = i;
        }
        
        for (int i = 0; i < n; i++) {
            int curr = s[i] - '0';
            for (int d = 9; d > curr; d--) {
                if (last[d] > i) { 
                    swap(s[i], s[last[d]]);
                    return s; // only one swap allowed
                }
            }
        }
        
        return s;
        
    }
};