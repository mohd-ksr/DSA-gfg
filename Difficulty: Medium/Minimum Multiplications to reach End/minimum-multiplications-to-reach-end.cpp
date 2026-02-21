// User function Template for C++

class Solution {
private:
    int mod = 100000;
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start==end)return 0;
        queue<pair<int, int>>q;
        q.push({start, 0});
        vector<int>dist(100000, 1e9);
        dist[start]=0;
        while(!q.empty()){
            auto [node, s] = q.front();q.pop();
            for(auto &a:arr){
                int v = (a%mod * node%mod)%mod;
                if(s+1<dist[v]){
                    dist[v]=s+1;
                    if(v==end)return s+1;
                    q.push({v, dist[v]});
                }
            }
            
        }
        return -1;
    }
};
