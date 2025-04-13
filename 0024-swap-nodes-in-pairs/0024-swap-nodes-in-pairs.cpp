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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy=new ListNode(0); //new node point next to head
        dummy->next=head;
        ListNode* prev=dummy; //creating new node not to change dummy node directly
        

        while(head and head->next){
            ListNode* first=head;
            ListNode* second=head->next;

            // prev -> A -> B -> X
            prev->next=second; //storing second element of pair first because not to loose
            first->next=second->next;// before setting second next, we'll set first next to second next
            second->next=first;

            // after swap
            // prev -> B -> A -> X
            prev=first;
            head=first->next;

        }
        return dummy->next;
    }
};