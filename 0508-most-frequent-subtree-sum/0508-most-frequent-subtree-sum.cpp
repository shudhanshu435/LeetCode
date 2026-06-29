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
    int freq=0;
    int dfs(TreeNode* root, unordered_map<int,int>&mp){
        if(!root)return 0;
        int l=dfs(root->left,mp);
        int r=dfs(root->right,mp);
        mp[l+r+root->val]++;
        freq=max(freq,mp[l+r+root->val]);
        return l+r+root->val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int>mp;
        dfs(root,mp);
        vector<int>v;
        for(auto i:mp){
            if(i.second==freq)v.push_back(i.first);
        }
        return v;
    }
};