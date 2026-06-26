/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* curr=nullptr;
    void dfs(TreeNode* cloned, TreeNode* target){
        if(!cloned)return;
        if(cloned->val==target->val){
            curr=cloned;
            return;
        }
        dfs(cloned->left,target);
        dfs(cloned->right,target);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        dfs(cloned,target);
        return curr;
    }
};