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
    void rec(vector<string>&ans, TreeNode*root,vector<int>v){
        v.push_back(root->val);
        if(!root->left and !root->right){
            string a="";
            for(int i=0;i<v.size();i++){
                a+=to_string(v[i]);
                if(i<v.size()-1)a+="->";
            }
            ans.push_back(a);
            v.clear();
        }
        if(root->left)rec(ans,root->left,v);
        if(root->right)rec(ans,root->right,v);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int>v;
        vector<string>ans;
        rec(ans,root,v);
        return ans;
    }
};