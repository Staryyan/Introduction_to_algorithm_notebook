/**
 * differ from 2.cpp
 */
class Solution {
private:
    int getLen(ListNode* l1) {
        ListNode* tmp = l1;
        int num = 0;
        while (tmp) {
            num++;
            tmp = tmp->next;
        }
        return num;
    }
    ListNode* helper(ListNode* l1, ListNode* l2, int offset) {
        if (!l1) { return nullptr; }
        ListNode* result = offset == 0 ? new ListNode(l1->val + l2->val) : new ListNode(l1->val);
        ListNode* post = offset == 0 ? helper(l1->next, l2->next, 0) : helper(l1->next, l2, offset - 1);
        if (post && post->val > 9) {
            post->val %= 10;
            result->val++;
        }
        result->next = post;
        return result;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = getLen(l1);
        int len2 = getLen(l2);
        ListNode* head = new ListNode(1);
        head->next = len1 < len2 ? helper(l2, l1, len2 - len1) : helper(l1, l2, len1 - len2);
        if (head->next->val > 9) {
            head->next->val %= 10;
            return head;
        }
        return head->next;
    }
};