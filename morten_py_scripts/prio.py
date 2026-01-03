from collections import deque
import matplotlib.pyplot as plt
import networkx as nx

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
# ---------------------------------------------------
class PriorityQueue:
    def __init__(self, heap_type="max"):
        """
        heap_type: "max" for max-heap, "min" for min-heap
        """
        self.heap = [None]  # index 0 unused
        if heap_type not in ("max", "min"):
            raise ValueError("heap_type skal være 'max' eller 'min'")
        self.heap_type = heap_type

    # -------------------- Hjælpefunktioner --------------------
    def _compare(self, child, parent):
        """Returner True hvis child skal "bobles op" i heap_type"""
        if self.heap_type == "max":
            return child > parent
        else:  # min-heap
            return child < parent

    def _bubble_up(self, idx):
        while idx > 1:
            parent = idx // 2
            if self._compare(self.heap[idx], self.heap[parent]):
                self.heap[idx], self.heap[parent] = self.heap[parent], self.heap[idx]
                idx = parent
            else:
                break

    def _bubble_down(self, idx):
        n = len(self.heap)
        while 2*idx < n:
            left = 2*idx
            right = 2*idx + 1
            swap_idx = idx

            if left < n and self._compare(self.heap[left], self.heap[swap_idx]):
                swap_idx = left
            if right < n and self._compare(self.heap[right], self.heap[swap_idx]):
                swap_idx = right

            if swap_idx != idx:
                self.heap[idx], self.heap[swap_idx] = self.heap[swap_idx], self.heap[idx]
                idx = swap_idx
            else:
                break

    # -------------------- Offentlige metoder --------------------
    def insert(self, key):
        self.heap.append(key)
        self._bubble_up(len(self.heap)-1)

    def delete(self):
        if len(self.heap) <= 1:
            return None
        if len(self.heap) == 2:
            return self.heap.pop()
        top = self.heap[1]
        self.heap[1] = self.heap.pop()
        self._bubble_down(1)
        return top

    def print_heap(self):
        if len(self.heap) <= 1:
            print("Heap er tom.")
            return
        values = self.heap[1:]
        indices = list(range(1, len(self.heap)))

        # print værdier øverst
        for val in values:
            print(f"{val:^5}", end=' ')
        print()
        # print index nederst
        for idx in indices:
            print(f"{idx:^5}", end=' ')
        print("\n")

    # Konverter array til træ for plot
    def to_tree(self, idx=1):
        if idx >= len(self.heap):
            return None
        node = TreeNode(self.heap[idx])
        node.left = self.to_tree(2*idx)
        node.right = self.to_tree(2*idx+1)
        return node

    # -------------------- Check heap --------------------
    def check_heap(self):
        """
        Tjekker om arrayet opfylder heap-egenskaben.
        Udskriver resultatet.
        """
        n = len(self.heap)
        if n <= 1:
            print("Heap er tom. Den opfylder heap-egenskaben.")
            return True

        valid = True
        for i in range(1, n):
            left = 2*i
            right = 2*i + 1

            if left < n:
                if self.heap_type == "max" and self.heap[i] < self.heap[left]:
                    print(f"Fejl: Node {self.heap[i]} ved index {i} er mindre end venstre barn {self.heap[left]} ved index {left}")
                    valid = False
                elif self.heap_type == "min" and self.heap[i] > self.heap[left]:
                    print(f"Fejl: Node {self.heap[i]} ved index {i} er større end venstre barn {self.heap[left]} ved index {left}")
                    valid = False

            if right < n:
                if self.heap_type == "max" and self.heap[i] < self.heap[right]:
                    print(f"Fejl: Node {self.heap[i]} ved index {i} er mindre end højre barn {self.heap[right]} ved index {right}")
                    valid = False
                elif self.heap_type == "min" and self.heap[i] > self.heap[right]:
                    print(f"Fejl: Node {self.heap[i]} ved index {i} er større end højre barn {self.heap[right]} ved index {right}")
                    valid = False

        if valid:
            print(f"Arrayet opfylder heap-egenskaben for en {self.heap_type}-heap.")
        else:
            print(f"Arrayet opfylder IKKE heap-egenskaben for en {self.heap_type}-heap.")
        return valid

# ---------------------------------------------------
# Plotfunktion (genbrugt fra trees.py)
# ---------------------------------------------------
def add_edges(graph, node, parent=None):
    if node is None:
        return
    node_id = id(node)  # unik ID
    label = f"{node.val}"  # kun værdi
    graph.add_node(node_id, label=label)
    if parent is not None:
        graph.add_edge(parent, node_id)
    add_edges(graph, node.left, node_id)
    add_edges(graph, node.right, node_id)

def hierarchy_pos_inorder(node):
    pos = {}
    current_x = 0

    def helper(n, depth):
        nonlocal current_x
        if n is None:
            return
        helper(n.left, depth + 1)
        pos[id(n)] = (current_x, -depth)
        current_x += 1
        helper(n.right, depth + 1)

    helper(node, 0)
    return pos
def plot_tree(root):
    G = nx.DiGraph()
    add_edges(G, root)
    pos = hierarchy_pos_inorder(root)
    labels = nx.get_node_attributes(G, 'label')
    fig, ax = plt.subplots(figsize=(10, 6))
    nx.draw(G, pos=pos, labels=labels, with_labels=True,
            node_size=1500, node_color='lightblue', font_size=10, arrows=False)
    plt.show()

if __name__ == "__main__":
    """
    heap = PriorityQueue(heap_type="min")  # eller "max"
    #for v in [42,41,23,17,6,33,37,18,17,4]:
    #    heap.insert(v)
    for v in [5,9,11,14,18,19,21,33,17,27]:
        heap.insert(v)
    print("Heap før operationer:")
    heap.print_heap()
    heap.check_heap()
    plot_tree(heap.to_tree())
    # 1. insert 7
    heap.insert(7)
    print("Efter insert 7:")
    heap.print_heap()

    plot_tree(heap.to_tree())
    # 2. insert 15
    heap.insert(15)
    print("Efter insert 15:")
    heap.print_heap()

    plot_tree(heap.to_tree())
    # 3. deleteMin
    heap.delete()
    print("Efter deleteMin:")
    heap.print_heap()


    plot_tree(heap.to_tree())
    """
    arr = [None, 17,21,23,44,32,65,38,56,46,69,33,77,67,56,39,61,60,62,50,71]
    
    heap = PriorityQueue(heap_type="min")
    heap.heap = arr  # direkte tildeling
    heap.print_heap()
    heap.check_heap()

    plot_tree(heap.to_tree())
    arr = [None,4,17,12,20,25,15,38,22,30,24,45,67,18,40,42,46,56]

    heap = PriorityQueue(heap_type="min")
    heap.heap = arr  # direkte tildeling
    heap.print_heap()

    heap.check_heap()
    plot_tree(heap.to_tree())




# ---------------------------------------------------
# Hvad en min-heap faktisk garanterer
# ---------------------------------------------------
#
# En min-heap har præcis ÉN regel:
#
#   Hver forælder er mindre end eller lig med sine børn
#
# Det er det.
# Ikke mere. Ikke mindre.
#
# Formelt gælder for hvert indeks i:
#
#   heap[i] <= heap[2*i]
#   heap[i] <= heap[2*i + 1]
#
# ---------------------------------------------------
# Hvad en min-heap IKKE garanterer
# ---------------------------------------------------
#
# ❌ Sorterede deltræer
# ❌ At værdier i venstre deltræ er mindre end værdier i højre deltræ
# ❌ Nogen form for orden mellem fætre/kusiner, søskendes børn
#    eller hele deltræer
#
# En heap er en prioriteringsstruktur – ikke et søgetræ.
# ---------------------------------------------------

