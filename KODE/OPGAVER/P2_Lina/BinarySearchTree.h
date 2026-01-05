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
	
	void makeEmpty();
	void insert(const int & x);
	void insert(int && x);
	void remove(const int & x);

	/*------------------------P2 methods-------------------------- */
	int branchCount() const;   // public wrapper
	//branchcount helpers
	BinaryNode* getSpecialBranches(BinaryNode* root) const;
	BinaryNode* getOnlyChild(BinaryNode* node) const; 
	

	
private:
	BinaryNode *root;
	void insert(const int & x, BinaryNode * & t);
	void insert(int && x, BinaryNode * & t);
	void remove(const int & x, BinaryNode * & t);
	BinaryNode * findMin(BinaryNode *t) const;
	BinaryNode * findMax(BinaryNode *t) const;
	bool contains(const int & x, BinaryNode *t) const;
	void makeEmpty(BinaryNode * & t);
	BinaryNode * clone(BinaryNode *t) const;
	string findRoute(BinaryNode* node, int value) const;

	/*------------------------P2 methods-------------------------- */
	int branchCount(BinaryNode* t) const;   // private helper

};

#endif
