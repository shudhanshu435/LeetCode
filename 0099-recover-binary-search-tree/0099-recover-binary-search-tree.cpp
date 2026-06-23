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
    vector<int>v;
    int a,b;
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    void inn(TreeNode* root){
        if(!root)return;
        inn(root->left);
        if(root->val==a)root->val=b;
        else if(root->val==b)root->val=a;
        inn(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        vector<int>t=v;
        sort(t.begin(),t.end());
        for(int i=0;i<v.size();i++){
            if(v[i]!=t[i]){
                a=v[i];
                b=t[i];
                break;
            }
        }
        inn(root);
    }
};