/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
#define ll long long
private:
    bool check(Node*root, ll mini, ll maxi){
        if(!root)return true;
        if(root->data >= maxi || root->data <= mini)return false;
        return check(root->left,mini,root->data) && check(root->right,root->data,maxi);
    }
public:
    bool isBST(Node* root) {
        return check(root,LLONG_MIN,LLONG_MAX);
    }
};
// Time Complexity O(n)
// Time Complexity O(n) for reursive stack