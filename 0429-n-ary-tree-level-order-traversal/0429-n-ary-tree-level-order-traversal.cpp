/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)return {};
        queue<Node*>q;
        q.push(root);
        vector<vector<int>>vec;
        while(!q.empty()){
            int k=q.size();
            vector<int>v;
            while(k--){
                Node* curr=q.front();
                q.pop();
                v.push_back(curr->val);
                for(Node* node:curr->children){
                    if(node)q.push(node);
                }
            }
            vec.push_back(v);
        }
        return vec;
    }
};