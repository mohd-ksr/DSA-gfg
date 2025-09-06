class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int ciel=-1;
        Node* curr = root;
        while(curr){
            if(curr->data>=x){
                ciel=curr->data;
                curr=curr->left;
            }
            else curr=curr->right;
        }
        return ciel;
    }
};
// Time complexty O(log(n))
// Space complexity O(1)
