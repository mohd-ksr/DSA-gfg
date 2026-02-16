class Solution {
private:
    string topoSort(unordered_set<char>&st, unordered_map<char, string>&adj){
        unordered_map<char, int>inDeg;
        for(auto &u:st){
            if(inDeg.find(u)==inDeg.end())inDeg[u]=0;
            for(auto v:adj[u]){
                inDeg[v]++;
            }
        }
        
        queue<char>q;
        for(auto &u:st){
            if(inDeg[u]==0)q.push(u);
        }
        
        string ans;
        while(!q.empty()){
            char node = q.front(); q.pop();
            ans.push_back(node);
            
            for(auto nei:adj[node]){
                inDeg[nei]--;
                if(inDeg[nei]==0)q.push(nei);
            }
        }
        
        return ans;
    }
public:
    string findOrder(vector<string> &words) {
        int n = words.size();
        unordered_set<char>st;
        for(auto &str:words){
            for(auto &ch:str){
                st.insert(ch);
            }
        }
        
        int v = st.size();
        
        unordered_map<char, string>adj;
        
        for(int i=0; i<n-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            
            int l = min(s1.length(), s2.length());
            
            int j=0;
            while(j<l){
                if(s1[j]!=s2[j]){
                    adj[s1[j]].push_back(s2[j]);
                    break;
                }
                j++;
            }
            if(j==l && s1.length() > s2.length())return "";
        }
        
        string topo = topoSort(st, adj);
        if(topo.length()!=v)return "";
        return topo;
    }
};





