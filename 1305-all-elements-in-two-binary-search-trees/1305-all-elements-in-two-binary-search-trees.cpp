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
    void dfs(TreeNode* root, vector<int>&v){
        if(!root)return;
        dfs(root->left,v);
        v.push_back(root->val);
        dfs(root->right,v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>in1,in2,v;
        dfs(root1,in1);
        dfs(root2,in2);
        int i=0,j=0;
        int n=in1.size(),m=in2.size();
        while(i<n and j<m){
            if(in1[i]<in2[j]){
                v.push_back(in1[i++]);
            }
            else v.push_back(in2[j++]);
        }
        while(j<m)v.push_back(in2[j++]);
        while(i<n)v.push_back(in1[i++]);
        return v;
    }
};