class Solution {
private:
    bool bfs(int src,  vector<vector<int>>&adjList, vector<bool>&vis){
        vis[src]=true;
        queue<pair<int, int>>q;
        q.push({src,-1});
        
        while(!q.empty()){
            auto [node, parent] = q.front();q.pop();
            for(auto &nei:adjList[node]){
                if(!vis[nei]){
                    vis[nei]=true;
                    q.push({nei, node});
                }
                else if(nei!=parent)return true;
            }
        }
        return false;
    }
public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adjList(V);
        for(auto &e:edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        
        vector<bool>vis(V,false);
        for(int i=0; i<V; i++){
            if(!vis[i] && bfs(i, adjList, vis))return true;
        }
        return false;
    }
};