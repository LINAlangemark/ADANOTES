#include "BinarySearchTree.h"
#include <bits/stdc++.h>

BinarySearchTree::BinarySearchTree() : root{ nullptr }
{
}


BinarySearchTree::BinarySearchTree(const BinarySearchTree & rhs) : root{ nullptr }
{
	root = clone(rhs.root);
}


BinarySearchTree::BinarySearchTree(BinarySearchTree && rhs) : root{ rhs.root }
{
	rhs.root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
	makeEmpty();
}

const int & BinarySearchTree::findMin() const
{
	if (isEmpty())
		return -1;
	return findMin(root)->element;
}


const int & BinarySearchTree::findMax() const
{
	if (isEmpty())
		return -1;
	return findMax(root)->element;
}

bool BinarySearchTree::contains(const int & x) const
{
	return contains(x, root);
}

bool BinarySearchTree::isEmpty() const
{
	return root == nullptr;
}

void BinarySearchTree::printTree() const
{
	if (isEmpty())
		cout << "Empty tree" << endl;
	else
		printTree(root);
}

void BinarySearchTree::makeEmpty()
{
	makeEmpty(root);
}


void BinarySearchTree::insert(const int & x)
{
	insert(x, root);
}

void BinarySearchTree::insert(int && x)
{
	insert(std::move(x), root);
}

void BinarySearchTree::remove(const int & x)
{
	remove(x, root);
}

void BinarySearchTree::insert(const int & x, BinaryNode * & t)
{
	if (t == nullptr)
		t = new BinaryNode{ x, nullptr, nullptr };
	else if (x < t->element)
		insert(x, t->left);
	else if (t->element < x)
		insert(x, t->right);
	else
		;  // Duplicate; do nothing
}


void BinarySearchTree::insert(int && x, BinaryNode * & t)
{
	if (t == nullptr)
		t = new BinaryNode{ std::move(x), nullptr, nullptr };
	else if (x < t->element)
		insert(std::move(x), t->left);
	else if (t->element < x)
		insert(std::move(x), t->right);
	else
		;  // Duplicate; do nothing
}

void BinarySearchTree::remove(const int & x, BinaryNode * & t)
{
	if (t == nullptr)
		return;   // Item not found; do nothing
	if (x < t->element)
		remove(x, t->left);
	else if (t->element < x)
		remove(x, t->right);
	else if (t->left != nullptr && t->right != nullptr) // Two children
	{
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else
	{
		BinaryNode *oldNode = t;
		t = (t->left != nullptr) ? t->left : t->right;
		delete oldNode;
	}
}

BinaryNode * BinarySearchTree::findMin(BinaryNode *t) const
{
	if (t == nullptr)
		return nullptr;
	if (t->left == nullptr)
		return t;
	return findMin(t->left);
}

BinaryNode * BinarySearchTree::findMax(BinaryNode *t) const
{
	if (t != nullptr)
		while (t->right != nullptr)
			t = t->right;
	return t;
}

bool BinarySearchTree::contains(const int & x, BinaryNode *t) const
{
	if (t == nullptr)
		return false;
	else if (x < t->element)
		return contains(x, t->left);
	else if (t->element < x)
		return contains(x, t->right);
	else
		return true;    // Match
}

void BinarySearchTree::makeEmpty(BinaryNode * & t)
{
	if (t != nullptr)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = nullptr;
}


void BinarySearchTree::printTree(BinaryNode *t) const
{
	if (t != nullptr)
	{
		printTree(t->left);
		cout << t->element << endl;
		printTree(t->right);
	}
}

void BinarySearchTree::inOrder(BinaryNode* root){
	// Empty tree
	if(root == nullptr){
		return;
	}

	// Recur on left subtree
	inOrder(root->left);

	// Visit the current node
	cout << root->element << endl;

	//Recur on the right subtree
	inOrder(root->right);
}

void BinarySearchTree::preOrder(BinaryNode* root){
	// Empty tree
	if(root == nullptr){
		return;
	}

	// Visit the current node
	cout << root->element << endl;

	// Recur on left subtree
	preOrder(root->left);

	//Recur on the right subtree
	preOrder(root->right);
}

void BinarySearchTree::postOrder(BinaryNode* root){
	// Empty tree
	if(root == nullptr){
		return;
	}

	// Recur on left subtree
	postOrder(root->left);

	//Recur on the right subtree
	postOrder(root->right);

	// Visit the current node
	cout << root->element << endl;
}

void BinarySearchTree::levelOrder(BinaryNode* root){
	// Empty tree
	if(root == nullptr){
		return;
	}

	// Create an empty queue for level order traversal
	std::queue<BinaryNode*> q;

	// Enqueue root and initialize height
	q.push(root);

	while(!q.empty()){
		// Print front of queue and remove it from queue
		BinaryNode* node = q.front();
		cout << node->element << endl;
		q.pop();

		// Enqueue left child
		if(node->left != nullptr){
			q.push(node->left);
		}

		// Enqueue right child
		if(node->right != nullptr){
			q.push(node->right);
		}
	}
}

BinaryNode * BinarySearchTree::clone(BinaryNode *t) const
{
	if (t == nullptr)
		return nullptr;
	else
		return new BinaryNode{ t->element, clone(t->left), clone(t->right) };
}