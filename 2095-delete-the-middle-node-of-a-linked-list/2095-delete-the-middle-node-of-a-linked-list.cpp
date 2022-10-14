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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *p=head;
        ListNode *ptr=head;
        ListNode *q=head->next;
        int cnt=0;
        while(p!=NULL){
            cnt++;
            p=p->next;
        }
        cnt=cnt/2;
        if(cnt==0)return {};
        for(int i=0;i<cnt-1;i++){
            ptr=ptr->next;
            q=q->next;
        }
        ptr->next=q->next;
        delete q;
        return head;
    }
};