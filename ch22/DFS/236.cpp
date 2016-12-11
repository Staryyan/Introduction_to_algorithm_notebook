/**
 * TLE
 */
class Solution {
private:
    bool DFS(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) { return false; }
        queue<TreeNode*> dfsQueue; dfsQueue.push(root);
        bool pExisted = false, qExisted = false;
        while (!dfsQueue.empty()) {
            TreeNode* top = dfsQueue.front();
            dfsQueue.pop();
            if (top == nullptr) { continue; }
            if (top == p) { pExisted = true; }
            if (top == q) { qExisted = true; }
            if (pExisted && qExisted) { break; }
            dfsQueue.push(top->left);
            dfsQueue.push(top->right);
        }
        return pExisted && qExisted;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) { return nullptr; }
        TreeNode* LCA = nullptr;
        queue<TreeNode*> nodeQueue; nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            TreeNode* top = nodeQueue.front();
            nodeQueue.pop();
            if (DFS(top->left, p, q)) {
                LCA = top->left;
                nodeQueue.push(top->left);
                continue;
            }
            if (DFS(top->right, p, q)) {
                LCA = top->right;
                nodeQueue.push(top->right);
                continue;
            }
            break;
        }
        return LCA;
    }
};