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
    void inorder(TreeNode* root, unordered_map<int,int>&mp, bool& p, int key){
        if(!root)return;
        inorder(root->left,mp,p,key);
        if(mp[key-root->val]!=0){
            p=true;return;
        }
        mp[root->val]++;
        inorder(root->right,mp,p,key);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>mp;
        bool p=0;
        inorder(root,mp,p,k);
        return p;
    }
};