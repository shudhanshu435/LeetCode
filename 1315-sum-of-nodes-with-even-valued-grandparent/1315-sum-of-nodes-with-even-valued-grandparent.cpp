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
    int sumEvenGrandparent(TreeNode* root) {
        int ans=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,-1});
        while(!q.empty()){
            int k=q.size();
            while(k--){
                TreeNode* curr=q.front().first;
                int p=q.front().second;
                q.pop();
                if(curr->left){
                    if(p%2==0)ans+=curr->left->val;
                    q.push({curr->left,curr->val});
                }
                if(curr->right){
                    if(p%2==0)ans+=curr->right->val;
                    q.push({curr->right,curr->val});
                }
            }
        }
        return ans;
    }
};