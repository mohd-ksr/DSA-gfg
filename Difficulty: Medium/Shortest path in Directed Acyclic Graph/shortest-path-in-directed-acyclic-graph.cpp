// User function Template for C++
class Solution {
private:
    void dfs(int node,  vector<vector<pair<int, int>>>&adj, vector<bool>&vis, stack<int>&st){
        vis[node]=true;
        
        for(auto it:adj[node]){
            int v = it.first;
            if(!vis[v]){
                dfs(v, adj, vis, st);
            }
        }
        st.push(node);
    }
public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>>adj(V);
        for(auto &e:edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
        }
        
        vector<bool>vis(V);
        stack<int>st;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, st);
            }
        }
        
        vector<int>dist(V,1e9);
        dist[0]=0;
        while(!st.empty()){
            int node = st.top(); st.pop();
            
            for(auto it:adj[node]){
                int v = it.first;
                int w = it.second;
                
                if(dist[node] + w < dist[v]){
                    dist[v] = dist[node]+w;
                }
            }
        }
        
        for(auto &d:dist)if(d==1e9)d=-1;
        
        return dist;
    }
};











