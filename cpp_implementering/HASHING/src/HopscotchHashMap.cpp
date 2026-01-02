

#include "HopscotchHashMap.h"

template <typename Key, typename Value, size_t H>
HopscotchHashMap<Key, Value, H>::HopscotchHashMap(
    size_t size,
    std::function<size_t(const Key&)> hf)
    : tableSize(size), hashFunc(hf)
{
    table.resize(tableSize);
    hopInfo.resize(tableSize, 0);
}

template <typename Key, typename Value, size_t H>
void HopscotchHashMap<Key, Value, H>::insert(const Key& key, const Value& value) {
    size_t h = hashFunc(key) % tableSize;

    // Find free bucket
    size_t freeIdx = h;
    while (freeIdx < tableSize && table[freeIdx].occupied)
        ++freeIdx;

    if (freeIdx >= tableSize) {
        rehash();
        insert(key, value);
        return;
    }

    // Bring free slot into neighborhood
    while (freeIdx - h >= H) {
        bool moved = false;

        for (size_t i = H - 1; i > 0; --i) {
            size_t candidate = freeIdx - i;
            uint32_t mask = hopInfo[candidate];

            for (size_t j = 0; j < i; ++j) {
                if (mask & (1u << j)) {
                    size_t swapIdx = candidate + j;
                    table[freeIdx] = table[swapIdx];
                    table[swapIdx].occupied = false;

                    hopInfo[candidate] &= ~(1u << j);
                    hopInfo[candidate] |= (1u << i);

                    freeIdx = swapIdx;
                    moved = true;
                    break;
                }
            }
            if (moved) break;
        }

        if (!moved) {
            rehash();
            insert(key, value);
            return;
        }
    }

    table[freeIdx] = {key, value, true};
    hopInfo[h] |= (1u << (freeIdx - h));
}

template <typename Key, typename Value, size_t H>
bool HopscotchHashMap<Key, Value, H>::contains(const Key& key) const {
    size_t h = hashFunc(key) % tableSize;
    uint32_t mask = hopInfo[h];

    for (size_t i = 0; i < H; ++i) {
        if (mask & (1u << i)) {
            size_t idx = h + i;
            if (table[idx].occupied && table[idx].key == key)
                return true;
        }
    }
    return false;
}

template <typename Key, typename Value, size_t H>
Value& HopscotchHashMap<Key, Value, H>::at(const Key& key) {
    size_t h = hashFunc(key) % tableSize;
    uint32_t mask = hopInfo[h];

    for (size_t i = 0; i < H; ++i) {
        if (mask & (1u << i)) {
            size_t idx = h + i;
            if (table[idx].occupied && table[idx].key == key)
                return table[idx].value;
        }
    }
    throw std::out_of_range("Key not found");
}

template <typename Key, typename Value, size_t H>
void HopscotchHashMap<Key, Value, H>::rehash() {
    auto oldTable = table;
    tableSize = tableSize * 2 + 1;

    table.assign(tableSize, {});
    hopInfo.assign(tableSize, 0);

    for (const auto& e : oldTable) {
        if (e.occupied)
            insert(e.key, e.value);
    }
}

template <typename Key, typename Value, size_t H>
void HopscotchHashMap<Key, Value, H>::debugPrint() const {
    for (size_t i = 0; i < tableSize; ++i) {
        std::cout << i << ": ";
        if (table[i].occupied)
            std::cout << "(" << table[i].key << "," << table[i].value << ")";
        else
            std::cout << "[empty]";
        std::cout << " hop=" << hopInfo[i] << "\n";
    }
}

template class HopscotchHashMap<int, int, 8>;

