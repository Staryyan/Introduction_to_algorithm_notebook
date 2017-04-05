#include "init.h"
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) { return head; }
        RandomListNode* copyHead, *p1, *p2;
        for (p1 = head; p1; p1 = p1->next->next) {
            p2 = new RandomListNode(p1->label);
            p2->next = p1->next;
            p1->next = p2;
        }
        copyHead = head->next;
        for (p1 = head; p1; p1 = p1->next->next) {
            if (p1->random) {
                p1->next->random = p1->random->next;
            }
        }
        for (p1 = head; p1; p1 = p1->next) {
            p2 = p1->next;
            p1->next = p2->next;
            if (p2->next) {
                p2->next = p2->next->next;
            }
        }
        return copyHead;
    }
};