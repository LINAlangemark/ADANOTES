#include <iostream>
#include "BinarySearchTree.h"

int main(int argc, char* argv[])
{
    BinarySearchTree tree;
    int values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27};
    std::cout<<"inserting values: "<<std::endl;
    for (int v : values){
        std::cout<<v<<std::endl;
        tree.insert(v);

    } 
    
    //tree.printTree();
    int h = tree.height();
    int minh = tree.minimalHeight();
    std::cout<<"height= "<< h << ", minimal height = "<<minh<<std::endl;
 /*
    // Build sample BST
    //int values[] = {4, 2, 5, 1, 6, 3, 7};
    int values[] = {45, 15, 10, 12, 20, 79, 55, 50, 90};
    std::cout<<"inserting values: "<<std::endl;
    for (int v : values){
        std::cout<<v<<std::endl;
        tree.insert(v);

    } 
    
    tree.printTree();
   
    std::cout << "Inorder traversal: ";
    tree.inorderTraversal();
    std::cout << "\n";

    std::cout << "Preorder traversal: ";
    tree.preorderTraversal();
    std::cout << "\n";

    std::cout << "Postorder traversal: ";
    tree.postorderTraversal();
    std::cout << "\n";

    std::string s = tree.findRoute(50);
    std::cout << "find 50: "<< s<<std::endl; 
    s = tree.findRoute(10);
    std::cout << "find 10: "<< s<<std::endl; 


    BinarySearchTree bst;
 
    // Build sample BST
    //int values[] = {4, 2, 5, 1, 6, 3, 7};
    int vals[] = {100, 90, 110, 120, 105, 103, 108, 111, 130, 95, 80, 70, 95, 92, 97, 85};
    std::cout<<"inserting values: "<<std::endl;
    for (int v : vals){
        std::cout<<v<<std::endl;
        bst.insert(v);

    } 
    std::cout<<"initial tree: "<<std::endl;
    bst.printTree();

    bst.remove(105);
    bst.insert(83);
    bst.remove(130);
    bst.insert(60);
    bst.remove(95);

    std::cout<<"tree after operations: "<<std::endl;
    
    bst.printTree();

    int height = bst.getTreeHeight();
    std::cout<<"height: "<< height<<std::endl;

    int depth = bst.getInternalDepth();
    std::cout<<"depth: "<< depth<<std::endl;
    */
    return 0;
}