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
    ListNode* rev(ListNode* node){
        ListNode* prev=nullptr;
        ListNode* curr=node;
        while(curr){
            ListNode* nextt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next)return 1;
        ListNode *slow=head, *fast=head;
        while(fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* sec=rev(slow->next);
        slow->next=nullptr;

        while(sec){
            if(head->val != sec->val)return 0;
            head=head->next;
            sec=sec->next;
        }
        return 1;
        
    }
};