#ifndef CUCKOO_HASHMAP_H
#define CUCKOO_HASHMAP_H

#include <vector>
#include <functional>
#include <utility>
#include <stdexcept>
#include <iostream>

template <typename Key, typename Value>
class CuckooHashMap {
private:
    struct Entry {
        Key key;
        Value value;
        bool occupied = false;
    };

    std::vector<Entry> table1;
    std::vector<Entry> table2;

    size_t tableSize;
    std::function<size_t(const Key&)> hash1;
    std::function<size_t(const Key&)> hash2;

    size_t maxDisplacements;

    void rehash();

public:
    CuckooHashMap(size_t size,
                  std::function<size_t(const Key&)> h1,
                  std::function<size_t(const Key&)> h2);

    void insert(const Key& key, const Value& value);
    bool contains(const Key& key) const;
    Value& at(const Key& key);
    size_t numElements = 0;

    void debugPrint() const;
};

#endif
