#include "BinarySearchTree.h"

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
	if (isEmpty()){
		return -1;
	}
		
	return findMin(root)->element;
}


const int & BinarySearchTree::findMax() const
{
	if (isEmpty()){
		return -1;
	}
		
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
	//else;  // Duplicate; do nothing
}


void BinarySearchTree::insert(int && x, BinaryNode * & t)
{
	if (t == nullptr)
		t = new BinaryNode{ std::move(x), nullptr, nullptr };
	else if (x < t->element)
		insert(std::move(x), t->left);
	else if (t->element < x)
		insert(std::move(x), t->right);
	//else	;  // Duplicate; do nothing
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

BinaryNode* BinarySearchTree::getOnlyChild(BinaryNode* node) const{
    if (node == nullptr){
		return nullptr;
	}
        
	
	bool leftExists  = (node->left  != nullptr);
    bool rightExists = (node->right != nullptr);
	
	//if node has both children or no children, return nullptr
	if ((leftExists && rightExists) || (!leftExists && !rightExists))
        return nullptr;

	//if node has left child, return left, else if it has right child, return right
    return leftExists ? node->left : node->right; 
}

//public wrapper
int BinarySearchTree::branchCount() const {
    return branchCount(root);   
}
//private method
int BinarySearchTree::branchCount(BinaryNode *t) const{
    if (t == nullptr){
        return 0;
	}
    
	int count = 0;

    // count if special branch
    if (getSpecialBranches(t) != nullptr)
        count++;

    //tree traversal
    count += branchCount(t->left);
    count += branchCount(t->right);

    return count;
}


BinaryNode* BinarySearchTree::getSpecialBranches(BinaryNode* x) const{     
	BinaryNode* a = getOnlyChild(x); //get only child

	if(a != nullptr){ //x only has one child

		BinaryNode* b = getOnlyChild(a); 
		
		// check if b exists
		if (b == nullptr)
			return nullptr;

		// check if b is a leaf
		if (b->left == nullptr && b->right == nullptr) {
			std::cout<<"x: "<<x->element<<std::endl;
			return x;  // x meets the criteria
		} else {
			return nullptr;
		}
	}
	return nullptr; 
}


BinaryNode * BinarySearchTree::clone(BinaryNode *t) const
{
	if (t == nullptr)
		return nullptr;
	else
		return new BinaryNode{ t->element, clone(t->left), clone(t->right) };
}


