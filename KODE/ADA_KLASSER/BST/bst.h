#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <string>
#include <algorithm>

class BST{
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        explicit Node(int d) : data(d), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // helpers
    static Node* insertNode(Node* root, int data);
    static void   inorderTraversal(Node* root);
    static void preorderTraversal(Node* root);
    static void postorderTraversal(Node* root);
    static Node*  searchNode(Node* root, int key);
    static Node*  minValueNode(Node* node);
    static Node*  deleteNode(Node* root, int data);
    static void   destroy(Node* root);
    
    static void printTreeRec(const Node* node, int depth) {
        if (!node) return;
        printTreeRec(node->right, depth + 1);
        for (int i = 0; i < depth; ++i) std::cout << "    ";
        std::cout << node->data << "\n";
        printTreeRec(node->left, depth + 1);
    }

public:
    BST() : root(nullptr) {} //constructor
    ~BST() { destroy(root); } //destructor

 // Safe accessor (doesn't expose mutable internals)
    const Node* getRoot() const { return root; }

    // Public print (no private type in signature)
    void printTree() const { 
        if (!root) { std::cout << "(empty)\n"; return; }
        printTreeRec(root, 0);
    }
    void insert(int value)   { root = insertNode(root, value); }
    void erase(int value)    { root = deleteNode(root, value); }
    bool contains(int key) const { return searchNode(root, key) != nullptr; }
    void inorder() const     { inorderTraversal(root); }
    void preorder() const     { preorderTraversal(root); }
    void postorder() const     { postorderTraversal(root); }
};

#endif