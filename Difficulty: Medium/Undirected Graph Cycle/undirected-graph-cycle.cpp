class Solution {
private:
    bool bfs(int u, vector<int>adj[], vector<bool>&vis){
        queue<pair<int, int>>q;
        vis[u]=true;
        q.push({u, -1});
        while(!q.empty()){
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
            for(auto nei:adj[node]){
                if(!vis[nei]){
                    vis[nei]=true;
                    q.push({nei, node});
                }
                else if(nei!=par)return true;
            }
        }
        return false;
    }
public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int>adj[V];
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool>vis(V, false);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(bfs(i, adj, vis))return true;
            }
        }
        return false;
    }
};