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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root)return root;
        queue<TreeNode*>q;
        q.push(root);
        int cnt=0;
        while(!q.empty()){
            cnt++;
            vector<int>v;
            vector<TreeNode*>vec;
            int k=q.size();
            while(k--){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left and temp->right){
                    vec.push_back(temp->left);
                    vec.push_back(temp->right);
                    v.push_back(temp->left->val);
                    v.push_back(temp->right->val);
                    q.push(temp->left);
                    q.push(temp->right);

                }
            }
            if(cnt&1){
                int n=v.size();
                for(int i=0;i<v.size();i+=2){
                    TreeNode*left=vec[i];
                    left->val=v[n-1-i];
                    TreeNode*right=vec[i+1];
                    right->val=v[n-1-(i+1)];
                }

            }

        }
        return root;
    }
};