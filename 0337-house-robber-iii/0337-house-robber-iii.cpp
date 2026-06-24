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
        pair<int,int>a=dfs(root->left);
        pair<int,int>b=dfs(root->right);
        int t=root->val+a.second+b.second;
        int nt=max(a.first,a.second)+max(b.first,b.second);

        return {t,nt};

    }
    int rob(TreeNode* root) {
        pair<int,int>p=dfs(root);
        return max(p.first,p.second);
    }
};