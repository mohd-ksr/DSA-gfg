class Solution {
private:
    void dfs(int u, vector<vector<int>>& adjList, vector<bool>&visited){
        if(visited[u])return;
        visited[u] = true;
        for(auto v:adjList[u]){
            if(!visited[v]){
                dfs(v, adjList, visited);
            }
        }
    }
public:
    int minConnect(int V, vector<vector<int>>& edges) {
        // Code here
        if(edges.size() < V-1)return -1;
        vector<vector<int>>adjList(V);
        for(auto &e:edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        vector<bool>visited(V,false);
        int cnt = 0;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs(i,adjList,visited);
                cnt++;
            }
        }
        return cnt - 1;
    }
};
