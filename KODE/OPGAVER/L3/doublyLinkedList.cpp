#include "doublyLinkedList.h"
#include <iostream>

DoublyLinkedList::DoublyLinkedList() : head_(nullptr), tail_(nullptr), sz_(0) {}

DoublyLinkedList::~DoublyLinkedList() { clear(); }

DoublyLinkedList::DoublyLinkedList(DoublyLinkedList&& other) noexcept : head_(nullptr), tail_(nullptr), sz_(0) {
    moveFrom(other);
}

DoublyLinkedList& DoublyLinkedList::operator=(DoublyLinkedList&& other) noexcept {
    if (this != &other) { clear(); moveFrom(other); }
    return *this;
}

bool DoublyLinkedList::empty() const { return sz_ == 0; }
std::size_t DoublyLinkedList::size() const { return sz_; }

void DoublyLinkedList::push_front(int data) {
    Node* n = new Node(data);
    n->next = head_;
    if (head_) head_->prev = n; else tail_ = n;
    head_ = n; ++sz_;
}

void DoublyLinkedList::push_back(int data) {
    Node* n = new Node(data);
    n->prev = tail_;
    if (tail_) tail_->next = n; else head_ = n;
    tail_ = n; ++sz_;
}

bool DoublyLinkedList::insert_at(std::size_t position_1based, int data) {
    if (position_1based < 1 || position_1based > sz_ + 1) return false;
    if (position_1based == 1) { push_front(data); return true; }
    if (position_1based == sz_ + 1) { push_back(data); return true; }

    Node* cur = head_;
    for (std::size_t i = 1; i < position_1based - 1; ++i) cur = cur->next;

    Node* n = new Node(data);
    n->next = cur->next;
    n->prev = cur;
    cur->next->prev = n;
    cur->next = n;
    ++sz_;
    return true;
}

bool DoublyLinkedList::pop_front() {
    if (!head_) return false;
    Node* n = head_;
    head_ = head_->next;
    if (head_) head_->prev = nullptr; else tail_ = nullptr;
    delete n; --sz_; return true;
}

bool DoublyLinkedList::pop_back() {
    if (!tail_) return false;
    Node* n = tail_;
    tail_ = tail_->prev;
    if (tail_) tail_->next = nullptr; else head_ = nullptr;
    delete n; --sz_; return true;
}

bool DoublyLinkedList::erase_at(std::size_t position_1based) {
    if (position_1based < 1 || position_1based > sz_) return false;
    if (position_1based == 1) return pop_front();
    if (position_1based == sz_) return pop_back();

    Node* cur = head_;
    for (std::size_t i = 1; i < position_1based; ++i) cur = cur->next;

    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete cur; --sz_;
    return true;
}

void DoublyLinkedList::clear() {
    Node* t = head_;
    while (t) {
        Node* nxt = t->next;
        delete t;
        t = nxt;
    }
    head_ = tail_ = nullptr; sz_ = 0;
}

// --- NEW: bucket-local index & search ---
Node* DoublyLinkedList::nth(std::size_t index) {
    if (index >= sz_) return nullptr;
    if (index <= sz_ / 2) {
        Node* cur = head_;
        for (std::size_t i = 0; i < index; ++i) cur = cur->next;
        return cur;
    } else {
        Node* cur = tail_;
        for (std::size_t i = sz_ - 1; i > index; --i) cur = cur->prev;
        return cur;
    }
}

const Node* DoublyLinkedList::nth(std::size_t index) const {
    return const_cast<DoublyLinkedList*>(this)->nth(index);
}

int* DoublyLinkedList::value_at(std::size_t index) {
    Node* n = nth(index);
    return n ? &n->data : nullptr;
}

const int* DoublyLinkedList::value_at(std::size_t index) const {
    const Node* n = nth(index);
    return n ? &const_cast<Node*>(n)->data : nullptr;
}

Node* DoublyLinkedList::find_first(int value) {
    for (Node* t = head_; t; t = t->next) if (t->data == value) return t;
    return nullptr;
}

const Node* DoublyLinkedList::find_first(int value) const {
    return const_cast<DoublyLinkedList*>(this)->find_first(value);
}

std::optional<std::size_t> DoublyLinkedList::index_of_first(int value) const {
    std::size_t i = 0;
    for (Node* t = head_; t; t = t->next, ++i) if (t->data == value) return i;
    return std::nullopt;
}

// Debug helpers
void DoublyLinkedList::print_forward() const {
    std::cout << "Forward List: ";
    for (Node* t = head_; t; t = t->next) std::cout << t->data << ' ';
    std::cout << '\n';
}

void DoublyLinkedList::print_reverse() const {
    std::cout << "Reverse List: ";
    for (Node* t = tail_; t; t = t->prev) std::cout << t->data << ' ';
    std::cout << '\n';
}

Node* DoublyLinkedList::head() const { return head_; }
Node* DoublyLinkedList::tail() const { return tail_; }

void DoublyLinkedList::moveFrom(DoublyLinkedList& other) {
    head_ = other.head_;
    tail_ = other.tail_;
    sz_   = other.sz_;
    other.head_ = other.tail_ = nullptr;
    other.sz_ = 0;
}
