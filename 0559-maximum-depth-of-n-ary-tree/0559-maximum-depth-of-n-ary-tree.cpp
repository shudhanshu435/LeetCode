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
    int maxDepth(Node* root) {
        queue<Node*>q;
        q.push(root);
        int x=0;
        while(!q.empty()){
            int k=q.size();
            x++;
            while(k--){
                Node*curr=q.front();
                q.pop();
                for(auto i:curr->children){
                    q.push(i);
                }
            }
        }
        return x;
    }
};