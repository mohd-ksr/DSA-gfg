class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        if(mat.empty()) return 0;
        int f = 0;
        queue<pair<int, int>>q;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]==2){
                    q.push({i,j});
                }
                if(mat[i][j]==1)f++;
            }
        }
        
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        int ans=0;
        while(f && !q.empty()){
            int s = q.size();
            while(s--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(int k=0; k<4; k++){
                    int ni = i+dx[k];
                    int nj = j+dy[k];
                    if(ni>=0 && ni<mat.size() && nj>=0 && nj<mat[0].size() && mat[ni][nj]==1){
                        q.push({ni, nj});
                        f--;
                        mat[ni][nj]=2;
                    }
                }
            }
            ans++;
        }
        return f?-1:ans;
    }
};




