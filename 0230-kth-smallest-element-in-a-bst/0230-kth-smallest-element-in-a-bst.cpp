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
    int ans=0,v;
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        v--;
        if(v==0)ans=root->val;
        inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        v=k;
        inorder(root);
        return ans;
    }
};