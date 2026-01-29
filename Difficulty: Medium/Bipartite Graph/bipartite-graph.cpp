class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<vector<int>>graph(V);
        for(auto e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int>color(V, -1);
        queue<int>q;
        q.push(0);
        color[0]=0;
        while(!q.empty()){
            int node = q.front(); q.pop();
            for(int nei:graph[node]){
                if(color[nei]==-1){
                    color[nei]=!color[node];
                    q.push(nei);
                }
                else if(color[node]==color[nei])return false;
            }
        }
        
        return true;
    }
};