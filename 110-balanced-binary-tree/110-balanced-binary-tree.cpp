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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
           return true;
        return height(root) != -1;
    }
    int height(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int lH = height(root->left);
        int rH = height(root->right);
        if(lH == -1 || rH == -1 || abs(lH - rH) > 1){
            return -1;
        }
        return 1 + max(lH, rH);
    }
};