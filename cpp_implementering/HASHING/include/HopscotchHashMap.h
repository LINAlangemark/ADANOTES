#ifndef HOPSCOTCH_HASHMAP_H
#define HOPSCOTCH_HASHMAP_H

#include <vector>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <cstdint>

template <typename Key, typename Value, size_t H = 8>
class HopscotchHashMap {
private:
    struct Entry {
        Key key;
        Value value;
        bool occupied = false;
    };

    std::vector<Entry> table;
    std::vector<uint32_t> hopInfo;   // bitmap
    size_t tableSize;
    std::function<size_t(const Key&)> hashFunc;

    void rehash();

public:
    HopscotchHashMap(size_t size,
                     std::function<size_t(const Key&)> hf);

    void insert(const Key& key, const Value& value);
    bool contains(const Key& key) const;
    Value& at(const Key& key);

    void debugPrint() const;
};

#endif
