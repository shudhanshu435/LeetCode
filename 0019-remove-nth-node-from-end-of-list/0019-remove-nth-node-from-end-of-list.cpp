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
        if(!head or !head->next)return nullptr;
        ListNode* fast=head;
        while(n--){
            fast=fast->next;
        }
        if(!fast)return head->next;
        ListNode*slow=head;
        ListNode* prev=new ListNode(0);
        while(fast){
            prev->next=slow;
            slow=slow->next;
            fast=fast->next;
            prev=prev->next;
        }
        prev->next=slow->next;
        // slow->next=t;
        return head;
    }
};