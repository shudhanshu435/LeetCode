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
    int getMinimumDifference(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans=INT_MAX;
        vector<int>v;
        while(!q.empty()){
            int k=q.size();
            while(k--){
                TreeNode* curr=q.front();
                v.push_back(curr->val);
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }

        }
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++){
            ans=min(ans,v[i]-v[i-1]);
        }
        return ans;
    }
};