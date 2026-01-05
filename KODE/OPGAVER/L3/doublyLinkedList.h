#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <cstddef>
#include <optional>
#include "node.h"

class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    // non-copyable (add deep copy if needed)
    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

    // movable
    DoublyLinkedList(DoublyLinkedList&& other) noexcept;
    DoublyLinkedList& operator=(DoublyLinkedList&& other) noexcept;

    bool empty() const;
    std::size_t size() const;

    void push_front(int data);
    void push_back(int data);
    bool insert_at(std::size_t position_1based, int data); // 1..sz+1

    bool pop_front();
    bool pop_back();
    bool erase_at(std::size_t position_1based);             // 1..sz

    void clear();

    // --- NEW: bucket-local index & search ---
    // 0-based index into this list; returns nullptr if out of range.
    Node* nth(std::size_t index);
    const Node* nth(std::size_t index) const;

    // Returns a pointer to the stored value (or nullptr if OOB).
    int* value_at(std::size_t index);
    const int* value_at(std::size_t index) const;

    // Linear search for the first node with given value.
    // Returns Node* (nullptr if not found).
    Node* find_first(int value);
    const Node* find_first(int value) const;

    // Optional: 0-based index of first value; std::nullopt if not found.
    std::optional<std::size_t> index_of_first(int value) const;

    // Debug helpers
    void print_forward() const;
    void print_reverse() const;

    // Accessors (use with care)
    Node* head() const;
    Node* tail() const;

private:
    Node* head_;
    Node* tail_;
    std::size_t sz_;

    void moveFrom(DoublyLinkedList& other);
};
#endif // DOUBLYLINKEDLIST_H