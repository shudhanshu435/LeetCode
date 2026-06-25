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
    string s="";
    void dfs(TreeNode* root){
        if(!root)return;
        s+=to_string(root->val);
        if(root->left){
            s+='(';
            dfs(root->left);
        }
        if(!root->left and root->right){
            s+="()(";
            dfs(root->right);
        }
        if(root->left and root->right){
            s+='(';
            dfs(root->right);
        }
        s+=')';
    }
    string tree2str(TreeNode* root) {
        s.clear();
        if(!root)return "";
        dfs(root);
        s.pop_back();
        return s;
    }
};

// 1(2()(4))(3)