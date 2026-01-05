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

int BinarySearchTree::height() const {
	return height(root);
}

int BinarySearchTree::height(BinaryNode *t) const{
	if (t == nullptr)
		return -1;
	else
		return 1 + max(height(t->left), height(t->right));
}

int BinarySearchTree::noOfNodes()const {
	return noOfNodes(root);
}

int BinarySearchTree::noOfNodes(BinaryNode *t) const{
	if (t == nullptr)
		return 0;
	else
		return 1 + noOfNodes(t->left) + noOfNodes(t->right);
}

bool BinarySearchTree::minimalHeight() const{
	   return minimalHeight(root);
}

bool BinarySearchTree::minimalHeight(BinaryNode *t) const{
	//find tree height
	int h = height();
	
	//find number of nodes
	int n = noOfNodes();
	
	std::cout<<"n: "<<n<<std::endl;
	int p = 1; //2-tals-potens
	int k = 0; //eksponent [tæller]

	//find next power of two
   	while (p < n+1) { //potens skal bare være mindre end number of nodes
    p *= 2;           // næste 2-potens
    ++k;              // eksponent stiger
	}
	std::cout<<"p: "<<p<<std::endl;
	
	//subtract one
	k = k-1;
	std::cout<<"k: "<<k<<std::endl;

	//compare to height
	if(h == k){
		return true;
	}
	return false;
}

