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
    TreeNode* dfs(TreeNode* node1, TreeNode* node2){
        if(!node1 and !node2)return nullptr;

        int num=0;
        if(!node1)num+=node2->val;
        else if(!node2)num+=node1->val;
        else num+=node1->val+node2->val;

        TreeNode* curr=new TreeNode(num);
        curr->left=dfs((node1)?node1->left:nullptr,(node2)?node2->left:nullptr);
        curr->right=dfs((node1)?node1->right:nullptr,(node2)?node2->right:nullptr);

        return curr;
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return dfs(root1,root2);
    }
};