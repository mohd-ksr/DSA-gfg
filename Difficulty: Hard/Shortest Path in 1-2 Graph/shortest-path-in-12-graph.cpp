class Solution {
public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        vector<pair<int, int>>adj[V];
        for(auto e:edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        vector<int>dist(V, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        dist[src] = 0;
        pq.push({0, src});
        while(!pq.empty()){
            auto [d, node] = pq.top(); pq.pop();
            if(d>dist[node])continue;
            for(auto [nei, wt]:adj[node]){
                if(dist[node]+wt < dist[nei]){
                    dist[nei]=dist[node]+wt;
                    pq.push({dist[nei], nei});
                }
            }
        }
        return dist[dest]!=1e9? dist[dest]:-1;
    }
};