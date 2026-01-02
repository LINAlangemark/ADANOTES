// Lec 2 Queues
// Write a class which implements a circular queue and test it.
// A circular queue can be implemented as an array.
// When you reach the last element, you move on to the next element, if there is room.
// The queue can then run while it's full.
// An extended version can expand the array when it runs full.

#include <iostream>
#include <climits>
using namespace std;

class CircularQueue {
private:
    int *queue;                         // Array to store the queue
    int front, rear, size, capacity;    // Front and rear pointers, size of the queue, and capacity of the queue

public:
    CircularQueue(int capacity) {       // Constructor
        this->capacity = capacity;      // Set the capacity of the queue
        queue = new int[capacity];      // Create an array of integers with the capacity
        front = size = 0;               // Initialize the front and size to 0
        rear = capacity - 1;            // Initialize the rear to the last index
    }

    ~CircularQueue() {                  // Destructor
        delete[] queue;                 // Delete the array
    }

    bool isFull() {                     // Check if the queue is full
        return (size == capacity);      // Return true if the size is equal to the capacity
    }

    bool isEmpty() {                    // Check if the queue is empty
        return (size == 0);             // Return true if the size is 0
    }

    void enqueue(int item) {            // Add an element to the queue
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << item << endl;       // If the queue is full, print a message and return
            return;                                                         
        }
        rear = (rear + 1) % capacity;                                       // Increment the rear pointer
        queue[rear] = item;                                                 // Add the item to the queue
        size++;                                                             // Increment the size
        cout << item << " enqueued to queue" << endl;                       // Print a message
    }

    int dequeue() {
        if (isEmpty()) {                                                    // Check if the queue is empty
            cout << "Queue is empty. Cannot dequeue" << endl;               // If the queue is empty, print a message and return
            return INT_MIN;                                                 // Return the minimum integer value
        }
        int item = queue[front];                                            // Get the item at the front of the queue
        front = (front + 1) % capacity;                                     // Increment the front pointer
        size--;                                                             // Decrement the size
        return item;                                                       
    }

    void display() {                            // Display the elements of the queue
        if (isEmpty()) {                        // Check if the queue is empty
            cout << "Queue is empty" << endl;   // If the queue is empty, print a message and
            return;                             
        }
        cout << "Queue elements: ";                          // Print the elements of the queue
        for (int i = 0; i < size; i++) {                     // Loop through the queue
            cout << queue[(front + i) % capacity] << " ";    // Print the element at the current index
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);                                               // Enqueue elements to the queue        

    q.display();                                                 // Display the elements of the queue

    cout << q.dequeue() << " dequeued from queue" << endl;       // Dequeue an element

    q.display();                                                // Display the elements of the queue

    q.enqueue(60);
    q.display();

    return 0;
}