#ifndef HASHMAP_H
#define HASHMAP_H

#include <vector>
#include <list>
#include <functional>
#include <utility>
#include <stdexcept>

enum class ProbingMode {
    SeparateChaining,
    LinearProbing,
    QuadraticProbing
};

template <typename Key, typename Value>

class HashMap {
private:
    /* configuration */
    ProbingMode mode;
    std::function<size_t(const Key&)> hashFunc;
    size_t tableSize;

    /* separate chaining storage */
    std::vector<std::list<std::pair<Key, Value>>> buckets;

    /* probing storage */
    struct Entry {
        Key key;
        Value value;
        bool occupied = false;
    };
    std::vector<Entry> table;

    /* helpers */
    size_t probeIndex(size_t h, size_t i) const;
    
    /* rehashing support */
    size_t numElements;
    double maxLoadFactor;
    bool rehashEnabled;

    


public:
    HashMap(size_t size,
            std::function<size_t(const Key&)> hf,
            ProbingMode m = ProbingMode::SeparateChaining,
            bool enableRehash = true,
            double maxLF = 0.75);
  
    void insert(const Key& key, const Value& value);
    bool contains(const Key& key) const;
    Value& at(const Key& key);
    
    double loadFactor() const;
    void rehash(size_t newSize);
    void setRehashing(bool enabled);
    
    size_t findLargestChain() const;   // chaining only
    std::pair<Key, Value> findMaxValue() const;
    size_t bucketOccupancy(size_t index) const;
    
    void debugPrint() const;

};



#endif
