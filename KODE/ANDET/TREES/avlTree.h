#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "BinarySearchTree.h"
#include <string>

class AVLNode
{
public:
    int element;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int value, AVLNode* l = nullptr, AVLNode* r = nullptr, int h = 0);
};

class AVLTree
{
public:
    AVLTree();
    AVLTree(const AVLTree& rhs);
    AVLTree(AVLTree&& rhs);
    ~AVLTree();

    bool isEmpty() const;
    bool contains(int x) const;

    void insert(int x);
    void remove(int x);
    void makeEmpty();

    void inorderTraversal() const;
    void preorderTraversal() const;
    void postorderTraversal() const;
    void levelorderTraversal() const;

    // Build AVL from existing BST
    void buildFromBST(const BinarySearchTree& bst);

    // Rebalance entire tree (no insert/delete)
    void rebalance();


    // --- Debug control ---
    void setDebug(bool enable);

    void printTree() const;

private:
    AVLNode* root;
    bool debug;   //DEBUG FLAG

    /* Core helpers */
    void insert(int x, AVLNode*& t);
    void remove(int x, AVLNode*& t);
    bool contains(int x, AVLNode* t) const;
    void makeEmpty(AVLNode*& t);
    AVLNode* clone(AVLNode* t) const;

    /* AVL logic */
    int height(AVLNode* t) const;
    int balanceFactor(AVLNode* t) const;
    void balance(AVLNode*& t);

    /* Rotations */
    void rotateWithLeftChild(AVLNode*& k2);
    void rotateWithRightChild(AVLNode*& k1);
    void doubleWithLeftChild(AVLNode*& k3);
    void doubleWithRightChild(AVLNode*& k1);

    /* Traversal helpers */
    void inorderTraversal(AVLNode* t) const;
    void preorderTraversal(AVLNode* t) const;
    void postorderTraversal(AVLNode* t) const;
    void levelorderTraversal(AVLNode* t) const;

    AVLNode* cloneFromBST(const BinaryNode* bstNode);
    void rebalance(AVLNode*& t);
};

#endif
