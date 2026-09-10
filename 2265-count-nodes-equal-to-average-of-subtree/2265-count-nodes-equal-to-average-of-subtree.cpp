/*
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
    pair<int,int> dfs(TreeNode* root, int &ans){
        if(!root)return {-1,0};
        auto [l,c]=dfs(root->left,ans);
        auto [r,d]=dfs(root->right,ans);
        if(l==-1)l=0;
        if(r==-1)r=0;
        if((l+r+root->val)/(c+d+1) == root->val)ans++;
        return {l+r+root->val,c+d+1};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        dfs(root,ans);
        return ans;
    }
};