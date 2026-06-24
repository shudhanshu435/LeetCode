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
    void dfs(TreeNode* root){
        if(!root)return;
        dfs(root->left);
        //for ledt child
        if(root->left){
            int l=root->left->val;
            if(l<=0){
                ans+=abs(l)+1;
                root->val-=(abs(l)+1);
            }
            else if(l>1){
                root->val+=l-1;
                ans+=l-1;
            }

        }
        dfs(root->right);
        //for right child
        if(root->right){
            int r=root->right->val;
            if(r<=0){
                ans+=abs(r)+1;
                root->val-=(abs(r)+1);
            }
            else if(r>1){
                root->val+=r-1;
                ans+=r-1;
            }

        }

    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ans;
    }
};