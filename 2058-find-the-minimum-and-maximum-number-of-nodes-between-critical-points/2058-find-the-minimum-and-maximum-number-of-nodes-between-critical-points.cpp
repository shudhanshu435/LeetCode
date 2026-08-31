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
    vector<int> solve(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* prev = head;
        vector<int> criticalPoints;
        int idx = 1;
        while(curr && curr->next) {
            if(prev->val < curr->val && curr->val > curr->next->val) criticalPoints.push_back(idx);
            else if(prev->val > curr->val && curr->val < curr->next->val) criticalPoints.push_back(idx);
            prev = curr;
            curr = curr->next;
            idx++;
        } 

        int maxi = -1, mini = 1e9;
        for(auto p : criticalPoints) cout <<p <<" -> ";
        
        sort(criticalPoints.begin(), criticalPoints.end());
        for(int i = 1; i < criticalPoints.size(); i++) {
            mini = min(mini, criticalPoints[i] - criticalPoints[i - 1]);
        }
        if(criticalPoints.size() <= 1) return {-1, -1};
        maxi = criticalPoints.back() - criticalPoints.front();
        return {mini, maxi};
    }
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        return solve(head); 
    }
};