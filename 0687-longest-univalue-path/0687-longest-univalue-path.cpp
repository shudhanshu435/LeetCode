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
    int maxi=0;
    int dfs(TreeNode* root){
        if(!root)return 0;

        int l=dfs(root->left);
        int r=dfs(root->right);

        int ll=0,rr=0;
        if(root->left and root->left->val==root->val){
            ll=l+1;
        }
        if(root->right and root->right->val==root->val){
            rr=r+1;
        }
        maxi=max(maxi,ll+rr);
        return max(ll,rr);
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return maxi;
    }
};