class DSU{
private:
    vector<int>parent, rank;
public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for(int i=0; i<=n; i++){
            parent[i]=i;
        }
    }
    int findUlpP(int node){
        if(node==parent[node])return node;
        return parent[node]=findUlpP(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int ulp_u = findUlpP(u);
        int ulp_v = findUlpP(v);
        
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
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        sort(edges.begin(), edges.end(), [](vector<int>&a, vector<int>&b){
            return a[2]<b[2];
        });
        
        // for(auto v:edges){
        //     cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
        // }
            
        DSU ds(V);
        int ans=0;
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            if(ds.findUlpP(u) != ds.findUlpP(v)){
                ds.unionByRank(u,v);
                ans+=w;
            }
        }
        
        return ans;
    }
};













