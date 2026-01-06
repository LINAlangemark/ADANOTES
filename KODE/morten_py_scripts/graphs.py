import networkx as nx
import matplotlib.pyplot as plt
from collections import deque
import math

A, B, C, D, E, F, G, H, I, J, K, L = range(12)
a, b, c, d, e, f, g, h, i, j, k, l = range(12)
def dijkstra_table(graph, start):
    # Initialisering
    nodes = list(graph.nodes())
    known = {n: False for n in nodes}
    dv = {n: math.inf for n in nodes}
    pv = {n: None for n in nodes}

    dv[start] = 0

    while not all(known.values()):
        # Vælg ukendt node med mindste dv
        unvisited = {n: dv[n] for n in nodes if not known[n]}
        u = min(unvisited, key=unvisited.get)
        known[u] = True

        for v in graph.neighbors(u):
            if not known[v]:
                edge_weight = graph[u][v]['value']
                if dv[u] + edge_weight < dv[v]:
                    dv[v] = dv[u] + edge_weight
                    pv[v] = u

    # Lav en "tabel" som liste af rækker
    table = []
    for n in nodes:
        table.append({
            'v': n,
            'known': known[n],
            'dv': dv[n],
            'pv': pv[n]
        })
    return table
def dijkstra_shortest_paths(graph, start, labels=None):
    """
    Beregner Dijkstra og viser både:
    1) fuld tabel med dv og pv
    2) korteste stier fra start-node
    """
    nodes = list(graph.nodes())
    known = {n: False for n in nodes}
    dv = {n: math.inf for n in nodes}
    pv = {n: None for n in nodes}

    dv[start] = 0

    while not all(known.values()):
        unvisited = {n: dv[n] for n in nodes if not known[n]}
        u = min(unvisited, key=unvisited.get)
        known[u] = True

        for v in graph.neighbors(u):
            if not known[v]:
                edge_weight = graph[u][v]['value']
                if dv[u] + edge_weight < dv[v]:
                    dv[v] = dv[u] + edge_weight
                    pv[v] = u

    # --- FULD TABEL ---
    print("\nFuld Dijkstra-tabel:")
    print("\tv\tknown\tdv\tpv")
    for n in sorted(nodes):
        pv_label = labels[pv[n]] if pv[n] is not None and labels else pv[n] if pv[n] is not None else "-"
        v_label = labels[n] if labels else n
        print(f"\t{v_label}\t{known[n]}\t{dv[n]}\t{pv_label}")

    # --- KORTESTE STIER FRA START ---
    print("\nKorteste stier fra start-node:")
    print("\tv\tdv\tsti")
    for n in sorted(nodes):
        if dv[n] < math.inf:
            # Genskab sti fra start til n
            path = []
            current = n
            while current is not None:
                path.append(labels[current] if labels else current)
                current = pv[current]
            path = list(reversed(path))
            print(f"\t{labels[n] if labels else n}\t{dv[n]}\t{' -> '.join(map(str,path))}")
        else:
            print(f"\t{labels[n] if labels else n}\t∞\tIngen sti")

def topological_sort(graph):
    """
    Udfører topologisk sortering på en rettet graf (DiGraph).
    Returnerer en liste af noder i topologisk orden.
    """
    if not graph.is_directed():
        raise ValueError("Topologisk sortering kræver en rettet graf (DiGraph)")

    # Indegree for hver node
    indegree = {u: 0 for u in graph.nodes()}
    for u, v in graph.edges():
        indegree[v] += 1

    # Kø med noder der har indegree 0
    queue = deque([u for u in indegree if indegree[u] == 0])
    topo_order = []

    while queue:
        u = queue.popleft()
        topo_order.append(u)

        for v in graph.neighbors(u):
            indegree[v] -= 1
            if indegree[v] == 0:
                queue.append(v)

    # Hvis ikke alle noder er med → cyklus i grafen
    if len(topo_order) != len(graph.nodes()):
        raise ValueError("Grafen indeholder en cyklus – topologisk sortering er ikke mulig")

    return topo_order

# --- Opret grafer med edge values ---
def build_graph(edges, directed=False):
    """
    edges: liste af tuples (u, v, value)
           fx (1,2,5) = kant fra 1 til 2 med værdi 5
    directed: True for DiGraph, False for Graph
    """
    G = nx.DiGraph() if directed else nx.Graph()
    for u, v, value in edges:
        G.add_edge(u, v, value=value)
    return G

# --- Traverseringer ---
def bfs(graph, start):
    visited = set()
    queue = deque([start])
    order = []

    while queue:
        node = queue.popleft()
        if node not in visited:
            visited.add(node)
            order.append(node)
            for neighbor in graph.neighbors(node):
                if neighbor not in visited:
                    queue.append(neighbor)
    return order

def dfs(graph, start):
    visited = set()
    stack = [start]
    order = []

    while stack:
        node = stack.pop()
        if node not in visited:
            visited.add(node)
            order.append(node)
            for neighbor in reversed(list(graph.neighbors(node))):
                if neighbor not in visited:
                    stack.append(neighbor)
    return order

def plot_graph(graph, node_labels_dict=None):
    """
    graph: networkx graf (DiGraph eller Graph)
    node_labels_dict: dict {node_id: label} fx {0:'A',1:'B'}
    """
    # Hvis labels ikke er givet, brug node-id som label
    labels = node_labels_dict if node_labels_dict else {n: str(n) for n in graph.nodes()}

    # Lav layout baseret på urettet version af grafen, så DiGraph også bliver pænt
    UG = graph.to_undirected()
    pos = nx.spring_layout(UG, seed=42)

    # Tegn noder og labels
    nx.draw_networkx_nodes(graph, pos, node_size=800, node_color='lightgreen')
    nx.draw_networkx_labels(graph, pos, labels=labels, font_size=10)

    # Tegn kanter
    if graph.is_directed():
        # Tegn pile på DiGraph
        nx.draw_networkx_edges(graph, pos, arrowstyle='-|>', arrowsize=20)
    else:
        # Urettet graf
        nx.draw_networkx_edges(graph, pos)

    # Tegn edge labels
    edge_labels = nx.get_edge_attributes(graph, 'value')
    nx.draw_networkx_edge_labels(graph, pos, edge_labels=edge_labels)

    plt.axis('off')
    plt.show()
def prim_mst_ordered(edges, start):
    G = nx.Graph()
    for u, v, w in edges:
        G.add_edge(u, v, value=w)

    visited = {start}
    mst_edges = []
    total_weight = 0

    while len(visited) < G.number_of_nodes():
        candidate_edges = []

        for u in visited:
            for v in G.neighbors(u):
                if v not in visited:
                    candidate_edges.append((u, v, G[u][v]['value']))

        # choose minimum weight edge crossing the cut
        u, v, w = min(candidate_edges, key=lambda x: x[2])

        visited.add(v)
        mst_edges.append((u, v, w))
        total_weight += w

    return mst_edges, total_weight

# --- Minimum Spanning Tree fra edges ---
def minimum_spanning_tree_from_edges(edges, algorithm='kruskal'):
    """
    edges: liste af tuples (u, v, value)
    algorithm: 'kruskal' eller 'prim'
    
    Returnerer MST kanter, total vægt og algoritme
    """
    # Byg grafen
    G = nx.Graph()
    for u, v, value in edges:
        G.add_edge(u, v, value=value)
    
    # Beregn MST
    if algorithm.lower() == 'kruskal':
        mst = nx.minimum_spanning_tree(G, algorithm='kruskal', weight='value')
    elif algorithm.lower() == 'prim':
        mst = nx.minimum_spanning_tree(G, algorithm='prim', weight='value')
    else:
        raise ValueError("Algoritme skal være 'kruskal' eller 'prim'")
    
    # Sortér kanterne efter vægt (tilnærmet rækkefølge som Kruskal vælger dem)
    edges_sorted = sorted(mst.edges(data=True), key=lambda e: e[2]['value'])
    edge_list = [(u, v, d['value']) for u, v, d in edges_sorted]
    total_weight = sum(d['value'] for _, _, d in edges_sorted)
    
    return edge_list, total_weight, algorithm.capitalize()

def generate_labels(nodes, style="num"):
    """
    style:
    'num' -> 1, 2, 3, ...
    'ABC'     -> A, B, C, ...
    'v'       -> v1, v2, v3, ...
    """
    nodes = sorted(nodes)

    if style == "num":
        return {n: str(i) for i, n in enumerate(nodes)}

    elif style == "ABC":
        return {n: chr(ord('A') + i) for i, n in enumerate(nodes)}

    elif style == "abc":
        return {n: chr(ord('a') + i) for i, n in enumerate(nodes)}

    elif style == "v":
        return {n: f"v{i+1}" for i, n in enumerate(nodes)}

    else:
        raise ValueError("Unknown label style")

def graph_properties(G):
    """
    Tjekker og returnerer grundlæggende egenskaber for grafen G.
    """
    props = {}

    props['Directed/rettet'] = G.is_directed()

    # Vægtet?
    weighted = any('value' in data for u, v, data in G.edges(data=True))
    props['vægtet'] = weighted

    # Forbundne noder og tæthed
    if not G.is_directed():
        props['forbundet'] = nx.is_connected(G)
        props['tæthed'] = nx.density(G)
    else:
        props['stærkt_forbundet'] = nx.is_strongly_connected(G)
        props['svagt_forbundet'] = nx.is_weakly_connected(G)
        props['tæthed'] = nx.density(G)

    props['antal_noder'] = G.number_of_nodes()
    props['antal_kanter'] = G.number_of_edges()

    # Klassificer tæthed
    d = props['tæthed']
    if d < 0.3:
        props['klassifikation_tæthed'] = "sparsom"
    elif d < 0.7:
        props['klassifikation_tæthed'] = "moderat"
    else:
        props['klassifikation_tæthed'] = "tæt"

    return props

def build_mst_graph(edges, algorithm="kruskal"):
    """
    Returns a NetworkX Graph containing only the MST edges
    """
    G = nx.Graph()
    for u, v, value in edges:
        G.add_edge(u, v, value=value)

    if algorithm.lower() == "kruskal":
        mst = nx.minimum_spanning_tree(G, algorithm="kruskal", weight="value")
    elif algorithm.lower() == "prim":
        mst = nx.minimum_spanning_tree(G, algorithm="prim", weight="value")
    else:
        raise ValueError("Algorithm must be 'kruskal' or 'prim'")

    return mst

def mst_edges_to_graph(mst_edges):
    """
    mst_edges: list of (u, v, weight)
    Returns a NetworkX Graph of the MST
    """
    G = nx.Graph()
    for u, v, w in mst_edges:
        G.add_edge(u, v, value=w)
    return G
def dijkstra_print_markdown(graph, start, labels=None):
    """
    Prints Dijkstra output as Markdown tables:
    - Full Dijkstra table
    - Shortest paths from start node
    """
    table = dijkstra_table(graph, start)

    def label(n):
        return labels[n] if labels else n

    # --- Full table ---
    print("\n### Fuld Dijkstra-tabel\n")
    print("| v | known | dv | pv |")
    print("|---|:-----:|---:|---|")
    for row in table:
        pv_label = label(row['pv']) if row['pv'] is not None else "-"
        print(f"| {label(row['v'])} | {row['known']} | {row['dv']} | {pv_label} |")

    # --- Shortest paths ---
    print("\n### Korteste stier fra start-node\n")
    print("| v | dv | sti |")
    print("|---|---:|-----|")

    # Reconstruct paths
    nodes = list(graph.nodes())
    known = {n: False for n in nodes}
    dv = {n: math.inf for n in nodes}
    pv = {n: None for n in nodes}
    dv[start] = 0

    while not all(known.values()):
        unvisited = {n: dv[n] for n in nodes if not known[n]}
        u = min(unvisited, key=unvisited.get)
        known[u] = True
        for v in graph.neighbors(u):
            if not known[v]:
                w = graph[u][v]['value']
                if dv[u] + w < dv[v]:
                    dv[v] = dv[u] + w
                    pv[v] = u

    for n in sorted(nodes):
        if dv[n] < math.inf:
            path = []
            current = n
            while current is not None:
                path.append(label(current))
                current = pv[current]
            path = list(reversed(path))
            print(f"| {label(n)} | {dv[n]} | {' -> '.join(path)} |")
        else:
            print(f"| {label(n)} | ∞ | Ingen sti |")

def run_graph(graph_data, start_node=0, mst_algorithm="kruskal"):
    print("=" * 45)
    print("                  Graph")
    print("=" * 45)
    G = build_graph(
        graph_data["edges"],
        directed=graph_data.get("directed", False)
    )
    # Get graph properties
    """
    props = graph_properties(G)
    print("Graph properties:")
    for k, v in props.items():
        print(f"\t{k}: {v}")
    """
    label_data = graph_data.get("labels", "num")
    # If labels is already a dict, use it; otherwise generate labels
    if isinstance(label_data, dict):
        labels = label_data
    else:
        labels = generate_labels(G.nodes(), label_data)
    props = graph_properties(G)

    print("\nGrafens egenskaber:")
    # 1. Rettet eller urettet
    if G.is_directed():
        print(f"- Grafen er rettet: Kanter har retning")
    else:
        print(f"- Grafen er urettet: Kanter har ingen retning")

    # 2. Vægtet eller ej
    if props['vægtet']:
        print("- Grafen er vægtet: Kanterne har tilknyttede værdier")
    else:
        print("- Grafen er ikke vægtet: Alle kanter behandles ens")
    # 3. Forbindelser
    def ja_nej(value):
        return "ja" if value else "nej"
    if G.is_directed():
        print(f"- Grafen er stærkt forbundet: {ja_nej(props['stærkt_forbundet'])} (Kan alle nå alle via kanter i pilens retning?)")
        print(f"- Grafen er svagt forbundet: {ja_nej(props['svagt_forbundet'])} (Kan alle nå alle, hvis man ignorerer retninger?)")
    else:
        print(f"- Grafen er forbundet: {ja_nej(props['forbundet'])} (Kan alle noder nås fra hinanden via kanter?)")

    # 4. Tæthed
    print(f"- Grafens tæthed: {props['tæthed']:.2f} ({props['klassifikation_tæthed']})")
    print("  - Tæthed = hvor mange af de mulige kanter, der rent faktisk findes i grafen")

    # 5. Antal noder og kanter
    print(f"- Antal noder: {props['antal_noder']} (Hvor mange punkter/grafer der er)")
    print(f"- Antal kanter: {props['antal_kanter']} (Hvor mange forbindelser der findes mellem noder)")
    print("\n")
    # ----- TOPOLOGICAL SORT -----
    if G.is_directed():
        try:
            topo = topological_sort(G)
            print("Topologisk sortering:")
            print([labels[n] for n in topo])
            print("Grafen er rettet og indeholder ingen cyklusser, derfor kan noderne ordnes i topologisk rækkefølge.")
        except ValueError as e:
            print(e)
    else:
        print("Topologisk sortering er ikke muligt, da grafen er retningsløg.")
    if not G.is_directed():
        if not props['forbundet']:
            print("\nMST kan ikke beregnes: Grafen er urettet men ikke forbundet.")
            print("Alle noder skal kunne nås fra hinanden for at en MST kan eksistere.")
        else:
            print(f"\nMST kan beregnes med både Prim og Kruskal (Grafen er urettet og forbundet).")
    else:
        print("\nMST kan ikke beregnes: Grafen er rettet. MST gælder kun for urettede grafer.")
    # ----- DIJKSTRA -----
    # Check om Dijkstra giver mening
    if not G.is_directed():
        if not props['forbundet']:
            print("\nDijkstra kan ikke udføres: Grafen er ikke forbundet. Ikke alle noder kan nås fra hinanden.")
        elif any(d < 0 for u, v, d in G.edges(data='value')):
            print("\nDijkstra kan ikke udføres: Grafen indeholder negative kantværdier, hvilket Dijkstra ikke håndterer.")
        else:
            print("\nDijkstra kan udføres: Grafen er urettet, forbundet og har ingen negative kanter. Dog afhænger relevansen af start noden.")
    else:  # Rettet graf
        if any(d < 0 for u, v, d in G.edges(data='value')):
            print("\nDijkstra kan ikke udføres: Grafen indeholder negative kantværdier.")
        else:
            print("\nDijkstra kan udføres: Grafen er rettet og har ingen negative kanter. Dog afhænger relevansen af start noden.")

    dijkstra_shortest_paths(G, start_node, labels)
    dijkstra_print_markdown(G, start_node, labels)

    # ----- MST -----
    if not G.is_directed():
        if mst_algorithm.lower() == "prim":
            mst_edges, total = prim_mst_ordered(graph_data["edges"], start_node)

            print(f"\nMST (Prim, start = {labels[start_node]}) – total vægt = {total}")
            for u, v, w in mst_edges:
                print(f"\t({labels[u]}-{labels[v]}, {w})")

            # 🔹 plot Prim MST
            mst_G = mst_edges_to_graph(mst_edges)
            plot_graph(G, labels)
            plot_graph(mst_G, labels)

        else:  # Kruskal
            mst_edges, total, algo = minimum_spanning_tree_from_edges(
                graph_data["edges"], mst_algorithm
            )

            print(f"\nMST ({algo}) – total vægt = {total}")
            for u, v, w in mst_edges:
                print(f"\t({labels[u]}-{labels[v]}, {w})")

            # 🔹 plot Kruskal MST
            mst_G = mst_edges_to_graph(mst_edges)
            plot_graph(G, labels)
            plot_graph(mst_G, labels)
    else:
        plot_graph(G, labels)

"""
edges = [
    (0,1,1), (0,4,1), (0,5,2), (1,2,8), (0,2,6),
    (2,3,14), (2,5,3), (3,6,1), (3,7,1), (4,8,7),
    (5,6,20), (5,8,3), (5,9,5), (5,10,8),
    (6,3,1), (6,7,4), (6,11,8), (7,11,3),
    (8,9,4), (9,10,2), (10,11,5)
]
"""
# edges = [(E,A,7),(A,C,12),(A,D,60),(B,A,10),(C,B,20),(C,D,32)]

# edges = [(F,E,4),(E,D,1),(D,B,9),(B,A,1),(B,C,7),(A,I,4),(C,H,5),(H,I,7),(I,D,2),(I,J,5),(J,G,10)]
"""
run_graph({
    "directed": False,
    "edges": edges,
    "labels": "num"
    },
    start_node=0,
    mst_algorithm="kruskal"
)
run_graph({
    "directed": False,
    "edges": edges,
    "labels": "num"
    },
    start_node=0,
    mst_algorithm="prim"
)
edges = [(A,B,22),(A,C,9),(A,D,12),(B,H,34),(B,F,36),(B,C,35),(C,F,42),(C,E,65),(C,D,4),(D,E,33),(D,I,30),(E,F,18),(E,G,23),(F,H,24),(F,G,39),(G,H,25),(G,I,21),(H,I,19)]
run_graph({
    "directed": False,
    "edges": edges,
    "labels": "ABC"
    },
    start_node=A,
    mst_algorithm="prim"
          )

# edges = [(a,b,4),(a,h,8),(b,c,8),(b,h,11),(c,d,7),(c,f,4),(c,i,2),(d,e,9),(d,f,14),(e,f,10),(f,g,2),(g,h,1),(g,i,6),(h,i,7)]
run_graph({
    "directed": False,
    "edges": edges,
    "labels": "abc"
    },
    start_node=A,
    mst_algorithm="kruskal"
          )
edges = [(a,b,1),(a,c,5),(b,e,7),(b,d,8),(b,c,4),(c,d,6),(c,f,2),(d,e,11),(d,f,9),(e,g,10),(e,f,3),(g,f,12)]
run_graph({
    "directed": False,
    "edges": edges,
    "labels": "abc"
    },
    start_node=A,
    mst_algorithm="prim"
)
city_labels = {
    0: "Seattle",       # A / a
    1: "Minneapolis",   # B / b
    2: "Denver",        # C / c
    3: "San Fran",      # D / d
    4: "Las Vegas",     # E / e
    5: "Los Angeles",   # F / f
    6: "Chicago",       # G / g
    7: "Dallas",        # H / h
    8: "Boston",        # I / i
    9: "Washington DC", # J / j
    10: "Miami",        # K / k
    11: "New York"      # L / l
}

edges = [(A,B,2661),(A,C,2161),(A,D,1306),(B,G,661),(B,C,1483),(B,H,1532),(C,E,1225),(C,H,1258),(E,F,435),(D,E,919),(D,F,629),(E,H,1983),(G,I,1613),(G,J,1145),(H,J,2113),(H,K,2161),(I,L,338),(I,J,725),(J,L,383),(J,K,1709),(K,L,2145)]
run_graph({
    "directed": False,
    "edges": edges,
    "labels": city_labels
    },
    start_node=A,
    mst_algorithm="prim"
)

edges = [(A,B,3),(A,D,4),(A,E,4),(B,C,10),(B,E,2),(B,F,3),(C,F,6),(C,G,1),(D,E,5),(D,H,6),(E,F,11),(E,H,2),(E,I,1),(F,G,2),(F,I,3),(F,J,11),(G,J,8),(H,I,4),(I,J,7)]
run_graph({
    "directed": False,
    "edges": edges,
    "labels": 'ABC'
    },
    start_node=A,
    mst_algorithm="prim"
)

edges = [(F,E,4),(E,D,1),(D,B,9),(B,A,1),(B,C,7),(A,C,1),(A,I,4),(C,H,5),(H,I,7),(I,D,2),(I,J,5),(J,G,10)]
run_graph({
    "directed": False,
    "edges": edges,
    "labels": 'ABC'
    },
    start_node=F,
    mst_algorithm="kruskal"
)
"""
edges1 = [(A,C,12,),(A,D,60),(B,A,10),(C,B,20),(C,D,32),(E,A,7)] # Directed
edges2 = [(0,1,3),(0,3,7),(0,4,8),(1,2,1),(1,3,4),(3,2,2),(4,3,3)] # Directed
edges3 = [(0,2,0.26),(0,4,0.38),(0,6,0.58),(0,7,0.16),(1,2,0.36),(1,3,0.29),(1,5,0.32),(1,7,0.19),(2,3,0.17),(2,6,0.40),(2,7,0.34),(3,6,0.52),(4,5,0.35),(4,6,0.93),(4,7,0.37),(5,7,0.28)] # Undirected

run_graph({
    "directed": True,
    "edges": edges1,
    "labels": 'ABC'
    },
    start_node=E,
    mst_algorithm="kruskal"
)

run_graph({
    "directed": True,
    "edges": edges2,
    "labels": 'num'
    },
    start_node=A,
    mst_algorithm="kruskal"
)
run_graph({
    "directed": False,
    "edges": edges3,
    "labels": 'num'
    },
    start_node=A,
    mst_algorithm="kruskal"
)

