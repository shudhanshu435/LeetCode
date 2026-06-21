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
    int ans=0;
    int dfs(TreeNode* root){
        if(root==nullptr)return 2;
        int l=dfs(root->left);
        int r=dfs(root->right);
        if(l==r and l==2)return 0;
        if(l==0 or r==0){
            ans++;
            return 1;
        }
        if(l==1 or r==1)return 2;

        return ans;
    }
    int minCameraCover(TreeNode* root) {
       int t=dfs(root); 
       if(t==0)return ans+1;
       return ans;
    }
};