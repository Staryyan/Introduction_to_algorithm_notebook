#include "init.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Divide Conquer method.
 */
class Solution {
private:
    ListNode* merge2Lists(ListNode* list1, ListNode* list2) {
        if (!list1) { return list2; }
        if (!list2) { return list1; }
        ListNode* res = new ListNode(0);
        ListNode* curNode = res;
        ListNode* curNode1 = list1, * curNode2 = list2;
        while (curNode1 && curNode2) {
            if (curNode1->val < curNode2->val) {
                curNode->next = curNode1;
                curNode1 = curNode1->next;
            } else {
                curNode->next = curNode2;
                curNode2 = curNode2->next;
            }
            curNode = curNode->next;
        }
        curNode->next = curNode1 ? curNode1 : curNode2;
        return res->next;
    }
    ListNode* mergeKLists(ListNode* lists[], int size) {
        if (size == 0) { return nullptr; }
        if (size == 1) { return lists[0]; }
        if (size == 2) {
            return merge2Lists(lists[0], lists[1]);
        }
        int mid = size >> 1;
        ListNode* subList1 = mergeKLists(lists, mid);
        ListNode* subList2 = mergeKLists(&lists[mid], size - mid);
        return merge2Lists(subList1, subList2);
    }
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return mergeKLists(&lists[0], (int)lists.size());
    }
};

