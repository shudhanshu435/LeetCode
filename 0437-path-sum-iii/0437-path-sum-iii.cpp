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
    long long sum=0;
    unordered_map<long long, int >mp;
    void dfs(TreeNode* root, int targetSum){
        if(!root)return;
        sum+=root->val;
        // cout<<sum<<endl;
        ans+=mp[sum-targetSum];
        mp[sum]++;
        dfs(root->left,targetSum);
        dfs(root->right,targetSum);
        mp[sum]--;
        if(mp[sum]==0)mp.erase(sum);
        sum-=root->val;
        // cout<<sum<<endl;
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0]=1;
        dfs(root,targetSum);
        return ans;
    }
};