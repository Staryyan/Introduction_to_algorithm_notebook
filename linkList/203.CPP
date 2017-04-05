class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) { return head; }
        if (head->val == val) { return removeElements(head->next, val); }
        ListNode* tmp = head;
        while (tmp->next && tmp->next->val != val) {
            tmp = tmp->next;
        }
        if (!tmp->next) { return head; }
        else {
            tmp->next = removeElements(tmp->next->next, val);
            return head;
        }
    }
};
