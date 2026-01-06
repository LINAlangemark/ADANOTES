#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <vector>
#include <string>
#include <optional>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <queue>
#include <sstream>
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
    /*--------- Additional Exercises ---------*/
    // 1. Get all leaf nodes
    std::vector<int> getLeaves() const;

    // 2. Get all nodes at a specific depth
    std::vector<int> getNodesAtDepth(int depth) const;

    // 3. Check if tree is balanced (AVL style)
    bool isBalanced() const;

    // 4. Get all root-to-leaf paths as strings
    std::vector<std::string> getRootToLeafPaths() const;

    // 5. Count nodes with exactly two children
    int fullNodeCount2() const;

    // 6. Compute average depth of tree
    double averageDepth() const;

    // 7. Find k-th smallest element (1-based)
    std::optional<int> kthSmallest(int k) const;

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
    /*--------- Helpers for Additional Exercises ---------*/
    void getLeaves(BinaryNode* node, std::vector<int>& leaves) const;
    void getNodesAtDepth(BinaryNode* node, int depth, int currentDepth, std::vector<int>& result) const;
    bool isBalanced(BinaryNode* node) const;
    void getRootToLeafPaths(BinaryNode* node, std::string path, std::vector<std::string>& paths) const;
    int fullNodeCount2(BinaryNode* node) const;
    void inorderTraversalForKth(BinaryNode* node, int& count, int k, int& result, bool& found) const;

};

#endif
