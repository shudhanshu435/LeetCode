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
class Solution 
{
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        std::vector<int> res;
        traveralUtil(root, res);
        return res;
    }
private:
    void traveralUtil(TreeNode* root, std::vector<int>& res)
    {
        if (!root)
            return;
        traveralUtil(root->left, res);
        traveralUtil(root->right, res);
        res.push_back(root->val);
    }
};