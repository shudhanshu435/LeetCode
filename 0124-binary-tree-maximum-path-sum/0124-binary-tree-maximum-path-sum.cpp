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
    int ans=INT_MIN;
    int neg=INT_MIN;
    int dfs(TreeNode* root){
        if(!root)return 0;
        neg=max(neg,root->val);
        int ll=dfs(root->left);
        int rr=dfs(root->right);
        ans=max(ans,root->val+ll+rr);

        return max(max({ll,rr,0})+root->val,0);

    }
    int maxPathSum(TreeNode* root) {
        dfs(root);

        return (ans<0)?neg:ans;
    }
};