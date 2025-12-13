/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int k=q.size();
            level++;
            while(k--){
                TreeNode* node=q.front();
                q.pop();
                if(!node->left and !node->right)return level;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }

        }
        return level;
    }
};