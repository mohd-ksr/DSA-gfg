class Solution {
private:
    void dfs1(int node, vector<vector<int>>& adj, vector<bool>&vis, vector<int>&ans){
        if(vis[node])return;
        ans.push_back(node);
        vis[node]=true;
        for(auto &v:adj[node]){
            if(!vis[v]){
                dfs1(v,adj,vis,ans);
            }
        }
    }
    
public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<bool>vis(adj.size()+1, false);
        int start = 0; 
        vector<int>ans;
        dfs1(start,adj,vis,ans);
        return ans;
    }
};