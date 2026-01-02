#include "BinarySearchTree.h"
#include "avlTree.h"
#include "prioQ.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <cmath>
 #include <queue>

int main(int argc, char** argv){

    std::cout<<"-------------------- Default Priority Queue--------------------"<<std::endl;
    std::priority_queue<int> pqd;  // MAX-heap (default)

    int H1[] = {32, 10, 8, 1, 9, 7, 6}; // level-order array representation

    std::cout << "Inserting Values:" << std::endl;
    for (int x : H1)
    {
        std::cout << x << std::endl;
        pqd.push(x); // insert
    }

    std::cout << "top (max): " << pqd.top() << std::endl; // findMax

    int a = pqd.top();  // get max
    pqd.pop();          // deleteMax

    std::cout << "popped: " << a << std::endl;

    std::cout << "new top: " << pqd.top() << std::endl;

    std::cout << "isEmpty: " << pqd.empty() << std::endl;

    std::cout<<"-------------------- Custom Priority Queue--------------------"<<std::endl;
    PrioQ pq;

    pq.push(32);
    pq.push(10);
    pq.push(8);
    pq.push(1);
    pq.push(9);
    pq.push(7);
    pq.push(6);

    std::cout << "Top: " << pq.top() << std::endl;

    pq.changePriority(9, 40);  // increase priority
    std::cout << "Top after change: " << pq.top() << std::endl;

    pq.changePriority(40, 5);  // decrease priority
    std::cout << "Top after change: " << pq.top() << std::endl;

   /*

    BinarySearchTree bst;
    
    int vals[] = {45, 15, 79, 10, 20, 55, 90, 12, 50};
        std::cout<<"inserting values: "<<std::endl;
    for (int v : vals){
        std::cout<<v<<std::endl;
        bst.insert(v);

    }
    std::cout<<"-------------------- Binary Search Tree --------------------"<<std::endl;
    bst.printTree();
 
    std::cout << "Route to 10: " << bst.findRoute(10) << std::endl;
    std::cout << "Route to 50: " << bst.findRoute(50) << std::endl;
    std::cout << "Route to 30: " << bst.findRoute(30) << std::endl; // ikke i træet
    */
    
    /*
    std::cout<<"-------------------- Binary Search Tree --------------------"<<std::endl;
    BinarySearchTree bst;
    
    int vals[] = {7, 4, 3, 2, 1, 28, 55, 51, 48, 40, 35, 60, 68, 67, 69};
        std::cout<<"inserting values: "<<std::endl;
    for (int v : vals){
        std::cout<<v<<std::endl;
        bst.insert(v);

    }
    std::cout<<"---------- Tree ----------"<<std::endl;
    bst.printTree();

    int branchCount= bst.branchCount();
    std::cout<<"branchCount: "<<branchCount<<std::endl;
   
    int height = bst.getTreeHeight();
    std::cout<<"Height: "<< height<<std::endl;

    int depth = bst.getInternalDepth();
    std::cout<<"Internal depth: "<< depth<<std::endl;
    
    std::cout<<"---------- Preorder Traversal of Tree ----------"<<std::endl;
    bst.preorderTraversal();
    std::cout<<"\n"<<std::endl;

    std::cout<<"---------- Inorder Traversal of Tree ----------"<<std::endl;
    bst.inorderTraversal();
    std::cout<<"\n"<<std::endl;

    std::cout<<"---------- Postorder Traversal of Tree ----------"<<std::endl;
    bst.postorderTraversal();
    std::cout<<"\n"<<std::endl;
    
    std::cout<<"---------- Levelorder Traversal of Tree ----------"<<std::endl;
     bst.levelOrderTraversal();
    std::cout<<"\n"<<std::endl;


    std::cout << "---------- AVL Tree Structure ----------" << std::endl;
    AVLTree avl;
    avl.setDebug(true);
    avl.buildFromBST(bst);

    std::cout << "---------- Initial (non-AVL) tree: ---------- \n";
    avl.printTree();

    std::cout << "---------- AVL Tree Structure ----------" << std::endl;
    avl.rebalance(); 
    avl.printTree();


   std::cout<<"-------------------- AVL Tree --------------------"<<std::endl;
    AVLTree avl;
    avl.setDebug(false);

    std::cout << "inserting values:" << std::endl;
    for (int v : vals)
    {
        std::cout << v << std::endl;
        avl.insert(v);
    }

    std::cout << "---------- AVL Tree Structure ----------" << std::endl;
    avl.printTree();

    std::cout << "---------- Preorder Traversal ----------" << std::endl;
    avl.preorderTraversal();
    std::cout << "\n" << std::endl;

    std::cout << "---------- Inorder Traversal ----------" << std::endl;
    avl.inorderTraversal();
    std::cout << "\n" << std::endl;

    std::cout << "---------- Postorder Traversal ----------" << std::endl;
    avl.postorderTraversal();
    std::cout << "\n" << std::endl;*/

    return 0;
};