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
    int max_dia=0;
    int findd(TreeNode* root){
        if(!root)   return 0;
        int ldia = findd(root->left);
        int rdia = findd(root->right);
        
        int curr_dia = ldia+rdia;
        
        max_dia=max(max_dia,curr_dia);
        return max(ldia,rdia)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=findd(root);
        return max_dia;
    }
};