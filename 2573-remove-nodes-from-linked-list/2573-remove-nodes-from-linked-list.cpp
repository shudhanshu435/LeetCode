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
    void rev(ListNode*& head){
        if(!head or !(head->next))return;
        ListNode* curr=head;
        ListNode*prev=nullptr;
        while(curr){
            ListNode* nextt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextt;
        }
        head=prev;
        return;
    }
    ListNode* removeNodes(ListNode* head) {
        rev(head);
        if(!head)return head;
        ListNode* temp=head;

        ListNode* curr=head->next;
        int maxi=temp->val;
        while(curr){
            while(curr and curr->val<maxi){
                curr=curr->next;
            }
            temp->next=curr;
            temp=temp->next;
            if(curr){
                maxi=max(maxi,curr->val);
                curr=curr->next;
            }
        }
        rev(head);
        return head;
    }
};