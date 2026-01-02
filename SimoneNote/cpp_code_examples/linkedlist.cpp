//Lecture 2
// Create a linked list from scratch


#include <bits/stdc++.h>
using namespace std;


struct Node {   // Define a structure for a node
    int data;   // The data stored in the node
    Node* next; // Pointer to the next node
};

int main()
{

    // Initialize the head of the list, it's the first node in the list. 
    // Initially, the list is empty, so the head is a null pointer.
    Node* head = nullptr;

    // Create new nodes and add them to the list
    // Each new node should be dynamically allocated using the new keyword
    for (int i = 1; i <= 5; i++) {
        Node* newNode = new Node();
        newNode->data = i; // After creating a new node, we set the data field and initialize the nect pointer to null (Replace i with the actual data)
        newNode->next = nullptr;

        // Link the nodes
        // If the list is not empty, we traverse the list to find the last node and link the new node to it
        if (head == nullptr) {

            // The list is empty, so the new node is the
            // head of the list
            head = newNode;
        }
        else {

            // The list is not empty, traverse the list to
            // find the last node
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }

            // Now temp points to the last node, link the
            // new node
            temp->next = newNode;
        }
    }

    // Print the list
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Free up the memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
