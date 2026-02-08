class Solution {
private:
    void dfs(int node,  vector<vector<int>>&adjList, stack<int>&st, vector<bool>&vis){
        vis[node]=true;
        for(auto nei:adjList[node]){
            if(!vis[nei])dfs(nei, adjList, st, vis);
        }
        st.push(node);
    }
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
       vector<vector<int>>adjList(V);
       for(auto &e:edges){
           adjList[e[0]].push_back(e[1]);
       }
       stack<int>st;
       vector<bool>vis(V, false);
       for(int i=0; i<V; i++){
           if(!vis[i])dfs(i, adjList, st, vis);
       }
        
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};