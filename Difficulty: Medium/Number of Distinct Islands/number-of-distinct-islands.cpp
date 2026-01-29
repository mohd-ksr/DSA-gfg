// User function Template for C++

class Solution {
private:
    int r,c;
    void dfs(int i, int j, vector<vector<int>>& grid,  vector<vector<bool>>&vis, vector<pair<int, int>>&vec, int r0, int c0){
        if(i<0 || i>=r || j<0 || j>=c || vis[i][j] || grid[i][j]==0)return;
        grid[i][j]=0;
        vis[i][j]=true;
        vec.push_back({i-r0, j-c0});
        
        dfs(i-1, j, grid, vis, vec, r0, c0);
        dfs(i, j-1, grid, vis, vec, r0, c0);
        dfs(i+1, j, grid, vis, vec, r0, c0);
        dfs(i, j+1, grid, vis, vec, r0, c0);
    }
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        this->r = grid.size();
        this->c = grid[0].size();
        
        vector<vector<bool>>vis(r, vector<bool>(c, false));
        set<vector<pair<int, int>>>st;
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int, int>>vec;
                    dfs(i, j, grid, vis, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        
        return st.size();
    }
};
