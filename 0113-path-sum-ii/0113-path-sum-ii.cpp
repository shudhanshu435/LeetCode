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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>vec;
        if(!root)return {};
        queue<pair<pair<TreeNode*,int>,vector<int>>>q;
        vector<int>v;
        v.push_back(root->val);
        q.push({{root,root->val},v});
        while(!q.empty()){
            int k=q.size();
            while(k--){
                TreeNode* curr=q.front().first.first;
                int num=q.front().first.second;
                vector<int>v=q.front().second;
                q.pop();
                if(curr->left){
                    v.push_back(curr->left->val);
                    q.push({{curr->left,curr->left->val+num},v});
                    v.pop_back();
                }
                if(curr->right){
                    v.push_back(curr->right->val);
                    q.push({{curr->right,curr->right->val+num},v});
                    v.pop_back();
                }

                if(!curr->left and !curr->right and num==targetSum)vec.push_back(v);
            }
        }
        return vec;
    }
};