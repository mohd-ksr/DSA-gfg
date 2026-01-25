class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
        int r = grid.size();
        int c = grid[0].size();
        
        vector<vector<int>>dist(r,vector<int>(c,0));
        queue<pair<int, int>>q;
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==1)q.push({i, j});
            }
        }
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [i, j] = q.front(); q.pop();
                if(i-1>=0 && grid[i-1][j]==0){
                    grid[i-1][j]=1;
                    dist[i-1][j]=dist[i][j]+1;
                    q.push({i-1, j});
                }
                if(j-1>=0 && grid[i][j-1]==0){
                    grid[i][j-1]=1;
                    dist[i][j-1]=dist[i][j]+1;
                    q.push({i, j-1});
                }
                if(i+1<r && grid[i+1][j]==0){
                    grid[i+1][j]=1;
                    dist[i+1][j]=dist[i][j]+1;
                    q.push({i+1, j});
                }
                if(j+1<c && grid[i][j+1]==0){
                    grid[i][j+1]=1;
                    dist[i][j+1]=dist[i][j]+1;
                    q.push({i, j+1});
                }
            }
        }
        return dist;
    }
};



