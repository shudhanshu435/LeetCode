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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int lev=0;
        while(!q.empty()){
            int k=q.size();
            while(k--){
                auto [a,b]=q.front();
                q.pop();
                mp[b].push_back({lev,a->val});
                if(a->left)q.push({a->left,b-1});
                if(a->right)q.push({a->right,b+1});
            }
            lev++;
        }
        vector<vector<int>>v;
        for(auto i:mp){
            sort(i.second.begin(),i.second.end());
            vector<int>vvv;
            for(auto vv:i.second){
                vvv.push_back(vv.second);
            }
            v.push_back(vvv);
        }

        return v;
    }
};