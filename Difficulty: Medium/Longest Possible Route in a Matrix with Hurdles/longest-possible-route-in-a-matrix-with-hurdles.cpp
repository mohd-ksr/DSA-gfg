class Solution {
private:
    int ans=0;
    int xd;
    int yd;
    int r,c;
    bool flag = false;
    vector<vector<int>>vis;
    void dfs(vector<vector<int>>& mat, int i, int j, int tempAns){
        if(i<0 || i>=r || j<0 || j>=c || vis[i][j]==1 || mat[i][j]==0)return;
        if(i==xd && j==yd){
            ans = max(ans, tempAns);
            flag = true;
            return;
        }
        vis[i][j]=1;
        dfs(mat, i+1, j, tempAns+1);
        dfs(mat, i, j+1, tempAns+1);
        dfs(mat, i-1, j, tempAns+1);
        dfs(mat, i, j-1, tempAns+1);
        vis[i][j]=0;
    }
public:
    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        this->xd = xd;
        this->yd = yd;
        this->r = mat.size();
        this->c = mat[0].size();
        vis.resize(r, vector<int>(c,0));
        dfs(mat, xs, ys, 0);
        return flag?ans:-1;
    }
};