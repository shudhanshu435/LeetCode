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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next)return head;
        ListNode*temp=head;
        int cnt=0;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        if(k==0)return head;
        k=k%cnt;
        if(k==0)return head;
        k=cnt-k;
        if(k==0)return head;
        temp=head;
        while(k--)temp=temp->next;
        ListNode*curr=head;
        while(curr->next!=temp){
            curr=curr->next;
        }
        curr->next=nullptr;
        curr=head;
        head=temp;
        while(head->next!=nullptr){
            head=head->next;
        }
        head->next=curr;
        return temp;
    }
};