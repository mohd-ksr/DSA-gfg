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
};
*/

class Solution {
private:
    Node* create(vector<int>& arr, int l, int r){
        if(l>r)return NULL;
        int mid = (l+r)/2;
        Node * node = new Node(arr[mid]);
        node->left = create(arr, l, mid-1);
        node->right = create(arr, mid+1, r);
        
        return node;
    }
public:
    Node* sortedArrayToBST(vector<int>& arr) {
        int n = arr.size();
        return create(arr, 0, n-1);
    }
};