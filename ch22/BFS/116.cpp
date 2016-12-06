/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) { return; }
        queue<TreeLinkNode*> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            int size = nodeQueue.size();
            while (size--) {
                auto tmp = nodeQueue.front();
                nodeQueue.pop();
                if (size == 0) { 
                    tmp->next = nullptr;
                } else {
                    tmp->next = nodeQueue.front();
                }
                if (tmp->left != nullptr) {
                    nodeQueue.push(tmp->left);
                    nodeQueue.push(tmp->right);
                }
            }
        }
    }
};