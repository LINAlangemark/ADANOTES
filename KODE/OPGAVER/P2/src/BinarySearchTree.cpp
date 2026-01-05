#include "BinarySearchTree.h"

/*---------------------------------------------------- NODE ROTATIONS ----------------------------------------------------*/
void BinarySearchTree::toVector(BinaryNode* node, std::vector<int>& v) const {
    if (!node) return;
    toVector(node->left, v);
    v.push_back(node->element);
    toVector(node->right, v);
}

std::vector<int> BinarySearchTree::toVector() const {
    std::vector<int> v;
    toVector(root, v);
    return v;
}
BinaryNode* BinarySearchTree::buildAVL(const std::vector<int>& v, int start, int end) {
    if (start > end) return nullptr;

    int mid = (start + end) / 2;

    BinaryNode* node = new BinaryNode(v[mid], nullptr, nullptr);
    node->left  = buildAVL(v, start, mid - 1);
    node->right = buildAVL(v, mid + 1, end);

    return node;
}

void BinarySearchTree::rebalance() {
    std::vector<int> v = toVector();
    root = buildAVL(v, 0, v.size() - 1);
}

void BinarySearchTree::insertAVL(int key) {
    root = insertAVL(root, key);
}

BinaryNode* BinarySearchTree::insertAVL(BinaryNode* node, int key) {
    if (!node)
        return new BinaryNode{key, nullptr, nullptr };

    if (key < node->element)
        node->left = insertAVL(node->left, key);
    else
        node->right = insertAVL(node->right, key);

    return balance(node);   // <-- AVL magic
}

BinaryNode* BinarySearchTree::rotateRight(BinaryNode* y) {
    BinaryNode* x = y->left;
    BinaryNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

BinaryNode* BinarySearchTree::rotateLeft(BinaryNode* x) {
    BinaryNode* y = x->right;
    BinaryNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

BinaryNode* BinarySearchTree::rotateLeftRight(BinaryNode* node) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

BinaryNode* BinarySearchTree::rotateRightLeft(BinaryNode* node) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}


int BinarySearchTree::height(BinaryNode* node) {
    if (!node) return 0;
    return 1 + std::max(height(node->left), height(node->right));
}

int BinarySearchTree::getBalance(BinaryNode* node) {
    if (!node) return 0;
    return height(node->left) - height(node->right);
}


BinaryNode* BinarySearchTree::balance(BinaryNode* node) {
    int bf = getBalance(node);
	//std::cout << "Balance factor at " << node->element << " = " << bf << std::endl;
    // Left heavy (LL)
    if (bf > 1 && getBalance(node->left) >= 0){
		std::cout<<"LL: rotate RIGHT"<<std::endl;
		return rotateRight(node);
	}

    // Left–Right (LR)
    if (bf > 1 && getBalance(node->left) < 0){
		std::cout<<"LR: rotate LEFT-RIGHT"<<std::endl;
		return rotateLeftRight(node);
	}
        
    // Right heavy (RR)
    if (bf < -1 && getBalance(node->right) <= 0){
		std::cout<<"RR: rotate LEFT"<<std::endl;
		return rotateLeft(node);
	}
        
    // Right–Left (RL)
    if (bf < -1 && getBalance(node->right) > 0){
		std::cout<<"RL: rotate RIGHT-LEFT"<<std::endl;
		return rotateRightLeft(node);
	}
        
    return node;  // already balanced
}


/*------------------------------------------------------------------------------------------------------------------------*/

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

/*void BinarySearchTree::printTree() const
{
	if (isEmpty())
		cout << "Empty tree" << endl;
	else
		printTree(root);
}*/

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
/*BinaryNode* BinarySearchTree::getOnlyChild(BinaryNode* node) const{
	BinaryNode* onlychild = nullptr;
	
	if((node->left && node->right) || node == nullptr){
		return onlychild;
	} else if (node->left == nullptr) {
		onlychild = node->right;
	} else {
		onlychild = node->left;
	}

	return onlychild;
}


bool BinarySearchTree::hasNoSibling(BinaryNode* child, BinaryNode* parent) const {
    if (parent == nullptr) 
        return false;

    if (parent->left == child && parent->right == nullptr) 
        return true;

    if (parent->right == child && parent->left == nullptr) 
        return true;

    return false;
}



*/

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
	return nullptr; //end of line?
}


/*void BinarySearchTree::printTree(BinaryNode *t) const
{

	if (t != nullptr)
	{
		printTree(t->left);
		cout << t->element << endl;
		printTree(t->right);
	}
}
*/
void BinarySearchTree::printTree() const
{
    if (!root) {
        std::cout << "(empty)\n";
        return;
    }
    printTreeRec(root, 0);
}

BinaryNode * BinarySearchTree::clone(BinaryNode *t) const
{
	if (t == nullptr)
		return nullptr;
	else
		return new BinaryNode{ t->element, clone(t->left), clone(t->right) };
}

//-------------access points to start from root----------------------
void BinarySearchTree::inorderTraversal() const //const so we can call it like tree.inorderTraversal from main
{
    inorderTraversal(root);
}

void BinarySearchTree::preorderTraversal() const
{
    preorderTraversal(root);
}

void BinarySearchTree::postorderTraversal() const
{
    postorderTraversal(root);
}

//------------------recursive private member functions---------------------

// Function to do inorder traversal of BST
void BinarySearchTree::inorderTraversal(BinaryNode *t) const //const so we can call from public accessors
{
    if (t != nullptr) {
        inorderTraversal(t->left);
        std::cout << t->element << " ";
        inorderTraversal(t->right);
    }
}



// Function to do preorder traversal of BST
void BinarySearchTree::preorderTraversal(BinaryNode *t) const
{   
    if(!t)return;
    std::cout <<t->element << " ";
    preorderTraversal(t->left);        
    preorderTraversal(t->right);
            

}

// Function to do postorder traversal of BST
void BinarySearchTree::postorderTraversal(BinaryNode *t) const
{   
    if(!t)return;
    postorderTraversal(t->left);        
    postorderTraversal(t->right);
    std::cout <<t->element << " ";            
    
}

string BinarySearchTree::findRoute(int value) const
{ 
    if (!contains(value) || root == nullptr) {
        return "";            
    }

  
    return findRoute(root, value);  // use and return what helper gives
}

string BinarySearchTree::findRoute(BinaryNode* node, int value) const{
    
	if (node == nullptr){
		return ""; //base case
	} 
	if (value == node->element) {
		return std::to_string(node->element);
	}

	std::string route;

	if (value < node->element){
		route = std::to_string(node->element) + " " + findRoute(node->left, value);
	} else {
		route = std::to_string(node->element) + " " + findRoute(node->right, value);
	} 

	return route;
} 


int BinarySearchTree::getTreeHeight() const {
    return getTreeHeight(root);
}

int BinarySearchTree::getTreeHeight(BinaryNode* node) const {
    if (node == nullptr) {
        return -1;  // empty node, go 1 step back 
    }

    int leftHeight  = getTreeHeight(node->left);
    int rightHeight = getTreeHeight(node->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight); //root is 1
}

int BinarySearchTree::getInternalDepth() const {
    return getInternalDepth(root, 0);   // root has depth 0
}

int BinarySearchTree::getInternalDepth(BinaryNode* node, int depth) const {
    if (node == nullptr) {
        return 0;
    }

	depth = depth + getInternalDepth(node->left,  depth + 1) + getInternalDepth(node->right, depth + 1);	

    return depth;
}
