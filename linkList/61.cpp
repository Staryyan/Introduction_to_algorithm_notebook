class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) { return nullptr; }
        if (k == 0) { return head; }
        ListNode* tail = head;
        int len = 1;
        while (tail->next != nullptr) {
            tail = tail->next;
            len++;
        }
        tail->next = head;
        int pos = k % len;
        pos = len - pos;
        ListNode* tmp = head;
        while (pos != 1) {
            tmp = tmp->next;
            pos--;
        }
        head = tmp->next;
        tmp->next = nullptr;
        return head;
    }
};