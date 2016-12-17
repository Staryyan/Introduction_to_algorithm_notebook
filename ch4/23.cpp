#include "init.h"
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](ListNode* a, ListNode* b) {return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> nodeQueue(comp);
        for (auto each : lists) {
            if (each) {
                nodeQueue.push(each);
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* next = dummy->next;
        while (!nodeQueue.empty()) {
            ListNode* tmp = nodeQueue.top();
            if (tmp) {
                nodeQueue.pop();
                next->next = tmp;
                next = next->next;
                if (tmp->next) { nodeQueue.push(tmp->next); }
            }
        }
        return dummy->next;
    }
};