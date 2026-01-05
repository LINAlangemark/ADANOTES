#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>
#include <algorithm>
#include <iostream>   
#include <sstream>   
#include <vector>
using namespace std;

class BinaryNode
{

public:
	int element;
	BinaryNode *left;
	BinaryNode *right;

	BinaryNode(const int & theElement, BinaryNode *lt, BinaryNode *rt)
		: element{ theElement }, left{ lt }, right{ rt } { }

	BinaryNode(int && theElement, BinaryNode *lt, BinaryNode *rt)
		: element{ std::move(theElement) }, left{ lt }, right{ rt } { }
	
};


class BinarySearchTree
{
public:
	BinarySearchTree(); 
	BinarySearchTree(const BinarySearchTree & rhs); 
	BinarySearchTree(BinarySearchTree && rhs); 
	~BinarySearchTree();
	
	const int & findMin() const;
	const int & findMax() const;
	bool contains(const int & x) const;
	bool isEmpty() const;
	//void printTree() const;
	
	void makeEmpty();
	void insert(const int & x);
	void insert(int && x);
	void remove(const int & x);

	void inorderTraversal() const;
	void preorderTraversal() const;
	void postorderTraversal() const;

	string findRoute(int value) const;

	int getTreeHeight() const; 
	int getInternalDepth() const;

		    // Public print (no private type in signature)
    void printTree() const;
	void insertAVL(int key); 
	void rebalance();
	std::vector<int> toVector() const;

    static void printTreeRec(const BinaryNode* node, int depth) {
        if (!node) return;
        printTreeRec(node->right, depth + 1);
        for (int i = 0; i < depth; ++i) std::cout << "    ";
        std::cout << node->element << "\n";
        printTreeRec(node->left, depth + 1);
    }
	
	BinaryNode* getOnlyChild(BinaryNode* node) const; //PE2
	
	bool hasNoSibling(BinaryNode* child, BinaryNode* parent) const;
	bool isLeaf(BinaryNode* node) const;
	BinaryNode* getRoot() const {
		return root;
	}
	int branchCount() const;   // public wrapper

	BinaryNode* getleaves(BinaryNode* root)const;
	BinaryNode* getSpecialBranches(BinaryNode* root) const;
	//int branchCount(BinaryNode *t) const; 

private:
	BinaryNode *root;
	BinaryNode* rotateLeft(BinaryNode* x);
    BinaryNode* rotateRight(BinaryNode* y);
    BinaryNode* rotateLeftRight(BinaryNode* node);
    BinaryNode* rotateRightLeft(BinaryNode* node);
	BinaryNode* buildAVL(const std::vector<int>& v, int start, int end);
	void toVector(BinaryNode* node, std::vector<int>& v) const;
	int branchCount(BinaryNode* t) const;   // private recursive helper

    int height(BinaryNode* node);
    int getBalance(BinaryNode* node);

    BinaryNode* insertAVL(BinaryNode* node, int key);
    BinaryNode* balance(BinaryNode* node);
	void insert(const int & x, BinaryNode * & t);
	void insert(int && x, BinaryNode * & t);
	void remove(const int & x, BinaryNode * & t);
	BinaryNode * findMin(BinaryNode *t) const;
	BinaryNode * findMax(BinaryNode *t) const;
	

	bool contains(const int & x, BinaryNode *t) const;
	
	void makeEmpty(BinaryNode * & t);
	//void printTree(BinaryNode *t) const;
	BinaryNode * clone(BinaryNode *t) const;

	void inorderTraversal(BinaryNode *t) const;
	void preorderTraversal(BinaryNode *t) const;
	void postorderTraversal(BinaryNode *t) const;

	string findRoute(BinaryNode* node, int value) const;
	int getTreeHeight(BinaryNode* node) const;
	int getInternalDepth(BinaryNode* node, int depth) const;

};

#endif
