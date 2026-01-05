#include <iostream>
#include "bst.h"

int main(int argc, char* argv[])
{
    BST tree;
 
    // Build sample BST
    int values[] = {4, 2, 5, 1, 6, 3, 7};
    std::cout<<"inserting valyues: "<<std::endl;
    for (int v : values){
        std::cout<<v<<std::endl;
        tree.insert(v);

    } 
    
    tree.printTree();

    std::cout << "Inorder traversal: ";
    tree.inorder();
    std::cout << "\n";

    std::cout << "Preorder traversal: ";
    tree.preorder();
    std::cout << "\n";

    std::cout << "Postorder traversal: ";
    tree.postorder();
    std::cout << "\n";


    // Search
    /*int key = 40;
    std::cout << "Contains " << key << "? "
              << (tree.contains(key) ? "yes" : "no") << "\n";

    // Delete a few nodes
    tree.erase(20);  // leaf
    tree.erase(30);  // one child
    tree.erase(50);  // two children (root)

    std::cout << "Inorder after deletions: ";
    tree.inorder();
    std::cout << "\n";
        */
    return 0;
}