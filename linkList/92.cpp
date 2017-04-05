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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || m == n) { return head; }
        ListNode* head1 = new ListNode(0);
        head1->next = head;
        head = head1;
        for (int i = 0; i < m - 1; ++i) { head1 = head1->next; }
        ListNode* head2 = head1->next;
        ListNode* p1 = head2->next, *p2 = nullptr;
        head2->next = nullptr;
        int times = n - m;
        while (times--) {
            p2 = p1->next;
            p1->next = head2;
            head2 = p1;
            p1 = p2;
        }
        head1->next->next = p1;
        head1->next = head2;
        return head->next;
    }
};