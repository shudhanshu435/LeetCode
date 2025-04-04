class Solution {
private:
    TreeNode* LCA(TreeNode* root, set<TreeNode*> &st){
        if(root == NULL || st.count(root) > 0) return root;

        TreeNode* left = LCA(root -> left, st);
        TreeNode* right = LCA(root -> right, st);

        if(left == NULL) return right;
        else if(right == NULL) return left;
        return root;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        set<TreeNode*> lowestLeafs;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            lowestLeafs.clear();
            for(int i = 0; i < n; i++){
                TreeNode* node = q.front();
                q.pop();
                lowestLeafs.insert(node);
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
        }
        
        TreeNode* ans = LCA(root, lowestLeafs);
        return ans;
    }
};