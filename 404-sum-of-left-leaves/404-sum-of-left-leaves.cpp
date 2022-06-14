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
    int total = 0;
    void DFS(bool left, TreeNode* current){
        if (current == NULL){
            return;
        }
        if (left && current->left == NULL && current->right == NULL){
            total += current->val;
            return;
        }
        DFS(true, current->left);
        DFS(false, current->right);
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        DFS(false, root);
        return total;
    }
};