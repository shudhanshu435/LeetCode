/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;https://leetcode.com/subscribe/?ref=lp_pl&source=qd$0
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,char>>>q;
        int maxi=0;
        if(root->left){
            q.push({root->left,{1,'L'}});
        }
        if(root->right){
            q.push({root->right,{1,'R'}});
        }
        while(!q.empty()){
            TreeNode* curr=q.front().first;
            int l=q.front().second.first;
            maxi=max(maxi,l);
            char ch=q.front().second.second;
            q.pop();
            if(curr->left){
                if(ch=='L'){
                    q.push({curr->left,{1,'L'}});
                }
                else{
                    q.push({curr->left,{l+1,'L'}});
                }
            }
            if(curr->right){
                if(ch=='R'){
                    q.push({curr->right,{1,'R'}});
                }
                else{
                    q.push({curr->right,{l+1,'R'}});
                }
            }
        }
        return maxi;
    }
};