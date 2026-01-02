import random

class CuckooHashTable:
    def __init__(self, size=11):
        self.size = size
        self.tables = [{}, {}]
        self.num_elements = 0

    def hash_function(self, key, function_number):
        if function_number == 0:
            return hash(key) % self.size
        else:
            return (hash(key) // self.size) % self.size

    def insert(self, key, value):
        if self.num_elements / self.size > 0.5:
            self.rehash()

        for _ in range(self.size):
            index1 = self.hash_function(key, 0)
            if key in self.tables[0]:
                self.tables[0][key] = value
                return
            elif len(self.tables[0]) < self.size:
                self.tables[0][key] = value
                self.num_elements += 1
                return

            key, value = self.tables[0].pop(key, (key, value))
            index2 = self.hash_function(key, 1)
            if key in self.tables[1]:
                self.tables[1][key] = value
                return
            elif len(self.tables[1]) < self.size:
                self.tables[1][key] = value
                self.num_elements += 1
                return

            key, value = self.tables[1].pop(key, (key, value))

        self.rehash()
        self.insert(key, value)

    def get(self, key):
        index1 = self.hash_function(key, 0)
        if key in self.tables[0]:
            return self.tables[0][key]
        index2 = self.hash_function(key, 1)
        if key in self.tables[1]:
            return self.tables[1][key]
        raise KeyError(f"Key {key} not found")

    def rehash(self):
        old_tables = self.tables
        self.size *= 2
        self.tables = [{}, {}]
        self.num_elements = 0

        for table in old_tables:
            for key, value in table.items():
                self.insert(key, value)

class CuckooHashError(Exception):
    pass

# Example usage
hash_table = CuckooHashTable()
hash_table.insert("key1", "value1")
hash_table.insert("key2", "value2")
print(hash_table.get("key1"))  # Output: value1
print(hash_table.get("key2"))  # Output: value2