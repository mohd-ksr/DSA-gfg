class Solution {
private:
    bool dfs(int node, vector<vector<int>>&adjList, vector<int>&vis, vector<int>&pathVis){
        vis[node]=1;
        pathVis[node]=1;
        
        for(int nei:adjList[node]){
            if(!vis[nei]){
                if(dfs(nei, adjList, vis, pathVis))return true;
            }
            else if(pathVis[nei]==1)return true;
        }
        
        pathVis[node]=0;
        return false;
    }
public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>>adjList(V);
        for(auto &e:edges){
            adjList[e[0]].push_back(e[1]);
        }
        
        vector<int>vis(V, 0), pathVis(V, 0);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, adjList, vis, pathVis)) return true;
            }
        }
        return false;
    }
};