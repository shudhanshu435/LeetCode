/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string ans="";
    void preorder(TreeNode* root){
        if(!root){
            ans+="N,";
            return;
        }
        ans+=to_string(root->val)+",";
        preorder(root->left);
        preorder(root->right);
    }

    string serialize(TreeNode* root) {
        // 1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1
        if(!root)return "";
        preorder(root);
        ans.pop_back();
        cout<<ans<<endl;
        return ans;
    }
    int idx=0;
    TreeNode* func(vector<string>&vec){
        if(vec[idx]=="N"){
            idx++;return nullptr;
        }
        TreeNode* root=new TreeNode(stoi(vec[idx++]));
        root->left=func(vec);
        root->right=func(vec);

        return root;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())return nullptr;
        vector<string>v;
        stringstream ss(data);
        string num;
        while(getline(ss,num,',')){
            v.push_back(num);
        }
        return func(v);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));