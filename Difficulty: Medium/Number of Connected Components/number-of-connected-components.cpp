class Solution {
private:
    vector<bool>vis;
    void dfs(int node, vector<int>adj[]){
        if(vis[node])return;
        vis[node]=true;
        for(int nei:adj[node]){
            dfs(nei, adj);
        }
    }
public:
    int countConnected(int V, vector<vector<int>>& edges) {
        vector<int>adj[V];
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vis.resize(V, false);
        int ans=0;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj);
                ans++;
            }
        }
        return ans;
    }
};