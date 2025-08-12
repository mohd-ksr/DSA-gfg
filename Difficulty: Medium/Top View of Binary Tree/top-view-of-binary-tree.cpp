/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        if(!root)return ans;
        queue<pair<Node*,int>>q;
        map<int,int>mapp;
        q.push({root,0});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            Node*node=p.first;
            int line=p.second;
            if(mapp.find(line)==mapp.end()){
                mapp[line]=node->data;
            }
            if(node->left)q.push({node->left,line-1});
            if(node->right)q.push({node->right,line+1});
        }
        for(auto &p:mapp){
            ans.push_back(p.second);
        }
        return ans;
    }
};

// Time Complexity O(n)
// Space Complexity O(n)







