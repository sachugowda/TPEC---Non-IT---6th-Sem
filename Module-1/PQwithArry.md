
# Implementing a Priority Queue using an Array in C

This tutorial provides a step-by-step guide on how to implement a priority queue using an array in C. The priority queue will manage elements such that the element with the lowest value has the highest priority.

## Structure Definition

First, define the structure of the priority queue. It includes an array to store the queue elements and an integer to track the last element's index.

```c
#define SIZE 100  // Maximum number of elements in the Priority Queue

typedef struct {
    int items[SIZE];
    int rear; // Index to the last element in the queue
} PriorityQueue;
```

## Initialization Function

Initialize the priority queue to set the `rear` index to -1, indicating that the queue is empty.

```c
void initializeQueue(PriorityQueue *pq) {
    pq->rear = -1;
}


## Enqueue Function

The enqueue function adds a new element at the end of the queue.

```c
void enqueue(PriorityQueue *pq, int value) {
    if (pq->rear == SIZE - 1) {
        printf("Priority Queue is full\n");
        return;
    }
    pq->items[++pq->rear] = value;
}
```

## Finding the Highest Priority Element

Find the index of the highest priority element, which is the minimum value in this implementation.

```c
int getHighestPriorityIndex(PriorityQueue *pq) {
    int minIndex = 0;
    for (int i = 1; i <= pq->rear; i++) {
        if (pq->items[i] < pq->items[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}
```

## Dequeue Function

Remove the highest priority element from the queue. This function finds the minimum element, swaps it with the last element, and then removes the last element.

```c
int dequeue(PriorityQueue *pq) {
    if (pq->rear == -1) {
        printf("Priority Queue is empty\n");
        return INT_MAX; // Return INT_MAX to indicate the queue is empty
    }

    int minIndex = getHighestPriorityIndex(pq);
    int minVal = pq->items[minIndex];

    // Move the last item to the position of the minIndex
    pq->items[minIndex] = pq->items[pq->rear];
    pq->rear--; // Reduce the size of the queue

    return minVal;
}
```

## Print Function

This function prints all the elements of the queue.

```c
void printQueue(PriorityQueue *pq) {
    if (pq->rear == -1) {
        printf("Priority Queue is empty\n");
        return;
    }
    printf("Priority Queue elements:\n");
    for (int i = 0; i <= pq->rear; i++) {
        printf("%d ", pq->items[i]);
    }
    printf("\n");
}
```

## Main Function

The `main` function demonstrates how to use the priority queue.

```c
int main() {
    PriorityQueue pq;
    initializeQueue(&pq);

    enqueue(&pq, 10);
    enqueue(&pq, 5);
    enqueue(&pq, 20);
    enqueue(&pq, 1);

    printQueue(&pq);

    int val = dequeue(&pq);
    printf("Dequeued value: %d\n", val);

    printQueue(&pq);

    return 0;
}
```

This tutorial covers the basic operations of a priority queue using arrays in C. It includes functions for initializing the queue, adding elements, removing the highest priority element, and printing the queue contents.
```
