class HashTable:
    def __init__(self, size, method="separate_chaining", hop_size=4, display_as_letters=False):
        self.size = size
        self.method = method
        self.hop_size = hop_size
        self.display_as_letters = display_as_letters
        self.table = [None] * size
        self.history = []  # log of insertions and collisions
        # Hopscotch-specific structures (initialized when hopscotch used)
        self.homes = [None] * size
        self.hops = [0] * size
        self.use_11k = False  # Auto-detect based on insert patterns
        if method == "separate_chaining":
            self.table = [[] for _ in range(size)]

    def _convert_key(self, item):
        """Convert letters to keys, or accept numeric keys directly.
        
        Returns: (key, is_numeric)
        """
        if isinstance(item, str):
            # Item is a letter
            k = ord(item.upper()) - ord('A') + 1
            return k, False
        else:
            # Item is already a key
            return item, True

    def _convert_to_display(self, key):
        """Convert key to display format (letter if 1-26, else number)."""
        if 1 <= key <= 26 and self.display_as_letters:
            return chr(ord('A') + key - 1)
        return str(key)
    def _hash(self, key):
        return key % self.size

    def insert(self, item):
        """Insert an item (number or letter) into the table according to chosen method."""
        key, _ = self._convert_key(item)
        idx = self._hash(key)
        probes = []

        if self.method == "separate_chaining":
            self.table[idx].append(key)
            self.history.append({
                "key": key,
                "hash": idx,
                "probes": [idx],
                "collision": False
            })

        elif self.method == "linear_probing":
            i = idx
            while self.table[i] is not None:
                probes.append(i)
                i = (i + 1) % self.size
            self.table[i] = key
            self.history.append({
                "key": key,
                "hash": idx,
                "probes": probes + [i],
                "collision": len(probes) > 0
            })

        elif self.method == "quadratic_probing":
            i = idx
            step = 0
            while self.table[i] is not None:
                probes.append(i)
                step += 1
                i = (idx + step ** 2) % self.size
                if step > self.size:
                    raise RuntimeError("Hash table full or cannot resolve collision")
            self.table[i] = key
            self.history.append({
                "key": key,
                "hash": idx,
                "probes": probes + [i],
                "collision": len(probes) > 0
            })

        elif self.method == "double_hashing":
            step = 1 + (key % (self.size - 1))
            i = idx
            while self.table[i] is not None:
                probes.append(i)
                i = (i + step) % self.size
            self.table[i] = key
            self.history.append({
                "key": key,
                "hash": idx,
                "probes": probes + [i],
                "collision": len(probes) > 0
            })
        elif self.method == "hopscotch":
            # Simplified hopscotch hashing implementation
            # neighborhood size (H) determines how far from home a key may reside
            H = self.hop_size
            i = idx
            probes = []

            # find first free slot by linear probing
            free = i
            while self.table[free] is not None:
                probes.append(free)
                free = (free + 1) % self.size
                if free == i:
                    raise RuntimeError("Hash table is full")

            # try to bring the free slot into the neighborhood of home
            # by moving elements closer (swap/move backwards)
            while (free - i) % self.size >= H:
                moved = False
                # search for a candidate j in [free-(H-1), free-1]
                for dist in range(H - 1, 0, -1):
                    j = (free - dist) % self.size
                    if self.table[j] is None:
                        continue
                    home_j = self._hash(self.table[j])
                    # if moving element at j to 'free' keeps it within its neighborhood
                    if (free - home_j) % self.size < H:
                        # move element from j to free, j becomes new free
                        self.table[free] = self.table[j]
                        self.table[j] = None
                        probes.append(j)
                        free = j
                        moved = True
                        break
                if not moved:
                    # cannot bring free into neighborhood; break and place outside neighborhood
                    break

            # place the new key at the free slot
            self.table[free] = key
            self.history.append({
                "key": key,
                "hash": idx,
                "probes": probes + [free],
                "collision": len(probes) > 0
            })
        else:
            raise NotImplementedError("Hashing method not implemented")
            return False, probes
    def search(self, item):
        """Search for item (number or letter) and return (found, probes)."""
        key, _ = self._convert_key(item)
        idx = self._hash(key)
        probes = []

        if self.method == "separate_chaining":
            probes.append(idx)
            return key in self.table[idx], probes

        elif self.method == "linear_probing":
            i = idx
            while self.table[i] is not None:
                probes.append(i)
                if self.table[i] == key:
                    return True, probes
                i = (i + 1) % self.size
            return False, probes

        elif self.method == "quadratic_probing":
            i = idx
            step = 0
            while self.table[i] is not None and step <= self.size:
                probes.append(i)
                if self.table[i] == key:
                    return True, probes
                step += 1
                i = (idx + step ** 2) % self.size
            return False, probes

        elif self.method == "double_hashing":
            step = 1 + (key % (self.size - 1))
            i = idx
            while self.table[i] is not None:
                probes.append(i)
                if self.table[i] == key:
                    return True, probes
                i = (i + step) % self.size
            return False, probes

        elif self.method == "hopscotch":
            H = self.hop_size
            for offset in range(H):
                i = (idx + offset) % self.size
                probes.append(i)
                if self.table[i] is None:
                    return False, probes
                if self.table[i] == key:
                    return True, probes
            return False, probes

    # --- Hopscotch helper methods attached to the class ---
    def _hop_set(self, home, pos):
        off = (pos - home) % self.size
        if off < self.hop_size:
            self.hops[home] |= (1 << off)

    def _hop_clear(self, home, pos):
        off = (pos - home) % self.size
        if off < self.hop_size:
            self.hops[home] &= ~(1 << off)

    def hop_find_free(self, start):
        i = start
        for _ in range(self.size):
            if self.table[i] is None:
                return i
            i = (i + 1) % self.size
        return None

    def hop_insert_home_index(self, name, home_index):
        """Insert an item with a given home index (0-based) using hopscotch logic.
        """
        home = home_index
        free = self.hop_find_free(home)
        if free is None:
            raise RuntimeError("Table full")

        # try to bring free into neighborhood
        while (free - home) % self.size >= self.hop_size:
            moved = False
            for dist in range(self.hop_size - 1, 0, -1):
                j = (free - dist) % self.size
                if self.table[j] is None:
                    continue
                home_j = self.homes[j]
                if home_j is None:
                    continue
                # can we move element at j to free so it stays within its home neighborhood?
                if (free - home_j) % self.size < self.hop_size:
                    # move
                    self.table[free] = self.table[j]
                    self.homes[free] = home_j
                    # update hop bits for moved element's home
                    self._hop_clear(home_j, j)
                    self._hop_set(home_j, free)
                    self.table[j] = None
                    self.homes[j] = None
                    free = j
                    moved = True
                    break
            if not moved:
                # cannot bring free into neighborhood
                break

        # place new element at free
        self.table[free] = name
        self.homes[free] = home
        self._hop_set(home, free)

    def hop_insert_sequence(self, sequence, base_index=0):
        """Insert a sequence of items using hopscotch with given home indices.
        
        Args:
            sequence: list of tuples [(item, home_index), ...]
            base_index: subtract from home_index to get table position
                       (use base_index=44 for indices 44-57 to map to 0-13)
            
            Example: [('A', 47), ('B', 51)] with base_index=44
        """
        for item, home_abs in sequence:
            home_index = home_abs - base_index
            self.hop_insert_home_index(item, home_index)

    def print_hop_table(self, base=0):
        """Print table with hop bitmasks. `base` used to display absolute indices."""
        H = self.hop_size
        print("Index | Value | Hop (H={})".format(H))
        print("---------------------------")
        for i in range(self.size):
            idx_abs = base + i
            val = self.table[i] if self.table[i] is not None else "-"
            hop_str = format(self.hops[i], f'0{H}b')
            print(f"{idx_abs:5} | {val:5} | {hop_str}")

    def insert_items(self, items):
        """Insert items (letters or keys).
        
        Args:
            items: list of letters (A-Z) or numeric keys
        """
        for item in items:
            key, _ = self._convert_key(item)
            self.insert(key)

    def populate_initial(self, item_positions):
        """Populate table directly with items at specific positions.
        
        Args:
            item_positions: dict with format {index: item, ...}
            item can be a letter or numeric key
            Example: {0: 'D', 1: 'H', 2: 'V', 5: 'P', 7: 'X', 8: 'E'}
        """
        for index, item in item_positions.items():
            key, _ = self._convert_key(item)
            self.table[index] = key

    def get_load_factor(self):
        """Calculate load factor = (number of elements) / table size"""
        count = sum(1 for slot in self.table if slot is not None)
        return count / self.size

    def rehash(self, new_size=None):
        """Rehash the table to a new size (default: double the current size).
        
        Args:
            new_size: new table size. If None, uses 2 * current size.
        """
        if new_size is None:
            new_size = self.size * 2
        
        # Save old table and elements
        old_table = self.table
        old_size = self.size
        
        # Create new empty table
        self.size = new_size
        self.table = [None] * new_size
        self.history = []  # Reset history for fresh start
        
        # Reinsert all old elements using the insert method (which uses new hash function)
        for element in old_table:
            if element is not None:
                self.insert(element)

        print(f"\nTabel efter rehashing (størrelse={int(new_size)}):")
        self.print_table()
        
        new_load_factor = self.get_load_factor()
        print(f"Ny load factor: {new_load_factor:.2f} ({int(new_load_factor*100)}%)")

    def print_table(self):
        """Print the table. Displays letters if keys are 1-26, otherwise shows numbers."""
        print("Index | Value")
        print("--------------")
        for i, slot in enumerate(self.table):
            if slot is None:
                val = "-"
            else:
                val = self._convert_to_display(slot)
            print(f"{i:5} | {val}")

    def print_history(self):
        """Print insertion history. Displays letters if keys are 1-26, otherwise shows numbers."""
        print("\nInsertion history")
        print("Step | Key | Hash | Probes (path) | Collision")
        total_probes = 0
        total_collisions = 0
        for step, h in enumerate(self.history, start=1):
            key_display = self._convert_to_display(h['key'])
            probes_str = " -> ".join(str(p) for p in h['probes'])
            collision = "Yes" if h.get('collision') else "No"
            print(f"{step:4} | {key_display:3} | {h['hash']:4} | {probes_str:14} | {collision}")
            total_probes += len(h['probes'])
            if h.get('collision'):
                total_collisions += 1
        
        print("--------------------------------------------------------------")
        print(f"Total insertions : {len(self.history)}")
        print(f"Total probes : {total_probes}")
        print(f"Average probes : {total_probes / len(self.history):.2f}")
        print(f"Collisions : {total_collisions}")
        load_factor = len(self.history) / self.size
        print(f"Load factor : {load_factor:.2f} ({load_factor*100:.2f}%)")

        if load_factor > 0.5:
            print("⚠️  Load factor is above 50%! Consider rehashing.")


if __name__ == "__main__":
    ht = HashTable(size=11, method="quadratic_probing", display_as_letters=True)

    # Define your inputs here (numbers or letters, upper/lowercase)
    inputs = ['A','W','C','O','E','S']

    # Insert all items in a loop
    for item in inputs:
        ht.insert(item)

    print("\nHash table efter indsættelse af bogstaver:")
    ht.print_table()
    ht.print_history()

    ht.rehash(new_size=16)
    


"""
   # ╔════════════════════════════════════════════════════════════════════════════╗
    # ║  OPGAVE 1: Quadratic Probing med Numeriske Nøgler                          ║
    # ╚════════════════════════════════════════════════════════════════════════════╝

    print("=" * 80)
    print("OPGAVE 1: Quadratic Probing med Numeriske Nøgler")
    print("=" * 80)
    
    ht = HashTable(size=11, method="quadratic_probing", display_as_letters=False)

    initial = [22, 5, 16, 27]
    for key in initial:
        ht.insert(key)

    print("\nTabel efter indsættelse af [22, 5, 16, 27]:")
    ht.print_table()
    ht.print_history()

    additions = [1, 12, 23, 30, 123]
    for key in additions:
        ht.insert(key)

    print("\nTabel efter indsættelse af [1, 12, 23, 30, 123]:")
    ht.print_table()
    ht.print_history()

    # ╔════════════════════════════════════════════════════════════════════════════╗
    # ║  OPGAVE 2: Hopscotch Hashing                                              ║
    # ╚════════════════════════════════════════════════════════════════════════════╝

    print("\n\n" + "=" * 80)
    print("OPGAVE 2: Hopscotch Hashing")
    print("=" * 80)
    
    n = 14
    H = 4

    ht_hop = HashTable(size=n, method="hopscotch", hop_size=H, display_as_letters=True)

    sequence = [
        ('A', 47), ('B', 51), ('C', 55), ('D', 51),
        ('E', 46), ('F', 51), ('G', 49), ('H', 53),
        ('I', 50), ('J', 51),
    ]
    
    ht_hop.hop_insert_sequence(sequence, base_index=44)
    
    print("\nHopscotch tabel (størrelse=14, hop_size=4):")
    ht_hop.print_hop_table(base=44)


    # ╔════════════════════════════════════════════════════════════════════════════╗
    # ║  OPGAVE 3: Rehashing                                                       ║
    # ╚════════════════════════════════════════════════════════════════════════════╝

    print("\n\n" + "=" * 80)
    print("OPGAVE 3: Rehashing")
    print("=" * 80)
    
    ht_rehash = HashTable(size=11, method="quadratic_probing", display_as_letters=True)
    
    ht_rehash.populate_initial({1: 'A', 2: 'W', 3: 'C', 4: 'O', 5: 'E', 8: 'S'})
    
    print("\nOriginaltabel (størrelse=11):")
    ht_rehash.print_table()
    
    load_factor = ht_rehash.get_load_factor()
    print(f"Load factor: {load_factor:.2f} ({int(load_factor*100)}%)")
    print(f"Elementer: {sum(1 for slot in ht_rehash.table if slot is not None)}")
    
    print("\n" + "-" * 80)
    print("Udfører rehashing (størrelse 11 → 22)...")
    print("-" * 80)
    
    ht_rehash.rehash(new_size=22)
    
    print("\nTabel efter rehashing (størrelse=22):")
    ht_rehash.print_table()
    
    new_load_factor = ht_rehash.get_load_factor()
    print(f"Ny load factor: {new_load_factor:.2f} ({int(new_load_factor*100)}%)")


    ht_rehash.print_table()
    ht_rehash.print_history()
    # ╔════════════════════════════════════════════════════════════════════════════╗
    # ║  OPGAVE 4: Quadratic Probing med Bogstavnøgler (Kollision)                 ║
    # ╚════════════════════════════════════════════════════════════════════════════╝

    print("\n\n" + "=" * 80)
    print("OPGAVE 4: Quadratic Probing med Bogstavnøgler (Kollision)")
    print("=" * 80)
    
    ht_letters = HashTable(size=11, method="quadratic_probing", display_as_letters=True)

    ht_letters.populate_initial({0: 'D', 1: 'H', 2: 'V', 5: 'P', 7: 'X', 8: 'E'})

    print("\nInitialtabel:")
    ht_letters.print_table()
    
    print("\nIndsætter bogstav A (nøgle=1) - vil kollidere med H ved index 1:")
    ht_letters.insert(1)
    
    print("\nTabel efter indsættelse af A:")
    ht_letters.print_table()
    ht_letters.print_history()
"""
