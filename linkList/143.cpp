/**
 * Reverse and merge.
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) { return; }
        ListNode* p1 = head, *p2 = head->next;
        while (p2 && p2->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        ListNode* head2 = p1->next;
        p1->next = nullptr;
        p2 = head2->next;
        head2->next = nullptr;
        while (p2) {
            p1 = p2->next;
            p2->next = head2;
            head2 = p2;
            p2 = p1;
        }
        for (p1 = head, p2 = head2; p2;) {
            auto t = p1->next;
            p1->next = p2;
            p2 = p2->next;
            p1 = p1->next->next = t;
        }
    }
};
