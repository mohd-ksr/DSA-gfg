class DSU{
private:
    vector<int>rank, parent;
public:
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i]=i;
        }
    }
    int findUlpParent(int node){
        if(node == parent[node])return node;
        return parent[node] = findUlpParent(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int ulp_u = findUlpParent(u);
        int ulp_v = findUlpParent(v);
        
        if(ulp_u == ulp_v)return;
        
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    
};
class Solution {
public:
    int countConnected(int V, vector<vector<int>>& edges) {
        DSU ds(V);
        for(auto edge:edges){
            ds.unionByRank(edge[0], edge[1]);
        }
        int ans = -1;
        for(int i=0; i<=V; i++){
            if(ds.findUlpParent(i)==i)ans++;
        }
        return ans;
        
    }
};









