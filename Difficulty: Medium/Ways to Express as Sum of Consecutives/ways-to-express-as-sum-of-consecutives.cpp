class Solution {
private:
    long long getA(long long k, int n){
        return (((n<<1)/k)-k+1)/2;
    }
    long long getSum(long long a, long long k){
        return (k*(2*a+k-1))/2;
    }
  public:
    int getCount(int n) {
        // code here
        long long ans = 0;
        for(long long k=2; (k*(k+1))/2<=n; k++){
            long long a = getA(k, n);
            long long windowSum = getSum(a, k);
            if (windowSum==n)ans++;
        }
        return ans;
        
    }
};