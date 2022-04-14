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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL)return NULL;
        TreeNode* temp=NULL;
        if(val<root->val){
            root->left=searchBST(root->left,val);
            temp=root->left;
        }
        else if(val>root->val){
            root->right=searchBST(root->right,val);
            temp=root->right;
        }
        else if(val==root->val)temp=root;
        return temp;
    }
};