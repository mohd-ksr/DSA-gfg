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
    vector<vector<string>> accMerge(vector<vector<string>>& arr) {
        unordered_map<string, int>mapp;
        int n = arr.size();
        DSU ds(n);
        
        for(int i=0; i<n; i++){
            for(int j=1; j<arr[i].size(); j++){
                if(mapp.find(arr[i][j])==mapp.end()){
                    mapp[arr[i][j]]=i;
                }
                else{
                    ds.unionByRank(i, mapp[arr[i][j]]);
                }
            }
        }
        
        unordered_map<int, vector<string>>mapp2;
        for(auto it:mapp){
            string mail = it.first;
            int node = ds.findUlpParent(it.second);
            mapp2[node].push_back(mail);
        }
        
        vector<vector<string>>ans;
        
        for(auto it:mapp2){
            int ind = it.first;
            vector<string>mails = it.second;
            sort(mails.rbegin(), mails.rend());
            mails.push_back(arr[ind][0]);
            reverse(mails.begin(), mails.end());
            ans.push_back(mails);
        }
        return ans;
    }
};















