class DSU{
private:
    vector<int>parent,size;
public:
    DSU(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++)parent[i]=i;
    }
    
    int findUpar(int node){
        if(parent[node]==node)return node;
        return parent[node] = findUpar(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<pair<int, pair<int, int>>>vec;
        for(auto &edge:edges){
            vec.push_back({edge[2], {edge[0], edge[1]}});
        }
        sort(vec.begin(), vec.end());
        
        int ans = 0;
        DSU ds(V);
        for(auto &edge:vec){
            int w = edge.first;
            auto [u, v] = edge.second;
            
            if(ds.findUpar(u) != ds.findUpar(v)){
                ans+=w;
                ds.unionBySize(u,v);
            }
        }
        return ans;
        
    }
};