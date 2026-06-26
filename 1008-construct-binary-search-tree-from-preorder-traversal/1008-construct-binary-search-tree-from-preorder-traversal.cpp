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
    void build(TreeNode*curr, int i){
        if(!curr)return;
        if(curr->val>i){
            if(curr->left==nullptr){
                curr->left=new TreeNode(i);
                return;
            }
            build(curr->left,i);
        }
        if(curr->val<=i){
            if(curr->right==nullptr){
                curr->right=new TreeNode(i);
                return;
            }
            build(curr->right,i);
        }

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode*node=new TreeNode(preorder[0]);
        TreeNode* curr=node;
        int n=preorder.size();
        for(int i=1;i<n;i++){
            build(curr,preorder[i]);
        }
        return node;
    }
};