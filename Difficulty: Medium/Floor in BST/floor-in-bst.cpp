// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int input) {
        // Code here
        int fl=-1;
        while(root){
            if(root->data==input){
                fl = root->data;
                return fl;
            }
            else if(root->data<input){
                fl=root->data;
                root=root->right;
            }
            else root=root->left;
        }
        return fl;
    }
};
// Time complexity O(logn)
// Space complexity O(1)