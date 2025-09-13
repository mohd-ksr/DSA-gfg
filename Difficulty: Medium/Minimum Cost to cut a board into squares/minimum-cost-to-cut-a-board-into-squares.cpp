class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        sort(x.rbegin(), x.rend()); // sort descending
        sort(y.rbegin(), y.rend());
    
        int i = 0, j = 0;
        int hzSegments = 1, vtSegments = 1;
        long long cost = 0;
    
        while (i < x.size() && j < y.size()) {
            if (x[i] >= y[j]) {
                cost += (long long)x[i] * hzSegments;
                vtSegments++;
                i++;
            } else {
                cost += (long long)y[j] * vtSegments;
                hzSegments++;
                j++;
            }
        }
    
        while (i < x.size()) {
            cost += (long long)x[i] * hzSegments;
            i++;
        }
        while (j < y.size()) {
            cost += (long long)y[j] * vtSegments;
            j++;
        }
    
        return cost;
        
    }
};
