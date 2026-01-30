class Solution {
private:
    bool dfs(int node, int parent, vector<vector<int>>&adjList, vector<bool>&vis){
        vis[node]=true;
        
        for(int nei:adjList[node]){
            if(!vis[nei]){
                if(dfs(nei, node, adjList, vis))return true;
            }
            else if(parent!=nei)return true;
        }
        return false;
    }
public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adjList(V);
        for(auto &e:edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        
        vector<bool>vis(V, false);
        for(int i=0; i<V; i++){
            if(!vis[i] && dfs(i,-1,adjList,vis)) return true;
        }
        
        return false;
        
    }
};