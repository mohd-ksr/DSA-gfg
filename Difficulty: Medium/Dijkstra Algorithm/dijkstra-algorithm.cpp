class Solution {
  public:
  const int inf = 1e9+7;
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>>adjList(V);
        for(auto &e:edges){
            adjList[e[0]].push_back({e[2], e[1]});
            adjList[e[1]].push_back({e[2], e[0]});
        }
        
        vector<int>dist(V, inf);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
        pq.push({0, src});
        dist[src]=0;
        while(!pq.empty()){
            auto [d, u] = pq.top(); pq.pop();
            
            if(d>dist[u])continue;
            
            for(auto [w, v]:adjList[u]){
                if(dist[u]+w < dist[v]){
                    dist[v]=dist[u]+w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};