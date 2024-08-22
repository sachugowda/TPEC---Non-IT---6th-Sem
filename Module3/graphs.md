
# Introduction to Graphs

A **Graph** is a data structure consisting of a set of nodes (or vertices) and a set of edges that connect pairs of nodes. Graphs are widely used in computer science to model and solve problems like network routing, social networking, and more.

### Key Types of Graphs:
- **Undirected Graph**: A graph where edges have no direction. The edge between node A and node B is the same as the edge between node B and node A.
- **Directed Graph (Digraph)**: A graph where edges have a direction. The edge from node A to node B is different from the edge from node B to node A.
- **Weighted Graph**: A graph where each edge has an associated weight, often representing cost, distance, or capacity.

---

## Graph Terminology

1. **Vertex (Node)**: A fundamental unit represented by a dot in the graph.
2. **Edge (Link)**: A connection between two vertices.
3. **Adjacent Vertices**: Two vertices that are connected by an edge.
4. **Degree of a Vertex**: The number of edges incident to a vertex.
5. **Path**: A sequence of edges that connect a sequence of vertices.
6. **Cycle**: A path that starts and ends at the same vertex.
7. **Connected Graph**: A graph where there's a path between any two vertices.
8. **Complete Graph**: A graph where there is an edge between every pair of vertices.

---

## Graph Implementation in C

Graphs can be represented in multiple ways. The two most common representations are:

1. **Adjacency Matrix**: A 2D array where each cell `(i, j)` indicates the presence or absence of an edge between vertices `i` and `j`.
2. **Adjacency List**: An array of lists where each list represents the set of neighbors of a vertex.

### Adjacency Matrix Representation

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

    // Example edges for an undirected graph
    adjMatrix[0][1] = 1;
    adjMatrix[1][0] = 1;

    adjMatrix[1][2] = 1;
    adjMatrix[2][1] = 1;

    adjMatrix[2][3] = 1;
    adjMatrix[3][2] = 1;

    adjMatrix[3][4] = 1;
    adjMatrix[4][3] = 1;

    adjMatrix[4][0] = 1;
    adjMatrix[0][4] = 1;

    printAdjacencyMatrix(adjMatrix, vertices);

    return 0;
}
```

### Adjacency List Representation

```c
#include <stdio.h>
#include <stdlib.h>

// A structure to represent an adjacency list node
typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

// A structure to represent an adjacency list
typedef struct AdjList {
    AdjListNode *head;
} AdjList;

// A structure to represent a graph
typedef struct Graph {
    int vertices;
    AdjList* array;
} Graph;

// Function to create a new adjacency list node
AdjListNode* createAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;

    // Create an array of adjacency lists. Size of array will be V
    graph->array = (AdjList*)malloc(vertices * sizeof(AdjList));

    // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < vertices; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest. A new node is added to the adjacency
    // list of src. The node is added at the beginning
    AdjListNode* newNode = createAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since graph is undirected, add an edge from dest to src also
    newNode = createAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to print the adjacency list representation of a graph
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->vertices; v++) {
        AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}
```
