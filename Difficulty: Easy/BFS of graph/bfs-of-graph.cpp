class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<bool>visited(adj.size()+1, false);
        queue<int>q;
        q.push(0);
        visited[0]=true;
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i=0; i<adj[node].size(); i++){
                if(!visited[adj[node][i]]){
                    q.push(adj[node][i]);
                    visited[adj[node][i]]=true;
                }
            }
            ans.push_back(node);
        }
        return ans;
    }
};