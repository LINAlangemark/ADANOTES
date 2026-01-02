#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <string>

class BinaryNode
{
public:
    int element;
    BinaryNode* left;
    BinaryNode* right;

    BinaryNode(const int& theElement, BinaryNode* lt, BinaryNode* rt);
    BinaryNode(int&& theElement, BinaryNode* lt, BinaryNode* rt);
};

class BinarySearchTree
{
public:
    /*--------- Original Methods ---------*/
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree& rhs);
    BinarySearchTree(BinarySearchTree&& rhs);
    ~BinarySearchTree();

    const int& findMin() const;
    const int& findMax() const;
    bool contains(const int& x) const;
    bool isEmpty() const;

    void makeEmpty();
    void insert(const int& x);
    void insert(int&& x);
    void remove(const int& x);

    /*--------- Tree Traversal ---------*/
    void inorderTraversal() const;
    void preorderTraversal() const;
    void postorderTraversal() const;
    void levelOrderTraversal() const;

    /*--------- Tree Stats ---------*/
    int branchCount() const;
	int getTreeHeight() const;
	int getInternalDepth() const; //path length 


    /*--------- Helpers ---------*/
    std::string findRoute(int value) const;    
    void printTree() const;

    // --- Accessor for read-only tree traversal (used by AVL) ---
    const BinaryNode* getRoot() const;

private:
    BinaryNode* root;

    /*--------- Original Methods ---------*/
    void insert(const int& x, BinaryNode*& t);
    void insert(int&& x, BinaryNode*& t);
    void remove(const int& x, BinaryNode*& t);

    BinaryNode* findMin(BinaryNode* t) const;
    BinaryNode* findMax(BinaryNode* t) const;
    bool contains(const int& x, BinaryNode* t) const;
    void makeEmpty(BinaryNode*& t);
    BinaryNode* clone(BinaryNode* t) const;

    /*--------- Tree Traversal ---------*/ //depth-first traversals
    void inorderTraversal(BinaryNode* t) const;
    void preorderTraversal(BinaryNode* t) const;
    void postorderTraversal(BinaryNode* t) const;
    void levelOrderTraversal(BinaryNode* root) const;

    /*--------- Tree Stats ---------*/
    int getTreeHeight(BinaryNode* node) const;
    int getInternalDepth(BinaryNode* node, int depth) const;
    int branchCount(BinaryNode* t) const;

    /*--------- Helpers ---------*/
    std::string findRoute(BinaryNode* node, int value) const; //breadth-first traversal
};

#endif
