#include <iostream>
#include "bst.h"

// Create or insert
BST::Node* BST::insertNode(BST::Node* root, int data) {
    if (!root) return new Node(data); //creates root node (sort of like a constructor)
    
    //make sure data on left is smaller than data on right
    if (data < root->data) {
        root->left  = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    
    // duplicates ignored
    return root;
}



// Function to delete a node
BST::Node* BST::deleteNode(Node* root, int data)
{
    if (root == nullptr)
        return root;

    // If the data to be deleted is smaller than the root's
    // data, then it lies in the left subtree
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }

    // If the data to be deleted is greater than the root's
    // data, then it lies in the right subtree
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }

    // if data is same as root's data, then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    
    return root;
}

// Function to find the inorder successor
BST::Node* BST::minValueNode(Node* node)
{
    Node* current = node;
    // loop down to find the leftmost leaf
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Function to search a given key in a given BST
BST::Node* BST::searchNode(Node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == nullptr || root->data == key) {
        return root;
    }

    // Key is greater than root's key
    if (root->data < key) {
        return searchNode(root->right, key); //recursive calls, right node is passed as root
    }

    // Key is smaller than root's key
    return searchNode(root->left, key); //recursive calls, right node is passed as root
}

// Function to do inorder traversal of BST
void BST::inorderTraversal(Node* root)
{
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Function to do preorder traversal of BST
void BST::preorderTraversal(Node* root)
{   
    if(!root)return;
    std::cout <<root->data << " ";
    preorderTraversal(root->left);        
    preorderTraversal(root->right);
            

}

// Function to do postorder traversal of BST
void BST::postorderTraversal(Node* root)
{   
    if(!root)return;
    postorderTraversal(root->left);        
    postorderTraversal(root->right);
    std::cout <<root->data << " ";            
    
}

// Destructor helper
void BST::destroy(BST::Node* root) {
    if (!root) return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}