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
    void dfs(int& ans, TreeNode* root, int num){
        num=num*10+root->val;
        if(!root->left and !root->right){
            ans+=num;
        }
        if(root->left)dfs(ans,root->left,num);
        if(root->right)dfs(ans,root->right,num);
    }
    int sumNumbers(TreeNode* root) {
        if(!root)return 0;
        int ans=0;
        dfs(ans,root,0);
        return ans;
    }
};