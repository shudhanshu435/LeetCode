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
    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        if(!root)return 0;
        queue<tuple<TreeNode*, int, int>>q;
        q.push({root,root->val,root->val});
        while(!q.empty()){
            int k=q.size();
            while(k--){
                TreeNode* curr=get<0>(q.front());
                int mini=get<1>(q.front());
                int maxi=get<2>(q.front());
                q.pop();
                if(curr->left){
                    ans=max({ans,abs(mini-curr->left->val),abs(maxi-curr->left->val)});
                    q.push({curr->left,min(mini,curr->left->val),max(maxi,curr->left->val)});
                }
                if(curr->right){
                    ans=max({ans,abs(mini-curr->right->val),abs(maxi-curr->right->val)});
                    q.push({curr->right,min(mini,curr->right->val),max(maxi,curr->right->val)});
                }
            }
        }
        return ans;
    }
};