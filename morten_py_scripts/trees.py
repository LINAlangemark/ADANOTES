from collections import deque
import matplotlib.pyplot as plt
import networkx as nx

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.height = 0
        self.balance_factor = 0

# --- Byg træ ---
def build_tree(preorder, inorder):
    if not preorder or not inorder:
        return None

    root_val = preorder[0]
    root = TreeNode(root_val)
    mid = inorder.index(root_val)

    root.left = build_tree(preorder[1:1+mid], inorder[:mid])
    root.right = build_tree(preorder[1+mid:], inorder[mid+1:])

    left_height = root.left.height if root.left else -1
    right_height = root.right.height if root.right else -1
    root.height = 1 + max(left_height, right_height)
    root.balance_factor = left_height - right_height

    return root

# --- Traverseringsfunktioner ---
def inorder_traversal(node):
    if node is None:
        return []
    return inorder_traversal(node.left) + [node.val] + inorder_traversal(node.right)

def postorder_traversal(node):
    if node is None:
        return []
    return postorder_traversal(node.left) + postorder_traversal(node.right) + [node.val]

def level_order_traversal(node):
    if node is None:
        return []
    result = []
    queue = deque([node])
    while queue:
        n = queue.popleft()
        result.append(n.val)
        if n.left:
            queue.append(n.left)
        if n.right:
            queue.append(n.right)
    return result
def is_balanced(node):
    """
    Returnerer True hvis træet er balanceret (AVL-balance),
    ellers False.
    """
    def _check(n):
        if n is None:
            return True, -1

        left_ok, left_h = _check(n.left)
        right_ok, right_h = _check(n.right)

        bf = left_h - right_h
        height = 1 + max(left_h, right_h)

        return left_ok and right_ok and abs(bf) <= 1, height

    ok, _ = _check(node)
    return ok
def is_complete_tree(root):
    if root is None:
        return True

    queue = deque([root])
    found_none = False

    while queue:
        node = queue.popleft()

        if node:
            if found_none:
                return False
            queue.append(node.left)
            queue.append(node.right)
        else:
            found_none = True

    return True
def is_perfect_tree(root):
    if root is None:
        return True

    h = tree_height(root)

    def _check(node, depth):
        if node is None:
            return True
        if node.left is None and node.right is None:
            return depth == h
        if node.left is None or node.right is None:
            return False
        return _check(node.left, depth + 1) and _check(node.right, depth + 1)

    return _check(root, 0)

# --- Insert i BST ---
def insert_node(root, val):
    if root is None:
        return TreeNode(val)
    if val < root.val:
        root.left = insert_node(root.left, val)
    elif val > root.val:
        root.right = insert_node(root.right, val)
    else:
        # værdien findes allerede, gør ingenting
        return root

    # Opdater højde og balance factor
    left_height = root.left.height if root.left else -1
    right_height = root.right.height if root.right else -1
    root.height = 1 + max(left_height, right_height)
    root.balance_factor = left_height - right_height
    return root

def delete_node(root, key):
    if root is None:
        return None
    
    # Naviger til node
    if key < root.val:
        root.left = delete_node(root.left, key)
    elif key > root.val:
        root.right = delete_node(root.right, key)
    else:
        # Node fundet
        if root.left is None:
            return root.right
        elif root.right is None:
            return root.left
        else:
            # Node med to børn: brug in-order successor
            successor = root.right
            while successor.left:
                successor = successor.left
            root.val = successor.val
            root.right = delete_node(root.right, successor.val)
    
    # Opdater height og balance_factor
    left_h = root.left.height if root.left else -1
    right_h = root.right.height if root.right else -1
    root.height = 1 + max(left_h, right_h)
    root.balance_factor = left_h - right_h
    
    return root

    # Opdater height og balance_factor
    left_h = root.left.height if root.left else -1
    right_h = root.right.height if root.right else -1
    root.height = 1 + max(left_h, right_h)
    root.balance_factor = left_h - right_h
    
    return root
def rotate_node(root, target_val, direction='left'):
    """
    Manually rotate the subtree rooted at target_val.
    direction: 'left' or 'right'
    Returns the new root of the tree.
    """
    if root is None:
        return None

    # Hvis vi har fundet noden
    if root.val == target_val:
        if direction == 'left':
            return rotate_left(root)
        elif direction == 'right':
            return rotate_right(root)
        else:
            raise ValueError("Direction must be 'left' or 'right'")

    # Naviger til venstre
    if root.left:
        root.left = rotate_node(root.left, target_val, direction)
    # Naviger til højre
    if root.right:
        root.right = rotate_node(root.right, target_val, direction)

    # Opdater denne node efter rotation i child
    update_node(root)
    return root

def rotate_left(x):
    if x is None or x.right is None:
        return x
    y = x.right
    T2 = y.left

    y.left = x
    x.right = T2

    update_node(x)
    update_node(y)
    return y

def rotate_right(y):
    if y is None or y.left is None:
        return y
    x = y.left
    T2 = x.right

    x.right = y
    y.left = T2

    update_node(y)
    update_node(x)
    return x

def update_node(node):
    left_h = node.left.height if node.left else -1
    right_h = node.right.height if node.right else -1
    node.height = 1 + max(left_h, right_h)
    node.balance_factor = left_h - right_h


# --- Internal Path Length (IPL) ---
def internal_path_length(node, depth=0):
    if node is None:
        return 0
    return depth + internal_path_length(node.left, depth + 1) + internal_path_length(node.right, depth + 1)
def internal_path_length_no_leaves(node, depth=0):
    if node is None:
        return 0

    # Check if leaf
    is_leaf = node.left is None and node.right is None

    current = 0 if is_leaf else depth

    return (
        current
        + internal_path_length_no_leaves(node.left, depth + 1)
        + internal_path_length_no_leaves(node.right, depth + 1)
    )

# --- Plot funktion med struktureret layout ---
def add_edges(graph, node, parent=None):
    if node is None:
        return
    label = f"{node.val}\nH={node.height}\nB={node.balance_factor}"
    graph.add_node(node.val, label=label)
    if parent is not None:
        graph.add_edge(parent, node.val)
    add_edges(graph, node.left, node.val)
    add_edges(graph, node.right, node.val)

def hierarchy_pos_by_value(node, x=0, y=0, dx=1.0, pos=None, parent_val=None):
    """
    Placerer noder baseret på deres værdi i forhold til forælder.
    Venstre børn placeres til venstre, højre børn til højre.
    dx bestemmer vandret afstand.
    """
    if pos is None:
        pos = {}
    if node is None:
        return pos

    # Juster x baseret på om noden er mindre eller større end forælder
    if parent_val is not None:
        if node.val < parent_val:
            x -= dx
        else:
            x += dx

    # Placer venstre og højre subtræer med halveret dx
    if node.left:
        pos = hierarchy_pos_by_value(node.left, x, y - 1, dx / 2, pos, node.val)
    pos[node.val] = (x, y)
    if node.right:
        pos = hierarchy_pos_by_value(node.right, x, y - 1, dx / 2, pos, node.val)

    return pos

def plot_tree(root):
    G = nx.DiGraph()
    add_edges(G, root)
    pos = hierarchy_pos_by_value(root, dx=4)  # større dx giver mere plads mellem noder

    labels = nx.get_node_attributes(G, 'label')
    fig, ax = plt.subplots()
    nx.draw(G, pos=pos, labels=labels, with_labels=True, arrows=False,
            node_size=1500, node_color='lightblue', font_size=8)

    def on_key(event):
        if event.key == 'escape':
            plt.close(fig)

    fig.canvas.mpl_connect('key_press_event', on_key)
    plt.show()
def tree_height(node):
    if node is None:
        return -1  # tomt træ har højde -1, blade har 0
    return max(tree_height(node.left), tree_height(node.right)) + 1
def node_depths(node, depth=0, depths=None):
    if depths is None:
        depths = {}
    if node is None:
        return depths
    depths[node.val] = depth
    node_depths(node.left, depth + 1, depths)
    node_depths(node.right, depth + 1, depths)
    return depths

def print_node_depths_level_order(root):
    if root is None:
        return
    queue = deque([(root, 0)])  # tuple: (node, depth)
    while queue:
        node, depth = queue.popleft()
        print(f"  Node\t{node.val}:\tdybde {depth}")
        if node.left:
            queue.append((node.left, depth + 1))
        if node.right:
            queue.append((node.right, depth + 1))

def check_avl_tree(node):
    """
    Tjekker om træet er et AVL-træ og printer forklaringer.
    Opdaterer balance_factor og height på noderne.
    """
    def _check(node):
        if node is None:
            return True, -1  # tomt træ er AVL, højde -1

        left_avl, left_height = _check(node.left)
        right_avl, right_height = _check(node.right)

        balance_factor = left_height - right_height
        node.balance_factor = balance_factor
        node.height = 1 + max(left_height, right_height)

        node_avl = left_avl and right_avl and (-1 <= balance_factor <= 1)

        if not (-1 <= balance_factor <= 1):
            print(f"Node {node.val} har balancefactor {balance_factor} (udenfor [-1,1])")
        return node_avl, node.height

    avl, _ = _check(node)

    if avl:
        print("Træet opfylder alle AVL-kravene: balancefaktor mellem -1 og 1 for alle noder.")
    else:
        print("Træet er ikke et AVL-træ.")
def count_nodes(node):
    """Return the total number of nodes in the tree."""
    if node is None:
        return 0
    return 1 + count_nodes(node.left) + count_nodes(node.right)

def can_be_perfect_tree(node):
    """
    Check if the tree could potentially be a perfect tree:
    i.e., number of nodes = 2^(h+1) - 1 for some height h.
    Returns (possible: bool, height: int)
    """
    n = count_nodes(node)
    h = 0
    while (2 ** (h + 1) - 1) < n:
        h += 1
    if 2 ** (h + 1) - 1 == n:
        return True, h
    else:
        return False, h

def balance_avl_tree(node):
    """
    Går rekursivt gennem træet og balancerer det til AVL ved
    automatisk at udføre rotationer, hvor det er nødvendigt.
    """
    if node is None:
        return None

    # Først balancer venstre og højre subtræer
    node.left = balance_avl_tree(node.left)
    node.right = balance_avl_tree(node.right)

    # Opdater height og balance factor
    update_node(node)

    # Hvis balancefactor udenfor [-1,1], fix med rotationer
    if node.balance_factor > 1:  # venstre tung
        if node.left and node.left.balance_factor < 0:
            # Venstre-højre tilfælde
            node.left = rotate_left(node.left)
            print(f"Rotation: left on {node.left.val} (venstre-højre case)")
        # Venstre-venstre tilfælde
        print(f"Rotation: right on {node.val} (venstre-venstre case)")
        node = rotate_right(node)
    elif node.balance_factor < -1:  # højre tung
        if node.right and node.right.balance_factor > 0:
            # Højre-venstre tilfælde
            node.right = rotate_right(node.right)
            print(f"Rotation: right on {node.right.val} (højre-venstre case)")
        # Højre-højre tilfælde
        print(f"Rotation: left on {node.val} (højre-højre case)")
        node = rotate_left(node)

    # Opdater igen efter rotation
    update_node(node)
    return node
def print_ipl_contributions(node, depth=0):
    if node is None:
        return

    is_leaf = node.left is None and node.right is None
    node_type = "blad" if is_leaf else "intern"

    print(f"  Node {node.val}: dybde={depth}, type={node_type}")

    print_ipl_contributions(node.left, depth + 1)
    print_ipl_contributions(node.right, depth + 1)

def run_tasks(root):
    print("=" * 45)
    print("           ANALYSE AF BINÆRT TRÆ")
    print("=" * 45)

    # --- Traverseringer ---
    print("\nTraverseringer")
    print(f"  In-order:    {inorder_traversal(root)}")
    print(f"  Post-order:  {postorder_traversal(root)}")
    print(f"  Level-order: {level_order_traversal(root)}")

    # --- Træets egenskaber ---
    print("\nTræets egenskaber")
    print(f"  Balanceret:       {is_balanced(root)}")
    print(f"  Komplet:          {is_complete_tree(root)}")
    print(f"  Perfekt:          {is_perfect_tree(root)}")
    print(f"  Træets højde:     {tree_height(root)}")
    print(f"  Antal noder:      {count_nodes(root)}")
    # --- Strukturdata ---
    print(f"  Internal Path Length (IPL): {internal_path_length(root)}")
    print(f"  Internal Path Length (uden blade):  {internal_path_length_no_leaves(root)}")

    possible_perfect, perfect_height = can_be_perfect_tree(root)
    if possible_perfect:
        print("\nPerfekt træ muligt?")
        print(f"   Eftersom antallet af noder ({count_nodes(root)}) er 2^{perfect_height+1}-1 bliver den optimale (mindste) højde {perfect_height}.")
    else:
        print(f"\nPerfekt træ muligt? Nej. "
              f"   Antallet af noder ({count_nodes(root)}) passer ikke til 2^h - 1.")

    
    print("\nIPL-bidrag pr. node:")
    print_ipl_contributions(root)
    # --- Node-dybder ---
    # print("\nNode-dybder (level-order)")
    # print_node_depths_level_order(root)

    # --- AVL-tjek ---
    print("\nAVL-kontrol")
    check_avl_tree(root)

    # --- Visualisering ---
    plot_tree(root)


# -------------------------------- MAIN --------------------------------
# Værdier i values-array'et skal skrive i pre-order rækkefølge.
# values = [11,2,1,9,3,13,57,25,17,90]
#values = [25, 20, 10, 5, 1, 8, 12, 15, 22, 36, 30, 28, 40, 38, 48, 45, 50]
# values = [100,90,80,70,85,95,92,97,110,105,103,108,120,111,130]
# values = [7,4,3,2,1,28,55,51,48,40,35,60,58,57,69]
# values = [2,1,3] # perfekt eksempel
# Final exercise:
values = [50,48,30,20,15,25,32,31,35,70,65,67,66,69,90,98,94,99]
root = None
for v in values:
    root = insert_node(root, v)


"""
root = delete_node(root,105)
root = insert_node(root,83)
root = delete_node(root,130)
root = insert_node(root,60)
root = delete_node(root,95)
"""

run_tasks(root)
"""
root = insert_node(root,3)
root = insert_node(root,12)
check_avl_tree(root)
plot_tree(root)
root = delete_node(root,12)
root = rotate_node(root,57,'right')
plot_tree(root)
root = rotate_node(root,13,'left')
plot_tree(root)
check_avl_tree(root)
"""
"""
# Automatisk balancering
root = balance_avl_tree(root)
plot_tree(root)

# Tjek AVL-status og print
check_avl_tree(root)
plot_tree(root)
"""

