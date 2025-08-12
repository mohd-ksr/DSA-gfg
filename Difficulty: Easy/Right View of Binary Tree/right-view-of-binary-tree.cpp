/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
private:
    void dfs(Node*root, int level, vector<int>&ans){
        if(!root)return;
        level++;
        if(level>ans.size()){
            ans.push_back(root->data);
        }
        dfs(root->right,level,ans);
        dfs(root->left,level,ans);
    }
public:
    vector<int> rightView(Node *root) {
        vector<int>ans;
        dfs(root,0,ans);
        return ans;
    }
};