#include "BinarySearchTree.h"


// ---------------- Constructors / Destructor ----------------
// ---------------- BinaryNode constructors ----------------

BinaryNode::BinaryNode(const int& theElement, BinaryNode* lt, BinaryNode* rt)
    : element{theElement}, left{lt}, right{rt}
{
}

BinaryNode::BinaryNode(int&& theElement, BinaryNode* lt, BinaryNode* rt)
    : element{std::move(theElement)}, left{lt}, right{rt}
{
}

BinarySearchTree::BinarySearchTree() : root{nullptr} {}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& rhs) : root{nullptr}
{
    root = clone(rhs.root);
}

BinarySearchTree::BinarySearchTree(BinarySearchTree&& rhs) : root{rhs.root}
{
    rhs.root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
    makeEmpty();
}

// ---------------- Public BST operations ----------------

const int& BinarySearchTree::findMin() const
{
    return findMin(root)->element;
}

const int& BinarySearchTree::findMax() const
{
    return findMax(root)->element;
}

bool BinarySearchTree::contains(const int& x) const
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

void BinarySearchTree::insert(const int& x)
{
    insert(x, root);
}

void BinarySearchTree::insert(int&& x)
{
    insert(std::move(x), root);
}

void BinarySearchTree::remove(const int& x)
{
    remove(x, root);
}

const BinaryNode* BinarySearchTree::getRoot() const
{
    return root;
}

// ---------------- Private BST helpers ----------------

void BinarySearchTree::insert(const int& x, BinaryNode*& t)
{
    if (t == nullptr)
        t = new BinaryNode{x, nullptr, nullptr};
    else if (x < t->element)
        insert(x, t->left);
    else if (t->element < x)
        insert(x, t->right);
}

void BinarySearchTree::insert(int&& x, BinaryNode*& t)
{
    if (t == nullptr)
        t = new BinaryNode{std::move(x), nullptr, nullptr};
    else if (x < t->element)
        insert(std::move(x), t->left);
    else if (t->element < x)
        insert(std::move(x), t->right);
}

void BinarySearchTree::remove(const int& x, BinaryNode*& t)
{
    if (t == nullptr)
        return;

    if (x < t->element)
        remove(x, t->left);
    else if (t->element < x)
        remove(x, t->right);
    else if (t->left && t->right)
    {
        t->element = findMin(t->right)->element;
        remove(t->element, t->right);
    }
    else
    {
        BinaryNode* oldNode = t;
        t = (t->left) ? t->left : t->right;
        delete oldNode;
    }
}

BinaryNode* BinarySearchTree::findMin(BinaryNode* t) const
{
    if (!t) return nullptr;
    while (t->left) t = t->left;
    return t;
}

BinaryNode* BinarySearchTree::findMax(BinaryNode* t) const
{
    if (!t) return nullptr;
    while (t->right) t = t->right;
    return t;
}

bool BinarySearchTree::contains(const int& x, BinaryNode* t) const {
    if (!t) return false;
    if (x < t->element) return contains(x, t->left);
    if (t->element < x) return contains(x, t->right);
    return true;
}

void BinarySearchTree::makeEmpty(BinaryNode*& t) {
    if (t) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

BinaryNode* BinarySearchTree::clone(BinaryNode* t) const {
    if (!t) return nullptr;
    return new BinaryNode{t->element, clone(t->left), clone(t->right)};
}

// ---------------- Traversals ----------------

void BinarySearchTree::inorderTraversal() const {
    inorderTraversal(root);
}

void BinarySearchTree::preorderTraversal() const {
    preorderTraversal(root);
}

void BinarySearchTree::postorderTraversal() const {
    postorderTraversal(root);
}

void BinarySearchTree::levelOrderTraversal() const {
    levelOrderTraversal(root);
}

void BinarySearchTree::inorderTraversal(BinaryNode* t) const {
    if (!t) return;
    inorderTraversal(t->left);
    std::cout << t->element << " ";
    inorderTraversal(t->right);
}

void BinarySearchTree::preorderTraversal(BinaryNode* t) const {
    if (!t) return;
    std::cout << t->element << " ";
    preorderTraversal(t->left);
    preorderTraversal(t->right);
}

void BinarySearchTree::postorderTraversal(BinaryNode* t) const {
    if (!t) return;
    postorderTraversal(t->left);
    postorderTraversal(t->right);
    std::cout << t->element << " ";
}

void BinarySearchTree::levelOrderTraversal(BinaryNode* root) const {
    if (!root)
        return;

    std::queue<BinaryNode*> q;
    q.push(root);

    while (!q.empty())
    {
        BinaryNode* current = q.front();
        q.pop();

        std::cout << current->element << " ";

        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }
}

// ---------------- Branch count ----------------

int BinarySearchTree::branchCount() const {
    return branchCount(root);
}

int BinarySearchTree::branchCount(BinaryNode* t) const
{
    if (!t) return 0;

    int count = 0;
    if ((t->left && !t->right) || (!t->left && t->right))
        count++;

    return count + branchCount(t->left) + branchCount(t->right);
}

// ---------------- findRoute ----------------

std::string BinarySearchTree::findRoute(int value) const
{
    if (!root || !contains(value)) return "";
    return findRoute(root, value);
}

std::string BinarySearchTree::findRoute(BinaryNode* node, int value) const
{
    if (!node) return "";

    if (value == node->element)
        return std::to_string(node->element);

    if (value < node->element)
        return std::to_string(node->element) + " " + findRoute(node->left, value);
    else
        return std::to_string(node->element) + " " + findRoute(node->right, value);
}

// ---------------- Tree printing ----------------

static void printTreeRec(const BinaryNode* node, int depth)
{
    if (!node) return;
    printTreeRec(node->right, depth + 1);
    for (int i = 0; i < depth; ++i) std::cout << "    ";
    std::cout << node->element << "\n";
    printTreeRec(node->left, depth + 1);
}

void BinarySearchTree::printTree() const
{
    if (!root)
    {
        std::cout << "(empty)\n";
        return;
    }
    printTreeRec(root, 0);
}

// ---------------- Stats ----------------
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


// ---------------- 1. Leaves ----------------
std::vector<int> BinarySearchTree::getLeaves() const {
    std::vector<int> leaves;
    getLeaves(root, leaves);
    return leaves;
}

void BinarySearchTree::getLeaves(BinaryNode* node, std::vector<int>& leaves) const {
    if (!node) return;
    if (!node->left && !node->right) {
        leaves.push_back(node->element);
    }
    getLeaves(node->left, leaves);
    getLeaves(node->right, leaves);
}

// ---------------- 2. Nodes at depth ----------------
std::vector<int> BinarySearchTree::getNodesAtDepth(int depth) const {
    std::vector<int> result;
    getNodesAtDepth(root, depth, 0, result);
    return result;
}

void BinarySearchTree::getNodesAtDepth(BinaryNode* node, int depth, int currentDepth, std::vector<int>& result) const {
    if (!node) return;
    if (currentDepth == depth) {
        result.push_back(node->element);
        return;
    }
    getNodesAtDepth(node->left, depth, currentDepth + 1, result);
    getNodesAtDepth(node->right, depth, currentDepth + 1, result);
}

// ---------------- 3. Balanced ----------------
bool BinarySearchTree::isBalanced() const {
    return isBalanced(root);
}

bool BinarySearchTree::isBalanced(BinaryNode* node) const {
    if (!node) return true;

    int leftHeight = getTreeHeight(node->left);
    int rightHeight = getTreeHeight(node->right);

    if (std::abs(leftHeight - rightHeight) > 1) return false;

    return isBalanced(node->left) && isBalanced(node->right);
}

// ---------------- 4. Root-to-leaf paths ----------------
std::vector<std::string> BinarySearchTree::getRootToLeafPaths() const {
    std::vector<std::string> paths;
    getRootToLeafPaths(root, "", paths);
    return paths;
}

void BinarySearchTree::getRootToLeafPaths(BinaryNode* node, std::string path, std::vector<std::string>& paths) const {
    if (!node) return;

    if (!path.empty()) path += " ";
    path += std::to_string(node->element);

    if (!node->left && !node->right) {
        paths.push_back(path);
        return;
    }

    getRootToLeafPaths(node->left, path, paths);
    getRootToLeafPaths(node->right, path, paths);
}

// ---------------- 5. Full nodes ----------------
int BinarySearchTree::fullNodeCount2() const {
    return fullNodeCount2(root);
}

int BinarySearchTree::fullNodeCount2(BinaryNode* node) const {
    if (!node) return 0;

    int count = 0;
    if (node->left && node->right) count = 1;

    return count + fullNodeCount2(node->left) + fullNodeCount2(node->right);
}

// ---------------- 6. Average depth ----------------
double BinarySearchTree::averageDepth() const {
    int totalDepth = getInternalDepth();
    int nodeCount = branchCount() + fullNodeCount2() + getLeaves().size(); // total nodes
    return nodeCount == 0 ? 0.0 : static_cast<double>(totalDepth) / nodeCount;
}

// ---------------- 7. k-th smallest ----------------
std::optional<int> BinarySearchTree::kthSmallest(int k) const {
    int result = 0;
    bool found = false;
    int count = 0;
    inorderTraversalForKth(root, count, k, result, found);
    if (found) return result;
    return std::nullopt;
}

void BinarySearchTree::inorderTraversalForKth(BinaryNode* node, int& count, int k, int& result, bool& found) const {
    if (!node || found) return;

    inorderTraversalForKth(node->left, count, k, result, found);
    count++;
    if (count == k) {
        result = node->element;
        found = true;
        return;
    }
    inorderTraversalForKth(node->right, count, k, result, found);
}

