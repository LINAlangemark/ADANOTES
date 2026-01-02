#include "avlTree.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <algorithm>
#include <queue>

/*---------- Constructors & Desctuctor ----------*/
AVLNode::AVLNode(int value, AVLNode* l, AVLNode* r, int h) : element(value), left(l), right(r), height(h) {}

AVLTree::AVLTree() : root(nullptr), debug(false) {}

AVLTree::~AVLTree()
{
    makeEmpty();
}

void AVLTree::setDebug(bool enable)
{
    debug = enable;
}


/*---------- Helpers ----------*/
int AVLTree::height(AVLNode* t) const
{
    return t == nullptr ? -1 : t->height;
}

int AVLTree::balanceFactor(AVLNode* t) const
{
    return height(t->left) - height(t->right);
}

/*---------- Rotations ----------*/
void AVLTree::rotateWithLeftChild(AVLNode*& k2)
{
    AVLNode* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = std::max(height(k2->left), height(k2->right)) + 1;
    k1->height = std::max(height(k1->left), height(k1->right)) + 1;

    k2 = k1;
}

void AVLTree::rotateWithRightChild(AVLNode*& k1)
{
    AVLNode* k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = std::max(height(k1->left), height(k1->right)) + 1;
    k2->height = std::max(height(k2->left), height(k2->right)) + 1;

    k1 = k2;
}


/*---------- Double Rotations ----------*/
void AVLTree::doubleWithLeftChild(AVLNode*& k3)
{
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

void AVLTree::doubleWithRightChild(AVLNode*& k1)
{
    rotateWithLeftChild(k1->right);
    rotateWithRightChild(k1);
}

/*---------- Balance Methods ----------*/
static const char* imbalanceName(int bf, int childBF)
{
    if (bf > 1 && childBF >= 0) return "LL (Left-Left)";
    if (bf > 1 && childBF < 0)  return "LR (Left-Right)";
    if (bf < -1 && childBF <= 0) return "RR (Right-Right)";
    if (bf < -1 && childBF > 0)  return "RL (Right-Left)";
    return "Balanced / Unknown";
}


void AVLTree::balance(AVLNode*& t)
{
    if (!t) return;

    int bf = balanceFactor(t);

    // -------- DEBUG + VISUALISERING --------
    if (std::abs(bf) > 1 && debug)
    {
        std::cout << "\n=== AVL IMBALANCE DETECTED ===\n";
        std::cout << "At node: " << t->element << "\n";
        std::cout << "Balance factor: " << bf << "\n";

        int childBF = (bf > 1)
                        ? balanceFactor(t->left)
                        : balanceFactor(t->right);

        std::cout << "Imbalance type: "
                  << imbalanceName(bf, childBF) << "\n";

        std::cout << "\nTree BEFORE rotation:\n";
        printTree();
        std::cout << "-----------------------------\n";

        // ---------- LEFT HEAVY ----------
        if (bf > 1)
        {
            // LL
            if (balanceFactor(t->left) >= 0)
            {
                std::cout << "Performing RIGHT rotation (LL)\n";
                rotateWithLeftChild(t);

                std::cout << "\nTree AFTER rotation:\n";
                printTree();
            }
            // LR
            else
            {
                std::cout << "Performing LEFT-RIGHT rotation (LR)\n";

                std::cout << "\nStep 1: LEFT rotation on left child ("
                          << t->left->element << ")\n";
                rotateWithRightChild(t->left);

                std::cout << "Tree AFTER step 1:\n";
                printTree();
                std::cout << "-----------------------------\n";

                std::cout << "Step 2: RIGHT rotation on node ("
                          << t->element << ")\n";
                rotateWithLeftChild(t);

                std::cout << "Tree AFTER step 2:\n";
                printTree();
            }
        }
        // ---------- RIGHT HEAVY ----------
        else
        {
            // RR
            if (balanceFactor(t->right) <= 0)
            {
                std::cout << "Performing LEFT rotation (RR)\n";
                rotateWithRightChild(t);

                std::cout << "\nTree AFTER rotation:\n";
                printTree();
            }
            // RL
            else
            {
                std::cout << "Performing RIGHT-LEFT rotation (RL)\n";

                std::cout << "\nStep 1: RIGHT rotation on right child ("
                          << t->right->element << ")\n";
                rotateWithLeftChild(t->right);

                std::cout << "Tree AFTER step 1:\n";
                printTree();
                std::cout << "-----------------------------\n";

                std::cout << "Step 2: LEFT rotation on node ("
                          << t->element << ")\n";
                rotateWithRightChild(t);

                std::cout << "Tree AFTER step 2:\n";
                printTree();
            }
        }

        std::cout << "===============================\n\n";
    }
    // -------- NORMAL AVL (NO DEBUG) --------
    else
    {
        if (bf > 1)
        {
            if (balanceFactor(t->left) >= 0)
                rotateWithLeftChild(t);
            else
                doubleWithLeftChild(t);
        }
        else if (bf < -1)
        {
            if (balanceFactor(t->right) <= 0)
                rotateWithRightChild(t);
            else
                doubleWithRightChild(t);
        }
    }

    // -------- UPDATE HEIGHT --------
    t->height = std::max(height(t->left), height(t->right)) + 1;
}



/*---------- AVL Insert ----------*/
void AVLTree::insert(int x, AVLNode*& t)
{
    if (!t)
        t = new AVLNode(x);
    else if (x < t->element)
        insert(x, t->left);
    else if (t->element < x)
        insert(x, t->right);

    balance(t);
}

void AVLTree::insert(int x)
{
    insert(x, root);
}

/*---------- Basic Tree Functionality ----------*/
bool AVLTree::contains(int x) const
{
    return contains(x, root);
}

bool AVLTree::contains(int x, AVLNode* t) const
{
    if (!t) return false;
    if (x < t->element) return contains(x, t->left);
    if (t->element < x) return contains(x, t->right);
    return true;
}

void AVLTree::makeEmpty(AVLNode*& t)
{
    if (!t) return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
    t = nullptr;
}

void AVLTree::makeEmpty()
{
    makeEmpty(root);
}

/*----------  Tree Traversals ----------*/


void AVLTree::inorderTraversal() const
{
    inorderTraversal(root);
}

void AVLTree::preorderTraversal() const
{
    preorderTraversal(root);
}

void AVLTree::postorderTraversal() const
{
    postorderTraversal(root);
}

void AVLTree::levelorderTraversal() const
{
    levelorderTraversal(root);
}

void AVLTree::inorderTraversal(AVLNode* t) const
{
    if (!t) return;
    inorderTraversal(t->left);
    std::cout << t->element << " ";
    inorderTraversal(t->right);
}

void AVLTree::preorderTraversal(AVLNode* t) const
{
    if (!t) return;
    std::cout << t->element << " ";
    preorderTraversal(t->left);
    preorderTraversal(t->right);
}

void AVLTree::postorderTraversal(AVLNode* t) const
{
    if (!t) return;
    postorderTraversal(t->left);
    postorderTraversal(t->right);
    std::cout << t->element << " ";
}

void AVLTree::levelorderTraversal(AVLNode* root) const
{
    if (!root)
        return;

    std::queue<AVLNode*> q;
    q.push(root);

    while (!q.empty())
    {
        AVLNode* current = q.front();
        q.pop();

        std::cout << current->element << " ";

        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }
}

/*----------  Built AVL from BST ----------*/
void AVLTree::buildFromBST(const BinarySearchTree& bst)
{
    makeEmpty();
    root = cloneFromBST(bst.getRoot());  // kræver evt. const getter
}


AVLNode* AVLTree::cloneFromBST(const BinaryNode* bstNode)
{
    if (!bstNode) return nullptr;

    AVLNode* node = new AVLNode(bstNode->element);
    node->left  = cloneFromBST(bstNode->left);
    node->right = cloneFromBST(bstNode->right);

    node->height = std::max(height(node->left), height(node->right)) + 1;
    return node;
}


void AVLTree::rebalance(AVLNode*& t)
{
    if (!t) return;

    // først børn (postorder!)
    rebalance(t->left);
    rebalance(t->right);

    // opdater højde før balance
    t->height = std::max(height(t->left), height(t->right)) + 1;

    // brug din eksisterende AVL-logik
    balance(t);
}

void AVLTree::rebalance()
{
    rebalance(root);
}



/*----------  Tree Printing ----------*/
static void printTreeRec(const AVLNode* node, int depth)
{
    if (!node) return;

    printTreeRec(node->right, depth + 1);

    for (int i = 0; i < depth; ++i)
        std::cout << "    ";

    std::cout << node->element << "\n";

    printTreeRec(node->left, depth + 1);
}

void AVLTree::printTree() const
{
    if (!root)
    {
        std::cout << "(empty)\n";
        return;
    }
    printTreeRec(root, 0);
}
