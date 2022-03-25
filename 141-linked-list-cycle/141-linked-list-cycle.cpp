/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*>s;
        while(head){
            if(s.find(head)!=s.end())return 1;
            s.insert(head);
            head=head->next;
        }
        return 0;
    }
};