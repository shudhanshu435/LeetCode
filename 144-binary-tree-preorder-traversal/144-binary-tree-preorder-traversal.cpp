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
    void pTH(TreeNode* root, vector<int> &res) {
	if(root)
	{
		res.push_back(root -> val);           

			pTH(root -> left, res);
			pTH(root -> right, res);
	}

	return;
}

    vector<int> preorderTraversal(TreeNode* root) {
       vector<int>res;
        pTH(root,res);
        return res;
    }
};