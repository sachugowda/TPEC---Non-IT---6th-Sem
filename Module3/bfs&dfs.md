
## Graph Traversal

Graph traversal refers to the process of visiting all the nodes in a graph in a specific manner. The two most common graph traversal techniques are:

### Depth-First Search (DFS)
DFS explores as far as possible along each branch before backtracking.

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 5

void DFS(int vertex, bool visited[], int adjMatrix[MAX_VERTICES][MAX_VERTICES], int vertices) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < vertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(i, visited, adjMatrix, vertices);
        }
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

    bool visited[MAX_VERTICES] = {false};

    printf("Depth-First Search starting from vertex 0:\n");
    DFS(0, visited, adjMatrix, vertices);

    return 0;
}
```

### Breadth-First Search (BFS)
BFS explores all the vertices at the present depth level before moving on to the nodes at the next depth level.

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 5

void BFS(int startVertex, int adjMatrix[MAX_VERTICES][MAX_VERTICES], int vertices) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    while (front != rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
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

    printf("Breadth-First Search starting from vertex 0:\n");
    BFS(0, adjMatrix, vertices);

    return 0;
}
```

### BFS and DFS Video Tutorial

For a visual explanation of Breadth-First Search (BFS) and Depth-First Search (DFS), you can watch this [YouTube video](https://www.youtube.com/watch?v=pcKY4hjDrxk).

