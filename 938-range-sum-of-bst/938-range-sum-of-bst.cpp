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
    void preorder(TreeNode* root, int &sum , int low, int high)
    {
        if(root==NULL) return;
        
        if(root->val >= low and root->val <=high)
        {
            sum = sum + root->val;
        }
        preorder(root->left,sum,low,high);
        preorder(root->right,sum,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        int sum = 0;
        preorder(root,sum,low,high);
        return sum;
    }
};