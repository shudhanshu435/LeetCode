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
    unordered_map<int,int>mp;
    void dfs(TreeNode* root){
        if(!root)return;
        mp[root->val]++;
        dfs(root->left);
        dfs(root->right);
        if(!root->left and !root->right){
            int cnt=0;
            for(auto &i:mp){
                if(i.second%2==1)cnt++;
            }
            if(cnt<=1)ans++;
        }
        mp[root->val]--;
        if(mp[root->val]==0)mp.erase(root->val);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root)return 0;
        dfs(root);
        return ans;
    }
};