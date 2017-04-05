class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) { return l2; } if (!l2) { return l1; }
        ListNode* p1 = l1, *p2 = l2;
        ListNode* l3 = new ListNode(0);
        ListNode* p3 = l3;
        int sum, carry = 0;
        ListNode* tmp = p3;
        while (p1 && p2) {
            sum = p1->val + p2->val;
            p3->val = (sum + carry) % 10;
            carry = (sum + carry) / 10;
            p3->next = new ListNode(0);
            tmp = p3; p3 = p3->next;
            p1 = p1->next; p2 = p2->next;
        }
        p1 = p1 == nullptr ? p2 : p1;
        if (p1) {
            while (p1) {
                p3->val = (p1->val + carry) % 10;
                carry = (p1->val + carry) / 10;
                p3->next = new ListNode(0);
                p1 = p1->next;
                tmp = p3;
                p3 = p3->next;
            }
        }
        if (carry != 0) {
            p3->val = carry;
        } else {
            tmp->next = nullptr;
        }
        return l3;
    }
};
