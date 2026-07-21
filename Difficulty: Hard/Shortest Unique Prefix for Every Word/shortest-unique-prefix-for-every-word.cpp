class TrieNode{
public:
    bool isEnd;
    TrieNode * children[26];
    TrieNode(){
        isEnd = false;
        for(int i=0; i<26; i++){
            children[i]=NULL;
        }
    }
};

class Trie{
private:
    TrieNode*root;
public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode*node = root;
        for(auto ch:word){
            int ind = ch-'a';
            if(node->children[ind]==NULL){
                node->children[ind] = new TrieNode();
            }
            node = node->children[ind];
        }
        node->isEnd = true;
    }
    void solve(TrieNode*root, string word, int ind, string &ans){
        if(root->isEnd)return;
        solve(root->children[word[ind]-'a'], word, ind+1, ans);
        if(ans.size()!=0){
            ans+=word[ind];
            return;
        }
        int cnt = 0;
        for(int i=0; i<26; i++){
            if(root->children[i]!=NULL)cnt++;
        }
        if(cnt>1)ans+=word[ind];
    }
    string uniquePrefix(string word){
        string ans ="";
        solve(root, word, 0, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


class Solution {
public:
    vector<string> findPrefixes(vector<string>& arr) {
        if(arr.size()==1){
            return {arr[0].substr(0,1)};
        }
        Trie *tr = new Trie();
        for(auto it:arr){
            tr->insert(it);
        }
        int n = arr.size();
        vector<string>ans(n);
        for(int i=0; i<n; i++){
            ans[i] = tr->uniquePrefix(arr[i]);
        }
        return ans;
    }
};









