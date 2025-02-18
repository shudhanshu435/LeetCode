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
        unordered_map<int,int>mp;
        for(auto i:nums)mp[i]++;
        vector<int>v;
        while(head){
            if(mp[head->val]==0)break;
            head=head->next;
        }
        if(!head)return head;
        ListNode* temp=head;

        ListNode* curr=head;
        temp=temp->next;
        while(temp){
            while(temp and mp[temp->val]!=0){
                temp=temp->next;
            }
            if(!temp)break;
            curr->next=temp;
            curr=temp;
            temp=temp->next;
        }
        curr->next=nullptr;
        
        return head;
    }
};