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
    int ind;
    unordered_map<int,int>mp;
    TreeNode* func(vector<int>&post, int l, int r){
        if(l>r)return nullptr;
        int v=post[ind--];
        TreeNode* root=new TreeNode(v);
        int mid=mp[v];
        root->right=func(post,mid+1,r);
        root->left=func(post,l,mid-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        ind=n-1;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return func(postorder,0,n-1);
    }
};