#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>
#include <algorithm>
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

    //BinaryNode(int element, BinaryNode*left = nullptr, BinaryNode *right = nullptr)
            //: element{element}, left{left}, right{right} {}
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
	void printTree() const;
	
	void makeEmpty();
	void insert(const int & x);
	void insert(int && x);
	void remove(const int & x);
	void inOrder(BinaryNode *t);
	void preOrder(BinaryNode *t);
	void postOrder(BinaryNode *t);
	void levelOrder(BinaryNode *t);

	int countNodes(BinaryNode *root){
            if(root ==nullptr) return 0;
            return 1 + countNodes(root->left) + countNodes(root->right);
        }

    int countLeaves(BinaryNode *root){
            if(root == nullptr) return 0;
            if(root -> left == nullptr && root -> right == nullptr) return 1;
            return countLeaves(root -> left) + countLeaves(root -> right);
        }

    int countFullNodes(BinaryNode *root){
            if(root == nullptr) return 0;
            int count = 0;
            if(root -> left != nullptr && root -> right != nullptr) count = 1;
            return count + countFullNodes(root -> left) + countFullNodes(root -> right);
        }
	
private:
	BinaryNode *root;

	void insert(const int & x, BinaryNode * & t);
	void insert(int && x, BinaryNode * & t);
	void remove(const int & x, BinaryNode * & t);
	BinaryNode * findMin(BinaryNode *t) const;
	BinaryNode * findMax(BinaryNode *t) const;
	
	bool contains(const int & x, BinaryNode *t) const;
	
	void makeEmpty(BinaryNode * & t);
	void printTree(BinaryNode *t) const;
	BinaryNode * clone(BinaryNode *t) const;
	void inOrder(BinaryNode *t) const;
	void preOrder(BinaryNode *t) const;
	void postOrder(BinaryNode *t) const;
	void levelOrder(BinaryNode *t) const;
	
};

#endif
