/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int getCount(Node *root, int k) {
        // code here
        map<int, int>mapp;
        queue<Node *>q;
        q.push(root);
        int level=1;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                Node* node = q.front();
                q.pop();
                if(!node->left && !node->right){
                    mapp[level]++;
                }
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            level++;
        }
        int ans=0;
        for(auto it:mapp){
            for(int i=1; i<=it.second; i++){
                if(k>=it.first){
                    ans++;
                    k-=it.first;
                }
            }
        }
        return ans;
    }
};















