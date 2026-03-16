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
    int dfs(TreeNode* root, long long curr, int k, unordered_map<long long,int>&mp){
        if(!root)return 0;
        curr+=root->val;
        int ans=0;
        if(mp.count(curr-k)){
            ans+=mp[curr-k];
        }
        mp[curr]++;
        ans+=dfs(root->left,curr,k,mp);
        ans+=dfs(root->right,curr,k,mp);
        mp[curr]--;

        return ans;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int>mp;
        mp[0]=1;
        return dfs(root,0,targetSum,mp);
    }
};