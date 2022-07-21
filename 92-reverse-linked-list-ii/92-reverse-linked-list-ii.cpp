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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
            if(head==NULL || head->next==NULL)return head;
        
        ListNode* oth=new ListNode(-1);
        oth->next=head;
        ListNode* previt=NULL; 
        ListNode* it=oth;
        
        for(int i=0;i<left;i++){
            previt=it;
            it=it->next;
        }
        ListNode* c=it;
        ListNode* p=previt;
        for(int i=left;i<=right;i++){
            ListNode* Next=c->next;
            c->next=p;
            p=c;
            c=Next;
        }
        previt->next=p;
        it->next=c;
        
        return oth->next;
    }
};