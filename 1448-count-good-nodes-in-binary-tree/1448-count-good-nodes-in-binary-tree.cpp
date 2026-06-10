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
    int goodNodes(TreeNode* root) {
        if(!root)return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,root->val});
        int ans=1;
        while(!q.empty()){
            int k=q.size();
            while(k--){
                TreeNode* curr=q.front().first;
                int val=q.front().second;
                q.pop();
                if(curr->left){
                    if(curr->left->val >= val)ans++;
                    q.push({curr->left,max(val,curr->left->val)});
                }
                if(curr->right){
                    if(curr->right->val >= val)ans++;
                    q.push({curr->right,max(val,curr->right->val)});
                }
            }
        }
        return ans;

    }
};