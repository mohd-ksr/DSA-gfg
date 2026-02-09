class Solution {
private:
    const int inf = 1e9+7;
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int, int>>>adj(V);
        for(auto &e:edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        vector<int>dist(V, inf);
        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, src});
        dist[src]=0;
        while(!pq.empty()){
            auto [d, node]=pq.top(); pq.pop();
            if(d>dist[node])continue;
            for(auto [nei, w]:adj[node]){
                if(dist[node]+w < dist[nei]){
                    dist[nei]=dist[node] + w;
                    pq.push({dist[nei], nei});
                }
            }
        }
        return dist;
    }
};