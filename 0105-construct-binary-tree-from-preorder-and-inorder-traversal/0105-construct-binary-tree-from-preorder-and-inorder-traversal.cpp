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
    int currind=0;
    unordered_map<int,int>mp;
    TreeNode* func(vector<int>& pre, int l, int r){
        if(l>r)return nullptr;

        int v=pre[currind++];
        TreeNode* root=new TreeNode(v);

        int mid=mp[v];
        root->left=func(pre,l,mid-1);
        root->right=func(pre,mid+1,r);

        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        for(int i=0;i<in.size();i++){
            mp[in[i]]=i;
        }

        return func(pre,0,in.size()-1);
    }
};