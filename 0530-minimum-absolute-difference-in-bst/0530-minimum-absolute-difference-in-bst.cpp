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
    int v=0,k=0;
    int ans=INT_MAX;
    int prev;
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        if(k==0){
            v=root->val;
            k=1;
        }
        else {
            ans=min(ans,root->val-v);
            v=root->val;
        }

        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return ans;
    }
};