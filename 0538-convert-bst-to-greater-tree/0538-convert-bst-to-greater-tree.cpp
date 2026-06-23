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
    int ans=0;
    void sum(TreeNode* root){
        if(!root)return;
        sum(root->left);
        ans+=root->val;
        sum(root->right);
    }
    int summ=0;
    void ino(TreeNode*& root){
        if(!root)return;
        ino(root->left);
        int v=root->val;
        root->val=ans-summ;
        summ+=v;
        ino(root->right);
    }
    TreeNode* convertBST(TreeNode* root) {
        sum(root);
        ino(root);
        // cout<<ans<<endl;
        return root;
    }
};