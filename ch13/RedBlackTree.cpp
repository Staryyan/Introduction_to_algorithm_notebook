#include <iostream>
using namespace std;
enum Color { RED, BLACK };
struct TreeNode {
    int val;
    TreeNode* left, *right, *parent;
    Color color;
    TreeNode(int val, TreeNode* left = nullptr, TreeNode* right = nullptr, TreeNode* parent = nullptr, Color color = RED) {
        this->val = val;
        this->left = left;
        this->right = right;
        this->parent = parent;
        this->color = color;
    }
};

class RedBlackTree {
private:
    TreeNode* root;
    TreeNode* searchImpl(TreeNode* root, int key) {
        if (!root) { return nullptr; }
        if (root->val == key) { return root; }
        else if (root->val > key) { return searchImpl(root->left, key); }
        else { return searchImpl(root->right, key); }
    }
    void leftRotate(TreeNode* ptr) {
        TreeNode* rightDown = ptr->right;
        ptr->right = rightDown->left;
        if (rightDown->left) {
            rightDown->left->parent = ptr;
        }
        rightDown->parent = ptr->parent;
        if (!ptr->parent) {
            root = rightDown;
        } else if (ptr == ptr->parent->left) {
            ptr->parent->left = rightDown;
        } else {
            ptr->parent->right = rightDown;
        }
        rightDown->left = ptr;
        ptr->parent = rightDown;
    }
    void rightRotate(TreeNode* ptr) {
        TreeNode* leftDown = ptr->left;
        ptr->left = leftDown->right;
        if (leftDown->left) {
            leftDown->right->parent = ptr;
        }
        leftDown->parent = ptr->parent;
        if (!ptr->parent) {
            root = leftDown;
        } else if (ptr == ptr->parent->left) {
            ptr->parent->left = leftDown;
        } else {
            ptr->parent->right = leftDown;
        }
        leftDown->right = ptr;
        ptr->parent = leftDown;
    }
    /**
     * Fix up the problem caused by insert new TreeNode.
     * Only 6 situation. 3 for right, 3 for left.
     * @param one
     */
    void RB_INSERT_FIXUP(TreeNode* one) {
        while (one->parent->color == RED) {
            if (one->parent->parent->left == one->parent) {
                TreeNode* y = one->parent->parent->right;
                if (y->color == RED) {
                    y->color = BLACK;
                    one->parent->color = BLACK;
                    one->parent->parent->color = RED;
                    one = one->parent->parent;
                } else if (one->parent->right == one) {
                    one = one->parent;
                    leftRotate(one);
                } else {
                    one->parent->color = BLACK;
                    one->parent->parent->color = RED;
                    rightRotate(one->parent->parent);
                }
            } else {
                TreeNode* y = one->parent->parent->left;
                if (y->color == RED) {
                    one->parent->color = BLACK;
                    one->parent->parent->color = RED;
                    y->color = BLACK;
                    one = one->parent->parent;
                } else if (one->parent->left == one) {
                    one = one->parent;
                    rightRotate(one);
                } else {
                    one->parent->color = BLACK;
                    one->parent->parent->color = RED;
                    leftRotate(one->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }
    TreeNode* minimumImpl(TreeNode* root) {
        if (!root) { return nullptr; }
        return minimumImpl(root->left);
    }
    void transplant(TreeNode* u, TreeNode* v) {
        if (!u->parent) { root = v; }
        else if (u->parent->left == u) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }
    void RB_DELETE_FIXUP(TreeNode* one) {
        while (one != root && one->color == BLACK) {
            if (one == one->parent->left) {
                TreeNode* w = one->parent->right;
                if (w->color == RED) {
                    w->color = BLACK;
                    w->parent->color = RED;
                    leftRotate(one->parent);
                    w = one->parent->right;
                }
                if (w->left->color == BLACK && w->right->color ==BLACK) {
                    w->color = RED;
                    one = one->parent;
                } else if (w->right->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    rightRotate(w);
                    w = one->parent->left;
                } else {
                    w->color = one->parent->color;
                    one->parent->color = BLACK;
                    w->right->color = BLACK;
                    leftRotate(one->parent);
                    one = root;
                }
            } else {
                TreeNode* w = one->parent->left;
                if (w->color == RED) {
                    w->color = BLACK;
                    w->parent->color = RED;
                    rightRotate(one->parent);
                    w = one->parent->left;
                }
                if (w->right->color == BLACK && w->left->color == BLACK) {
                    w->color = RED;
                    one = one->parent;
                } else if (w->left->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    leftRotate(w);
                    w = one->parent->right;
                } else {
                    w->color = one->parent->color;
                    one->parent->color = BLACK;
                    w->left->color = BLACK;
                    rightRotate(one->parent);
                    one = root;
                }
            }
        }
        one->color = BLACK;
    }
public:
    RedBlackTree() { root = nullptr; }
    /**
     * FInd the position to insert and set the new node as red, and then fix uo the problem
     * by calling RE_INSERT_FIXUP.
     * @param key
     */
    TreeNode* treeSearch(int key) {
        return searchImpl(root, key);
    }
    void treeInsert(int key) {
        if (!root) { root = new TreeNode(key); }
        TreeNode* tmpParent = nullptr;
        TreeNode* tmp = root;
        while (tmp) {
            tmpParent = tmp;
            if (tmp->val < key) { tmp = tmp->right; }
            else { tmp = tmp->left; }
        }
        TreeNode* newOne = new TreeNode(key);
        newOne->parent = tmpParent;
        if (tmpParent->val > key) {
            tmpParent->left = newOne;
        } else {
            tmpParent->right = newOne;
        }
        RB_INSERT_FIXUP(newOne);
    }
    TreeNode* minimum() {
        return minimumImpl(root);
    }
    void treeDelete(int key) {
        TreeNode* delOne = treeSearch(key);
        if (!delOne) { return; }
        TreeNode* y = delOne;
        Color yOrginalColor = y->color;
        TreeNode* x = nullptr;
        if (!delOne->left) {
            x = delOne->right;
            transplant(delOne, delOne->right);
        } else if (!delOne->right) {
            x = delOne->left;
            transplant(delOne, delOne->left);
        } else {
            y = minimumImpl(delOne->right);
            yOrginalColor = y->color;
            x = y->right;
            if (y->parent == delOne) {
                x->parent = y;
            } else {
                transplant(y, y->right);
                y->right = delOne->right;
                y->right->parent = y;
            }
            transplant(delOne, y);
            y->left = delOne->left;
            y->left->parent = y;
            y->color = delOne->color;
        }
        if (yOrginalColor == BLACK) {
            RB_DELETE_FIXUP(x);
        }
    }
};
