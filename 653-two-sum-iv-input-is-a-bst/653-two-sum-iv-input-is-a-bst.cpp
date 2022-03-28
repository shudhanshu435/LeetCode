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
    vector<int> res;
    void tree(TreeNode* r)
    {
        if(!r)  return;
        tree(r->left);
        res.push_back(r->val);
        tree(r->right);
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root)   return 0;
        tree(root);
        int l=0,r=res.size()-1;
        while(l<r)
        {
            if(res[l]+res[r] == k)  return true;
            if(res[l]+res[r] < k)   l++;
            else    r--;
        }
        return false;
    }
};