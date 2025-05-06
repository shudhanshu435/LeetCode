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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>v;
        while(!q.empty()){
            int k=q.size();
            v.push_back(q.back()->val);
            while(k--){
                TreeNode* no=q.front();
                if(no->left)q.push(no->left);
                if(no->right)q.push(no->right);
                q.pop();
            }
        }
        return v;
    }
};