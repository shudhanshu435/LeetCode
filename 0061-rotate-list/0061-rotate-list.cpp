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
        ListNode* temp=head, *curr=head;
        int cnt=1;
        while(temp->next){
            temp=temp->next;
            cnt++;
        }
        k=k%cnt;
        temp->next=head;
        cnt=cnt-k-1;
        while(cnt--){
            curr=curr->next;
        }
        head=curr->next;
        curr->next=nullptr;

        return head;

    }
};