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
    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr;
        ListNode*curr=head;
        while(curr){
            ListNode* nextt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextt;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        head= reverse(head);
        ListNode* curr=head,*prev=nullptr;
        int carry=0;
        while(curr){
            long long data=curr->val;
            data+=data;
            curr->val=(data+carry)%10;
            carry=data/10;
            prev=curr;
            curr=curr->next;
        }
        if(carry>=1){
            ListNode*newnode=new ListNode(carry);
            prev->next=newnode;
        }
        return reverse(head);
    }
};