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
    int countminswaps(vector<int>&vec){
        int swaps=0;
        vector<int>sortedVec(begin(vec),end(vec));
        sort(begin(sortedVec), end(sortedVec));
        unordered_map<int,int>mp;
        for(int i=0;i<vec.size();i++){
            mp[vec[i]]=i;
        }
        for(int i=0;i<vec.size();i++){
            if(vec[i]==sortedVec[i])continue;
            int curr=mp[sortedVec[i]];
            mp[vec[i]]=curr;
            mp[vec[curr]]=i;
            swap(vec[curr],vec[i]);
            swaps++;
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int result=0;
        while(!q.empty()){
            int k=q.size();
            vector<int>v;
            while(k--){
                TreeNode* temp=q.front();
                q.pop();
                v.push_back(temp->val);

                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
            result+=countminswaps(v);
        }
        return result;
    }
};