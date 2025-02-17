/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        vector<int>v;
        ListNode* temp =head;
        int curr=0;
        while(temp){
            if(temp->val!=0)
                curr+=temp->val;
            else{
                if(curr!=0)v.push_back(curr);
                curr=0;
            }
            temp=temp->next;
        }
        temp=head;
        for(auto i:v){
            ListNode* newNode=new ListNode(i);
            temp->next=newNode;
            temp=newNode;
        }
        return head->next;
    }
};