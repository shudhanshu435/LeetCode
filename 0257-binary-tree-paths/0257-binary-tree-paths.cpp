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
    void dfs(vector<vector<int>>&v, TreeNode* root, vector<int>vv){
        vv.push_back(root->val);
        if(!root->left and !root->right){
            v.push_back(vv);
        }
        if(root->left)dfs(v,root->left,vv);
        if(root->right)dfs(v,root->right,vv);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>>v;
        vector<int>vv;
        dfs(v,root,vv);
        vector<string>vec;
        for(auto i:v){
            string s="";
            for(auto ii:i){
                s+=to_string(ii)+"->";
            }
            s.pop_back();
            s.pop_back();
            vec.push_back(s);
        }
        return vec;
    }
};