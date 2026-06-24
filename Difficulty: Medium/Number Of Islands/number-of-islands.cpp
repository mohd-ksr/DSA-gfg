class DSU{
private:
    vector<int>rank,parent;
public:
    DSU(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
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
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DSU ds(m*n);
        vector<int>ans;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int cnt=0;
        for(auto op:operators){
            int r = op[0];
            int c = op[1];
            if(vis[r][c]==1){
                ans.push_back(cnt);
                continue;
            }
            
            vis[r][c]=1;
            cnt++;
            
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for(int i=0; i<4; i++){
                int adjr = r + dr[i];
                int adjc = c + dc[i];
                
                if(adjr>=0 && adjr<n && adjc>=0 && adjc<m){
                    if(vis[adjr][adjc]==1){
                        int nodeN = r*m+c;
                        int adjNodeN = adjr*m+adjc;
                        
                        if(ds.findUlpParent(nodeN)!= ds.findUlpParent(adjNodeN)){
                            ds.unionByRank(nodeN, adjNodeN);
                            cnt--;
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
        
    }
};











