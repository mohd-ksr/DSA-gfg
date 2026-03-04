class DSU{
private:
    vector<int>parent, rank;
public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for(int i=0; i<=n; i++)parent[i]=i;
    }
    
    int findUpar(int node){
        if(parent[node]==node)return node;
        return parent[node]=findUpar(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DSU ds(m*n);
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int count = 0;
        vector<int>ans;
        for(auto &op:operators){
            int r = op[0];
            int c = op[1];
            
            if(vis[r][c]==1){
                ans.push_back(count);
                continue;
            }
            vis[r][c]=1;
            count++;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    if(vis[nr][nc]==1){
                        int nn = r*m + c;
                        int nnn = nr*m + nc;
                        if(ds.findUpar(nn) != ds.findUpar(nnn)){
                            count--;
                            ds.unionByRank(nn, nnn);
                        }
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};







