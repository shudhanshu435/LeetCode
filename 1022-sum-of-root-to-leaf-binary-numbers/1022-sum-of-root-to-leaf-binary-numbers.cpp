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
    void dfs(TreeNode*root, string& s, int& ans){
        if(!root){
            return;
        }
        s+=(char)('0'+root->val);

        if(!root->left and !root->right){
            int dec=stoi(s,nullptr,2);
            ans+=dec;
        }
        else{
            dfs(root->left,s,ans);
            dfs(root->right,s,ans);
        }
        s.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans=0;
        string s="";
        dfs(root,s,ans);
        return ans;
    }
};