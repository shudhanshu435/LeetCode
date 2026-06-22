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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root;
        if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else{
            if(!root->left and !root->right){
                delete root;return nullptr;
            }
            if(!root->left){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            if(!root->right){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }

            TreeNode* temp=root->right;
            while(temp->left)temp=temp->left;
            root->val=temp->val;
            root->right=deleteNode(root->right,temp->val);
        }

        return root;
    }
};