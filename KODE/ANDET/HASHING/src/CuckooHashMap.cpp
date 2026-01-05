

#include "CuckooHashMap.h"

template <typename Key, typename Value>
CuckooHashMap<Key, Value>::CuckooHashMap(
    size_t size,
    std::function<size_t(const Key&)> h1,
    std::function<size_t(const Key&)> h2)
    : tableSize(size),
      hash1(h1),
      hash2(h2),
      maxDisplacements(2 * size)
{
    table1.resize(tableSize);
    table2.resize(tableSize);
}

template <typename Key, typename Value>
void CuckooHashMap<Key, Value>::insert(const Key& key, const Value& value) {
    Key curKey = key;
    Value curVal = value;
    bool inTable1 = true;

    for (size_t i = 0; i < maxDisplacements; ++i) {
        if (inTable1) {
            size_t idx = hash1(curKey) % tableSize;
            if (!table1[idx].occupied) {
                table1[idx] = {curKey, curVal, true};
                return;
            }
            std::swap(curKey, table1[idx].key);
            std::swap(curVal, table1[idx].value);
            inTable1 = false;
        } else {
            size_t idx = hash2(curKey) % tableSize;
            if (!table2[idx].occupied) {
                table2[idx] = {curKey, curVal, true};
                return;
            }
            std::swap(curKey, table2[idx].key);
            std::swap(curVal, table2[idx].value);
            inTable1 = true;
        }
    }

    ++numElements;
    if (double(numElements) / (2.0 * tableSize) > 0.5){ //Cuckoo hashing har 2 tabeller, så kapaciteten er 2 * tableSize.
        std::cout<<"loadfactor overskredet"<<std::endl;
        rehash();
    }
        

    insert(curKey, curVal);
}

template <typename Key, typename Value>
bool CuckooHashMap<Key, Value>::contains(const Key& key) const {
    size_t i1 = hash1(key) % tableSize;
    size_t i2 = hash2(key) % tableSize;

    return (table1[i1].occupied && table1[i1].key == key) ||
           (table2[i2].occupied && table2[i2].key == key);
}

template <typename Key, typename Value>
Value& CuckooHashMap<Key, Value>::at(const Key& key) {
    size_t i1 = hash1(key) % tableSize;
    if (table1[i1].occupied && table1[i1].key == key)
        return table1[i1].value;

    size_t i2 = hash2(key) % tableSize;
    if (table2[i2].occupied && table2[i2].key == key)
        return table2[i2].value;

    throw std::out_of_range("Key not found");
}

template <typename Key, typename Value>
void CuckooHashMap<Key, Value>::rehash() {
    auto old1 = table1;
    auto old2 = table2;

    tableSize = tableSize * 2 + 1;
    table1.assign(tableSize, {});
    table2.assign(tableSize, {});
    maxDisplacements = 2 * tableSize;

    for (const auto& e : old1)
        if (e.occupied)
            insert(e.key, e.value);

    for (const auto& e : old2)
        if (e.occupied)
            insert(e.key, e.value);
}

template <typename Key, typename Value>
void CuckooHashMap<Key, Value>::debugPrint() const {
    std::cout << "Table 1:\n";
    for (size_t i = 0; i < tableSize; ++i) {
        if (table1[i].occupied)
            std::cout << i << ": (" << table1[i].key << "," << table1[i].value << ")\n";
        else
            std::cout << i << ": [empty]\n";
    }

    std::cout << "Table 2:\n";
    for (size_t i = 0; i < tableSize; ++i) {
        if (table2[i].occupied)
            std::cout << i << ": (" << table2[i].key << "," << table2[i].value << ")\n";
        else
            std::cout << i << ": [empty]\n";
    }
}

template class CuckooHashMap<int, int>;

