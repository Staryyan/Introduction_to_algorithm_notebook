/**
 * Binary Search Tree basic method.
 */
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left, *right, *parent;
    TreeNode(int val = 0, TreeNode* parent = nullptr, TreeNode* left = nullptr, TreeNode* right = nullptr) {
        this->val = val;
        this->parent = parent;
        this->left = left;
        this->right = right;
    }
};
class BinarySearchTree {
private:
    TreeNode* root;
    TreeNode* treeSearchImpl(TreeNode* tmp, int key) {
        if (tmp == nullptr || tmp->val == key) { return nullptr; }
        if (tmp->val > key) { return treeSearchImpl(tmp->left, key); }
        if (tmp->val < key) { return treeSearchImpl(tmp->right, key); }
    }
    TreeNode* maximumImpl(TreeNode* _root) {
        TreeNode* tmp = _root;
        while (tmp->right) {
            tmp = tmp->right;
        }
        return tmp;        
    }
    TreeNode* minimumImpl(TreeNode* _root) {
        TreeNode* tmp = _root;
        while (tmp->left) {
            tmp = tmp->left;
        }
        return tmp;
    }
    void transplant(TreeNode* u, TreeNode* v) {
        if (u->parent == nullptr) { root = v;
        } else if (u == u->parent->left) { u->parent->left = v;
        } else { u->parent->right = v; }
        if (v) { v->parent = u->parent; }
    }
public:
    BinarySearchTree() { root = nullptr; }
    TreeNode* treeSearch(int key) {
        return treeSearchImpl(root, key);
    }
    TreeNode* maximun() {
        return maximumImpl(root);
    }
    TreeNode* minimum() {
        return minimumImpl(root);
    }
    TreeNode* treeSuccessorByValue(int key) {
        return treeSuccessorByNode(treeSearch(key));
    }
    /**
     * The node which is the first one larger than key.
     * @param key 
     * @return 
     */
    TreeNode* treeSuccessorByNode(TreeNode* key) {
        if (!key) { return nullptr; }
        if (key->right) { return maximumImpl(key->right); }
        TreeNode* tmp = key->parent;
        while (tmp->parent && tmp->right == key) {
            key = tmp;
            tmp = tmp->parent;
        }
        return tmp;
    }
    TreeNode* treeInsert(int val) {
        if (root == nullptr) {
            root = new TreeNode(val);
            return root;
        }
        TreeNode* p = nullptr, *tmp = root;
        while (tmp) {
            p = tmp;
            if (tmp->val > val) { tmp = tmp->left; }
            else { tmp = tmp->right; }
        }
        TreeNode* newOne = new TreeNode(val, p);
        if (val < p->val) {
            p->left = newOne;
        } else {
            p->right = newOne;
        }
        return newOne;
    }
    void treeDelete(int key) {
        TreeNode* tmp = treeSearch(key);
        if (!tmp->right) { transplant(tmp, tmp->left); }
        else if (!tmp->left) { transplant(tmp, tmp->right); }
        else {
            TreeNode* y = minimumImpl(tmp->right);
            if (tmp->parent != y) {
                transplant(y, y->right);
                y->right = tmp->right;
                y->right->parent = y;
            }
            transplant(tmp, y);
            y->left = tmp->left;
            y->left->parent = y;
        }
    }
};
