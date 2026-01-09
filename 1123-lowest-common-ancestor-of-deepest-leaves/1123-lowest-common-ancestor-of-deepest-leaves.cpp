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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root)return root;
        map<TreeNode*,TreeNode*>mp;
        queue<TreeNode*>q;
        q.push(root);
        vector<TreeNode*>v;
        v.push_back(root);

        while(!q.empty()){
            v.clear();
            int k=q.size();
            while(k--){
                TreeNode* temp=q.front();
                v.push_back(temp);
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                    mp[temp->left]=temp;
                }
                if(temp->right){
                    q.push(temp->right);
                    mp[temp->right]=temp;
                }
            }
        }

        if(v.size()==1)return v[0];
        while(1){
            set<TreeNode*>s;
            int i=0;
            for(auto i:v){
                s.insert(mp[i]);
            }
            if(s.size()==1){
                return *s.begin();
            }
            v.assign(s.begin(), s.end());
        }

        return root;
    }
};