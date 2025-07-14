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
    int getDecimalValue(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=nullptr;
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        long long num=0;
        int k=0;
        while(prev){
            // cout<<prev->val<<" ";
            if(prev->val)num+=(1<<k);
            prev=prev->next;
            k++;
        }

        return num;
    }
};