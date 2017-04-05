class Solution {
public:
    ListNode* reverseKGroup(ListNode *head, int k) {
        if (!head || k == 1) { return head; }
        int num = 0;
        ListNode* preHead = new ListNode(-1); preHead->next = head;
        ListNode* pre = preHead, *cur = head, *nex, *tmp;
        while (cur) { cur = cur->next; num++; }
        while (num >= k) {
            cur = pre->next;
            nex = cur->next;
            for (int i = 1; i < k; ++i) {
                tmp = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                cur->next = tmp;
                nex = tmp;
            }
            num -= k;
            pre = cur;
        }
        return preHead->next;
    }
};