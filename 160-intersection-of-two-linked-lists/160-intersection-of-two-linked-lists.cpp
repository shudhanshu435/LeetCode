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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* dum1 = headA;
        ListNode* dum2 = headB;
        
        while(dum1 != dum2)
        {
            dum1 = dum1->next;
            dum2 = dum2->next;
            
            if(dum1 == NULL && dum2 == NULL)
                return NULL;
            
			else if(dum1 == NULL)
                dum1 = headB;
            
			else if(dum2 == NULL)
                dum2 = headA;
        }
        return dum1;
    }
};