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
    bool identical(TreeNode* s, TreeNode* t){
        if(!s and !t)return 1;
        if((!s and t) or (s and !t))return 0;
        return (s->val==t->val) and identical(s->left,t->left) and identical(s->right,t->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)return 0;
        if(identical(root,subRoot))return 1;
        return isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot);
    }
};