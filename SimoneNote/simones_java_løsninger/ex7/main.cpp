// Skriv metode til pre-order, in-order, post-order og level order traversering af binære (søge træer).
#include <iostream>
#include "BinarySearchTree.h"
#include "BinaryHeap.h"
#include "dsexceptions.h"
using namespace std;

/*// In-order
int main(){
    BinarySearchTree tree;
    BinaryNode *root = new BinaryNode(1, new BinaryNode(2, nullptr, nullptr), new BinaryNode(3, nullptr, nullptr));
    tree.inOrder(root);
    return 0;
}*/

/*// Pre-order
int main(){
    BinarySearchTree tree;
    BinaryNode *root = new BinaryNode(1, new BinaryNode(2, nullptr, nullptr), new BinaryNode(3, nullptr, nullptr));
    tree.preOrder(root);
    return 0;
}*/

// Post-order
/*int main(){
    BinarySearchTree tree;
    BinaryNode *root = new BinaryNode(1, new BinaryNode(2, nullptr, nullptr), new BinaryNode(3, nullptr, nullptr));
    tree.postOrder(root);
    return 0;
}*/

// Level-order
/*int main (){
    BinarySearchTree tree;
    BinaryNode *root = new BinaryNode(1, new BinaryNode(2, nullptr, nullptr), new BinaryNode(3, nullptr, nullptr));
    tree.levelOrder(root);
    return 0;
}*/


// 4.31 fra bogen
// Write efficient functions that take only a pointer to the root of a binary tree, T, and compute
// a) the number of nodes in T b) the number of leaves in T c) the number of full nodes in T
// What is the running time of your functions?

/*int main(){
    BinarySearchTree tree;
    BinaryNode *root = new BinaryNode(1, new BinaryNode(2, nullptr, nullptr), new BinaryNode(3, nullptr, nullptr));
    cout << "Number of nodes: " << tree.countNodes(root) << endl;
    cout << "Number of leaves: " << tree.countLeaves(root) << endl;
    cout << "Number of full nodes: " << tree.countFullNodes(root) << endl;

    return 0;
}*/

// Skriv en metode som kan beregne internal path length af et binært træ


// SKriv en metode, som kan skabe et perfekt binært træ med højden h(>0).
