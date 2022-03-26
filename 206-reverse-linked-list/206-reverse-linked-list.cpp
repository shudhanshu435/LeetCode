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
    ListNode* reverseList(ListNode* head) {
        struct ListNode *ptr1 = NULL, *ptr2 = NULL;
        struct ListNode *ptr = head;
        while(ptr!=NULL){
            ptr1 = ptr->next;
            ptr->next = ptr2;
            ptr2 = ptr;
            ptr = ptr1;
        }
        return ptr2;
    }
};