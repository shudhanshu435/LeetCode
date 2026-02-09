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
    TreeNode* rec(vector<int>&v, int i, int j){
        if(i>j)return nullptr;
        int mid=(i+j)/2;
        TreeNode* rot=new TreeNode(v[mid]);
        rot->left=rec(v,i,mid-1);
        rot->right=rec(v,mid+1,j);
        return rot;
    }
    void func(TreeNode* root, vector<int>&v){
        if(!root)return;
        v.push_back(root->val);
        if(root->left)func(root->left,v);
        if(root->right)func(root->right,v);
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(!root)return root;
        vector<int>v;
        func(root,v);
        sort(v.begin(),v.end());
        int n=v.size();
        return rec(v,0,n-1);
    }
};