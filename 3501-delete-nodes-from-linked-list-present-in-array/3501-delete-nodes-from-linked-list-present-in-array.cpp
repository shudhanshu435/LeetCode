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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,bool>mp;
        for(auto &i:nums)mp[i]=1;
        ListNode* temp=head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        while(temp){
            if(mp[temp->val]){
                prev->next=temp->next;
                temp=temp->next;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        return dummy->next;
    }
};