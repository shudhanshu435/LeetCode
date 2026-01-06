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
    int maxLevelSum(TreeNode* root) {
        TreeNode* curr=root;
        queue<TreeNode*>qq;
        qq.push(root);
        int ans=1;
        int k=1;
        int maxi=INT_MIN;
        while(!qq.empty()){
            int s= qq.size();
            int sum=0;
            while(s--){
                TreeNode* node=qq.front();
                qq.pop();
                sum+=node->val;
                if(node->left)qq.push(node->left);
                if(node->right)qq.push(node->right);
            }
            if(sum>maxi){
                maxi=sum;
                ans=k;
            }
            k++;
        }
        return ans;
    }
};