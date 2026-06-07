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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        vector<int>l(100001,0),r(100001,0);
        set<int>s;
        for(auto &i: des){
            s.insert(i[1]);
            if(i[2]==1){
                l[i[0]]=i[1];
            }
            else r[i[0]]=i[1];
        }
        int val=0;
        for(auto &i:des){
            if(s.contains(i[0]))continue;
            else {
                val=i[0];
                break;
            }
        }
        TreeNode* curr=new TreeNode(val);
        queue<TreeNode*>q;
        q.push(curr);
        while(!q.empty()){
            TreeNode* c=q.front();
            q.pop();
            if(l[c->val]!=0){
                c->left=new TreeNode(l[c->val]);
                q.push(c->left);
            }
            if(r[c->val]!=0){
                c->right=new TreeNode(r[c->val]);
                q.push(c->right);
            }
        }

        return curr;

    }
};