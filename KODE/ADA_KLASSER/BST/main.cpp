#include <iostream>
#include <optional>

#include "BinarySearchTree.h"

int main(int argc, char* argv[])
{
    BinarySearchTree tree;
    int values[] = {45, 15, 10, 12, 20, 79, 55, 50, 90};
    std::cout<<"inserting values: "<<std::endl;
    for (int v : values){
        std::cout<<v<<std::endl;
        tree.insert(v);

    } 
    
    tree.printTree();
      
    const BinaryNode* root = tree.getRoot();
    if (root != nullptr) {
    std::cout << "root value: " << root->element << std::endl;
    }
    
    std::vector<int> leaves = tree.getLeaves();
    for(int i = 0; i < leaves.size(); i++){
        std::cout<<"leaf: "<<leaves[i]<<std::endl;
    }
    
    
    int depth = 3;
    std::cout<<"printing nodes at depth: "<<depth<<std::endl;
    std::vector<int> nodesAtDepth = tree.getNodesAtDepth(depth);
    for(int i = 0; i < nodesAtDepth.size()-1; i++){
        std::cout<<"node: "<<nodesAtDepth[i]<<std::endl;
    }
    

    bool balanced = tree.isBalanced();
    std::cout<<"tree balanced? "<<balanced<<std::endl;
    
    std::cout<<"printing root to leaf paths"<<std::endl;
    std::vector<std::string> rootToLeafPaths = tree.getRootToLeafPaths();
    for(int i = 0; i < rootToLeafPaths.size(); i++){
        std::cout<<rootToLeafPaths[i]<<" "<<std::endl;
    }
    
    
    int nodeCount = tree.fullNodeCount2();
    std::cout<<"fullnodeCount: "<<nodeCount<<std::endl;
    
    double avgDepth = tree.averageDepth();
    std::cout<<"avgDepth: "<<avgDepth<<std::endl;
    

    int k = 3;
    std::optional<int> kthsmallest = tree.kthSmallest(k);

    if (kthsmallest.has_value()) {
        std::cout << k << "th-smallest: " << *kthsmallest << std::endl;
        // eller: kthsmallest.value()
    } else {
        std::cout << "Der findes ikke et " << k << "th-smallest element i træet" << std::endl;
    }


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


    int height = tree.getTreeHeight();
    std::cout<<"height: "<< height<<std::endl;

    int IPL = tree.getInternalDepth();
    std::cout<<"IPL: "<< IPL<<std::endl;
    
    return 0;
}