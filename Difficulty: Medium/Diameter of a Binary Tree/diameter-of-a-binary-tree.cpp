/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
private:
    int solve(Node* root, int &ans){
        if(!root)return 0;
        int l = solve(root->left, ans);
        int r = solve(root->right, ans);
        ans = max(ans, 1+l+r);
        return 1+max(l,r);
    }
public:
    int diameter(Node* root) {
       int ans = INT_MIN;
       solve(root, ans);
       return ans-1;
        
    }
};