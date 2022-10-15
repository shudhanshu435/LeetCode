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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p=head;
        ListNode *q=head;
        ListNode *ptr=head->next;
        int sz=0;
        while(p!=NULL){
            sz++;
            p=p->next;
        }
        if(sz==1)return {};
        sz=sz-n;
        if(sz==0)return head->next;
        for(int i=0;i<sz-1;i++){
            q=q->next;
            ptr=ptr->next;
        }
        q->next=ptr->next;
        delete ptr;
        return head;
    }
};