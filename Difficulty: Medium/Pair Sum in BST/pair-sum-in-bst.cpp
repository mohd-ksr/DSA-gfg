/*
Node is as follows
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
private:
    bool check(Node*root, unordered_set<int>&s, int &k){
        if(!root)return false;
        else if(s.count(k-root->data))return true;
        s.insert(root->data);
        return check(root->left, s, k) || check(root->right, s, k);
    }
public:
    bool findTarget(Node *root, int target) {
        unordered_set<int>s;
        return check(root,s,target);
    }
};
// Time complexity O(n)