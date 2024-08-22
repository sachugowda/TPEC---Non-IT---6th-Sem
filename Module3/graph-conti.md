
# Introduction to Weighted and Directed Graphs

In graph theory, **Weighted Graphs** are graphs where each edge has a numerical value, called the weight. These weights often represent costs, distances, or capacities. **Directed Graphs (Digraphs)** are graphs where edges have a direction, meaning they go from one vertex to another in a specific order.

### Key Concepts:
- **Weighted Graph**: Each edge in the graph has a weight associated with it.
- **Directed Graph**: Each edge has a direction, from a source vertex to a destination vertex.
- **Weighted Directed Graph**: Combines both properties where each edge has both a weight and a direction.

### Example Representation of a Weighted Directed Graph

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 5

// Function to print the adjacency matrix
void printAdjacencyMatrix(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int vertices) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices = MAX_VERTICES;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0};

    // Example edges with weights for a directed graph
    adjMatrix[0][1] = 5;
    adjMatrix[1][2] = 3;
    adjMatrix[2][3] = 1;
    adjMatrix[3][4] = 2;
    adjMatrix[4][0] = 4;

    printAdjacencyMatrix(adjMatrix, vertices);

    return 0;
}
```

---

# Minimum Spanning Trees (MST)

A **Minimum Spanning Tree (MST)** of a graph is a subgraph that connects all the vertices together, without any cycles, and with the minimum possible total edge weight.

### Algorithms for MST:
- **Kruskal's Algorithm**: Sort all the edges in non-decreasing order of their weight. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If not, include it. Repeat until there are V-1 edges in the spanning tree.
- **Prim's Algorithm**: Start with a vertex, add the least weight edge from the vertex to the tree. Continue adding the least weight edges that connect vertices in the tree to vertices outside the tree until all vertices are included.

### Kruskal's Algorithm Example in C

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100
#define MAX_VERTICES 5

typedef struct {
    int src, dest, weight;
} Edge;

typedef struct {
    int V, E;
    Edge edges[MAX_EDGES];
} Graph;

typedef struct {
    int parent, rank;
} Subset;

Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    return graph;
}

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank) {
        subsets[rootX].parent = rootY;
    } else if (subsets[rootX].rank > subsets[rootY].rank) {
        subsets[rootY].parent = rootX;
    } else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

int compareEdges(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->weight > edgeB->weight;
}

void KruskalMST(Graph* graph) {
    int V = graph->V;
    Edge result[MAX_VERTICES];
    int e = 0;
    int i = 0;

    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);

    Subset* subsets = (Subset*)malloc(V * sizeof(Subset));
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E) {
        Edge nextEdge = graph->edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    printf("Following are the edges in the constructed MST:\n");
    for (i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
    }
}

int main() {
    int V = MAX_VERTICES;
    int E = 7;
    Graph* graph = createGraph(V, E);

    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = 10;

    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].weight = 6;

    graph->edges[2].src = 0;
    graph->edges[2].dest = 3;
    graph->edges[2].weight = 5;

    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].weight = 15;

    graph->edges[4].src = 2;
    graph->edges[4].dest = 3;
    graph->edges[4].weight = 4;

    graph->edges[5].src = 2;
    graph->edges[5].dest = 4;
    graph->edges[5].weight = 7;

    graph->edges[6].src = 3;
    graph->edges[6].dest = 4;
    graph->edges[6].weight = 9;

    KruskalMST(graph);

    return 0;
}
```

### Prim's Algorithm Example in C

```c
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], minIndex = v;

    return minIndex;
}

void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0},
    };

    primMST(graph);

    return 0;
}
```

---

# Dijkstra's Algorithm

**Dijkstra's Algorithm** is a famous algorithm for finding the shortest path between nodes in a graph, which may represent, for example, road networks. It is a greedy algorithm that works well with graphs having non-negative weights.

### Dijkstra's Algorithm Example in C

```c
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min

Index = v;

    return minIndex;
}

void printSolution(int dist[]) {
    printf("Vertex \tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist);
}

int main() {
    int graph[V][V] = {
        {0, 10, 20, 0, 0},
        {10, 0, 30, 50, 10},
        {20, 30, 0, 20, 0},
        {0, 50, 20, 0, 60},
        {0, 10, 0, 60, 0},
    };

    dijkstra(graph, 0);

    return 0;
}
```

---

# Cycle Detection in Graphs

**Cycle Detection** is a fundamental problem in graph theory. A cycle is a path of edges and vertices wherein a vertex is reachable from itself. Cycle detection is crucial in various algorithms, such as detecting deadlocks in operating systems.

### Cycle Detection in Directed Graphs using DFS

For a directed graph, cycle detection can be implemented using Depth-First Search (DFS). The idea is to visit each vertex and check if there is a back edge (an edge that connects a vertex to an ancestor in the DFS tree).

```c
#include <stdio.h>
#include <stdbool.h>

#define V 4

bool DFS(int v, bool visited[], bool *recStack, int graph[V][V]) {
    if (visited[v] == false) {
        visited[v] = true;
        recStack[v] = true;

        for (int i = 0; i < V; i++) {
            if (graph[v][i]) {
                if (!visited[i] && DFS(i, visited, recStack, graph))
                    return true;
                else if (recStack[i])
                    return true;
            }
        }
    }
    recStack[v] = false;
    return false;
}

bool isCyclic(int graph[V][V]) {
    bool visited[V];
    bool recStack[V];

    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < V; i++)
        if (DFS(i, visited, recStack, graph))
            return true;

    return false;
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0}
    };

    if (isCyclic(graph))
        printf("Graph contains cycle\n");
    else
        printf("Graph doesn't contain cycle\n");

    return 0;
}
```

### Cycle Detection in Undirected Graphs using Union-Find

For an undirected graph, we can use the Union-Find algorithm to detect cycles. The idea is to keep track of the subsets of the vertices and ensure that no two vertices that are already connected are connected again by another edge.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int src, dest;
} Edge;

typedef struct Graph {
    int V, E;
    Edge* edge;
} Graph;

typedef struct Subset {
    int parent, rank;
} Subset;

Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (Edge*)malloc(graph->E * sizeof(Edge));
    return graph;
}

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

int isCycle(Graph* graph) {
    int V = graph->V;
    Subset* subsets = (Subset*)malloc(V * sizeof(Subset));

    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    for (int e = 0; e < graph->E; ++e) {
        int x = find(subsets, graph->edge[e].src);
        int y = find(subsets, graph->edge[e].dest);

        if (x == y)
            return 1;

        Union(subsets, x, y);
    }

    return 0;
}

int main() {
    int V = 3, E = 3;
    Graph* graph = createGraph(V, E);

    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;

    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;

    if (isCycle(graph))
        printf("Graph contains cycle\n");
    else
        printf("Graph doesn't contain cycle\n");

    return 0;
}
```

---

