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
    pair<int,int> dfs(TreeNode* root){
        if(!root)return {0,0};
        auto [a,b]=dfs(root->left);
        auto [c,d]=dfs(root->right);
        int t=b+root->val+d;
        int nt=max(a,b)+max(c,d);
        return {t,nt};
    }
    int rob(TreeNode* root) {
        auto [t,nt]=dfs(root);
        return max(t,nt);
    }
};