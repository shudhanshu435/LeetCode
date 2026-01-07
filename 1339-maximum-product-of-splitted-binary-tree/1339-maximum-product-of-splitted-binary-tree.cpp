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
    int mod=1000000007;
    long long ans=0;
    long long tot=0;
    long long sum(TreeNode* root){
        if(!root)return 0;

        long long s1=0,s2=0;
        s1=sum(root->left);
        s2=sum(root->right);

        long long summ=s1+s2+root->val;

        ans = max(ans,summ*(tot-summ));

        return summ;

    }
    int maxProduct(TreeNode* root) {
        tot=sum(root);
        sum(root);
        return ans%mod;
    }
};