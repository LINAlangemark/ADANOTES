

#include "hashMap.h"
#include <iostream>

/* ---------- Constructor ---------- */
template <typename Key, typename Value>
HashMap<Key, Value>::HashMap(
    size_t size,
    std::function<size_t(const Key&)> hf,
    ProbingMode m,
    bool enableRehash,
    double maxLF)
    : mode(m),
      hashFunc(hf),
      tableSize(size),
      rehashEnabled(enableRehash),
      maxLoadFactor(maxLF),
      numElements(0)
{
    if (mode == ProbingMode::SeparateChaining)
        buckets.resize(tableSize);
    else
        table.resize(tableSize);
}


template <typename Key, typename Value>
void HashMap<Key, Value>::insert(const Key& key, const Value& value) {
    size_t h = hashFunc(key) % tableSize;

    /* ---------- Separate chaining ---------- */
    if (mode == ProbingMode::SeparateChaining) {
        for (auto& p : buckets[h]) {
            if (p.first == key) {
                p.second += value;   // existing key
                return;
            }
        }

        // new key
        buckets[h].push_back({key, value});
        ++numElements;

        if (rehashEnabled && loadFactor() > maxLoadFactor) {
            rehash(tableSize * 2 + 1);
        }

        return;
    }

    /* ---------- Probing ---------- */
    for (size_t i = 0; i < tableSize; ++i) {
        size_t idx = probeIndex(h, i);

        if (!table[idx].occupied) {
            table[idx] = {key, value, true};
            ++numElements;
            
            if (rehashEnabled && loadFactor() > maxLoadFactor) {
                rehash(tableSize * 2 + 1);
            }
            return;
        }

        if (table[idx].occupied && table[idx].key == key) {
            table[idx].value += value;   // existing key
            return;
        }
    }

    throw std::overflow_error("Hash table full");
}

/* ---------- Probing ---------- */
template <typename Key, typename Value>
size_t HashMap<Key, Value>::probeIndex(size_t h, size_t i) const {
    if (mode == ProbingMode::LinearProbing)
        return (h + i) % tableSize;
    else  // Quadratic
        return (h + i * i) % tableSize;
}

/* ---------- Load factor ---------- */
template <typename Key, typename Value>
double HashMap<Key, Value>::loadFactor() const {
    return static_cast<double>(numElements) / tableSize;
}


/* ---------- Rehashing ---------- */
template <typename Key, typename Value>
void HashMap<Key, Value>::rehash(size_t newSize) {
    // Save old data
    auto oldBuckets = buckets;
    auto oldTable   = table;
    size_t oldSize  = tableSize;

    // Reset
    tableSize = newSize;
    numElements = 0;

    if (mode == ProbingMode::SeparateChaining) {
        buckets.clear();
        buckets.resize(tableSize);

        for (const auto& bucket : oldBuckets) {
            for (const auto& p : bucket) {
                insert(p.first, p.second);
            }
        }
    } else {
        table.clear();
        table.resize(tableSize);

        for (const auto& e : oldTable) { //probing rehashing
            if (e.occupied) {
                insert(e.key, e.value);
            }
        }
    }
}

template <typename Key, typename Value>
void HashMap<Key, Value>::setRehashing(bool enabled) {
    rehashEnabled = enabled;
}

/* ---------- Lookup ---------- */
template <typename Key, typename Value>
bool HashMap<Key, Value>::contains(const Key& key) const {
    size_t h = hashFunc(key) % tableSize;

    if (mode == ProbingMode::SeparateChaining) {
        for (const auto& p : buckets[h])
            if (p.first == key) return true;
        return false;
    }

    for (size_t i = 0; i < tableSize; ++i) {
        size_t idx = probeIndex(h, i);
        if (!table[idx].occupied) return false;
        if (table[idx].key == key) return true;
    }
    return false;
}

template <typename Key, typename Value>
Value& HashMap<Key, Value>::at(const Key& key) {
    size_t h = hashFunc(key) % tableSize;

    if (mode == ProbingMode::SeparateChaining) {
        for (auto& p : buckets[h])
            if (p.first == key) return p.second;
        throw std::out_of_range("Key not found");
    }

    for (size_t i = 0; i < tableSize; ++i) {
        size_t idx = probeIndex(h, i);
        if (!table[idx].occupied) break;
        if (table[idx].key == key) return table[idx].value;
    }
    throw std::out_of_range("Key not found");
}

/* ---------- Stats ---------- */

template <typename Key, typename Value>
size_t HashMap<Key, Value>::findLargestChain() const {
    size_t max = 0;
    for (const auto& bucket : buckets) {
        if (bucket.size() > max)
            max = bucket.size();
    }
    return max;
}


template <typename Key, typename Value>
std::pair<Key, Value> HashMap<Key, Value>::findMaxValue() const {
    Key maxKey{};
    Value maxValue{};
    bool init = false;

    if (mode == ProbingMode::SeparateChaining) {
        for (const auto& bucket : buckets)
            for (const auto& p : bucket)
                if (!init || p.second > maxValue) {
                    maxKey = p.first;
                    maxValue = p.second;
                    init = true;
                }
    } else {
        for (const auto& e : table)
            if (e.occupied && (!init || e.value > maxValue)) {
                maxKey = e.key;
                maxValue = e.value;
                init = true;
            }
    }
    return {maxKey, maxValue};
}


template <typename Key, typename Value>
size_t HashMap<Key, Value>::bucketOccupancy(size_t index) const {
    if (mode == ProbingMode::SeparateChaining)
        return buckets[index].size();

    // probing: 0 or 1
    return table[index].occupied ? 1 : 0;
}


/*---------- debugging ----------*/
template <typename Key, typename Value>
void HashMap<Key, Value>::debugPrint() const {
    if (mode == ProbingMode::SeparateChaining) {
        for (size_t i = 0; i < tableSize; ++i) {
            std::cout << i << ": ";
            for (const auto& p : buckets[i])
                std::cout << "(" << p.first << "," << p.second << ") ";
            std::cout << "\n";
        }
    } else {
        for (size_t i = 0; i < tableSize; ++i) {
            std::cout << i << ": ";
            if (table[i].occupied)
                std::cout << "(" << table[i].key << "," << table[i].value << ")";
            else
                std::cout << "[empty]";
            std::cout << "\n";
        }
    }
}
// Explicit template instantiations
template class HashMap<int, int>;
template class HashMap<std::string, int>;

