/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int>>mp;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int k=q.size();
            while(k--){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left){
                    mp[curr->val].push_back(curr->left->val);
                    mp[curr->left->val].push_back(curr->val);
                    q.push(curr->left);
                }
                if(curr->right){
                    mp[curr->val].push_back(curr->right->val);
                    mp[curr->right->val].push_back(curr->val);
                    q.push(curr->right);
                }
            }
        }
        // cout<<k<<endl;
        queue<int>qq;
        qq.push(target->val);
        vector<bool>vis(501,0);
        vis[target->val]=1;
        while(!qq.empty() and k){
            int kk=qq.size();
            k--;
            while(kk--){
                int v=qq.front();
                qq.pop();
                for(auto &i:mp[v]){
                    if(!vis[i]){
                        qq.push(i);
                        vis[i]=1;
                    }
                }
            }

        }
        vector<int>ans;
        while(!qq.empty()){
            ans.push_back(qq.front());
            qq.pop();
        }
        return ans;
    }
};