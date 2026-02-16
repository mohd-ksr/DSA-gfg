class Solution {
public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        vector<vector<int>>adj(V);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int>dist(V, 1e9);
        dist[src]=0;
        queue<pair<int, int>>q;
        q.push({src, 0});
        
        while(!q.empty()){
            auto [node, d] = q.front(); q.pop();
            
            if(d > dist[node])continue;
            for(auto v:adj[node]){
                if(dist[node]+1 < dist[v]){
                    dist[v] = dist[node]+1;
                    q.push({v, dist[v]});
                }
            }
        }
        
        for(auto &d:dist)if(d==1e9)d=-1;
        return dist;
    }
};
