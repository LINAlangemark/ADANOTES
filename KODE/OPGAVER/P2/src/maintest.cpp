#include "P2E.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <string>
#include "hashMap.h"
#include <stdio.h>
#include <string.h>
#include <vector>
#include <cmath>


int main(int argc, char** argv){
    P2E P2;
    BinarySearchTree bst;
    std::cout<<"----------------------------- Exercise 1 ----------------------------- "<<std::endl;
    std::string text = "The cattle were running back and forth, but there was no wolf to be seen, heard, or smelled, so the shepherd decided to take a little nap in a bed of grass and early summer flowers. Soon he was awakened by a sound he had never heard before.";
    std::cout<<"sentence: "<< text<<std::endl;
    std::cout<<"\n";
    std::string word = P2.findMostFrequentWord(text);

    std::cout<<"----------------------------- Exercise 2 ----------------------------- "<<std::endl;
    int vals[] = {7, 4, 3, 2, 1, 28, 55, 51, 48, 40, 35, 60, 68, 67, 69};
        std::cout<<"inserting values: "<<std::endl;
    for (int v : vals){
        std::cout<<v<<std::endl;
        bst.insert(v);

    } 

    std::cout<<"initial tree: "<<std::endl;
    bst.printTree();
    //BinaryNode* root = bst.getRoot();
    //std::cout<<"root: "<<root->element<<std::endl;
    int branchCount= bst.branchCount();
    std::cout<<"branchCount"<<branchCount<<std::endl;
    int height = bst.getTreeHeight();
    std::cout<<"height: "<< height<<std::endl;

    int depth = bst.getInternalDepth();
    std::cout<<"depth: "<< depth<<std::endl;
    //BinaryNode* onlychild = bst.getOnlyChild(root);
    //std::cout<<"onlychild: "<<onlychild->element<<std::endl;

    
    std::cout<<"----------------------------------- Exercise 3 ----------------------------- "<<std::endl;
    BinarySearchTree bst2;
    int tree[] = {11, 2, 1, 9, 3, 13, 57, 25, 17, 90};
    std::cout<<"inserting values: "<<std::endl;
    for (int v : tree){
        std::cout<<v<<std::endl;
        bst2.insert(v);

    } 
    std::cout<<"---------- initial tree ---------- "<<std::endl;
    bst2.printTree();
    
    /*BinarySearchTree avl;
    int treeavl[] = {11, 2, 1, 9, 3, 13, 57, 25, 17, 90};
    
    for (int v : treeavl){
        //std::cout<<v<<std::endl;
        avl.insertAVL(v);
        std::cout<<"------ Current Tree -----"<<std::endl;
		avl.printTree();
       

    }*/
    std::cout<<"---------- AVL tree ---------- "<<std::endl;
    bst2.rebalance();
    std::cout << "Balanced AVL tree:\n";
    bst2.printTree();

    //bst2.inorderTraversal();
    
    
    std::cout<<"----------------------------------- Exercise 4 ----------------------------- "<<std::endl;
    BinarySearchTree bst3;
    int tree2[] = {25, 20, 36, 10, 22, 30, 40, 5, 12, 28, 38, 48, 1, 8, 15, 45, 50};
    std::cout<<"inserting values: "<<std::endl;
    for (int v : tree2){
        std::cout<<v<<std::endl;
        bst3.insert(v);

    } 
    std::cout<<"initial tree: "<<std::endl;
    bst3.printTree();
    //bst2.inorderTraversal();
    std::cout<<"postorder traversal: \n";
    bst3.postorderTraversal();
    std::cout<<"preorder traversal: \n";
    bst3.preorderTraversal();

    depth = bst3.getInternalDepth();
    std::cout<<"depth: "<< depth<<std::endl;
    std::cout<<"----------------------------------- Exercise 5 ----------------------------- "<<std::endl;
  
    // Define the adjacency matrix
    std::vector<std::vector<int>> graph = {
             /*0  1  2  3  4  5  6  7  8  9 10 11*/
        /*0*/ {0, 1, 6, 0, 1, 2, 0, 0, 0, 0, 0, 0},
        /*1*/ {1, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        /*2*/ {0, 8, 0,14, 0, 3, 0, 0, 0, 0, 0, 0},
        /*3*/ {0, 0,14, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        /*4*/ {1, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0},
        /*5*/ {2, 0, 3, 0, 0, 0,20, 0, 3, 5, 0, 0},
        /*6*/ {0, 0, 1, 0, 0,20, 0, 4, 0, 0, 8, 0},
        /*7*/ {0, 0, 0, 1, 0, 0, 4, 0, 0, 0, 0, 3},
        /*8*/ {0, 0, 0, 0, 7, 3, 0, 0, 0, 4, 0, 0},
        /*9*/ {0, 0, 0, 0, 0, 5, 0, 0, 4, 0, 2, 0},
        /*10*/{0, 0, 0, 0, 0, 0, 8, 0, 0, 2, 0, 5},
        /*11*/{0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 5, 0}
        };

    // Find and print the Minimum Spanning
    // Tree using Prim's algorithm
    P2.primMST(graph);


    std::cout<<"----------------------------------- Exercise 6 ----------------------------- "<<std::endl;

    // Node rækkefølge: A=0, B=1, C=2, D=3, E=4, F=5, G=6
    vector<vector<int>> adj = {
        //A  B  C  D  E  F  G
        { 0, 5, 3, 0, 0, 0, 0 }, // A
        { 0, 0, 2, 0, 3, 0, 1 }, // B
        { 0, 0, 0, 7, 7, 0, 0 }, // C
        { 2, 0, 0, 0, 0, 6, 0 }, // D
        { 0, 0, 0, 2, 0, 1, 0 }, // E
        { 0, 0, 0, 0, 0, 0, 0 }, // F
        { 0, 0, 0, 0, 1, 0, 0 }  // G
    };
    
    P2.djikstra(adj);
    std::cout<<"---------------------------------------------------------------------------- "<<std::endl;
  
    return 0; 
};