class DSU{
public:
    vector<int>rank,parent,size;
    DSU(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0; i<=n; i++){
            parent[i]=i;
        }
    }
    
    int findUlpParent(int node){
        if(node==parent[node])return node;
        return parent[node]=findUlpParent(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int ulp_u = findUlpParent(u);
        int ulp_v = findUlpParent(v);
        if(ulp_u==ulp_v)return;
        
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
    
    void unionBySize(int u, int v){
        int ulp_u = findUlpParent(u);
        int ulp_v = findUlpParent(v);
        if(ulp_u==ulp_v)return;
        
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

class Solution {
public:
    int maxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds(n*n);
        
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                if(grid[r][c]==0)continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for(int i=0; i<4; i++){
                    int nr = r+dr[i];
                    int nc = c+dc[i];
                    
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        int nodeN = r*n+c;
                        int newNodeN = nr*n+nc;
                        ds.unionBySize(nodeN, newNodeN);
                    }
                }
            }
        }
        
        int ans=0;
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                if(grid[r][c]==1)continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                
                unordered_set<int>compos;
                for(int i=0; i<4; i++){
                    int nr = r+dr[i];
                    int nc = c+dc[i];
                    
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        int nodeN = nr*n+nc;
                        compos.insert(ds.findUlpParent(nodeN));
                    }
                }
                int totalSize = 1;
                for(auto compo:compos){
                    totalSize+=ds.size[compo];
                }
                ans=max(ans, totalSize);
            }
        }
        return ans==0?n*n:ans;
    }
};













