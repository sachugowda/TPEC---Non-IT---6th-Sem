
# Implementing a Priority Queue using a Binary Heap in C

This tutorial demonstrates how to implement a priority queue using a binary heap in C, where the element with the highest value has the highest priority.

## Structure Definition

Define the structure for the binary heap:

```c
#define MAX_SIZE 100  // Maximum number of elements in the Heap

typedef struct {
    int data[MAX_SIZE];
    int size;
} MaxHeap;
```

## Initialization Function

Initialize the heap with size 0, indicating it's empty.

```c
void initializeHeap(MaxHeap *heap) {
    heap->size = 0;
}
```

## Utility Functions for Heap Operations

### Swap Function

```c
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

### Get Parent Index

```c
int parent(int index) {
    return (index - 1) / 2;
}
```

### Get Left Child Index

```c
int leftChild(int index) {
    return (2 * index) + 1;
}
```

### Get Right Child Index

```c
int rightChild(int index) {
    return (2 * index) + 2;
}
```

## Insert Function

Inserts a new element into the heap, maintaining the max heap property.

```c
void insert(MaxHeap *heap, int element) {
    if (heap->size == MAX_SIZE) {
        printf("Heap is full\n");
        return;
    }

    // Place the element at the end of the heap
    heap->data[heap->size] = element;
    int current = heap->size;
    heap->size++;

    // Bubble up the new element to maintain the max heap property
    while (current != 0 && heap->data[current] > heap->data[parent(current)]) {
        swap(&heap->data[current], &heap->data[parent(current)]);
        current = parent(current);
    }
}
```

## ExtractMax Function

Removes and returns the element with maximum priority (the root of the heap).

```c
int extractMax(MaxHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap is empty\n");
        return -1;
    }

    int max = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    maxHeapify(heap, 0);

    return max;
}
```

### MaxHeapify Function

Helper function to maintain max heap property after deletion.

```c
void maxHeapify(MaxHeap *heap, int index) {
    int left = leftChild(index);
    int right = rightChild(index);
    int largest = index;

    if (left < heap->size && heap->data[left] > heap->data[largest]) {
        largest = left;
    }
    if (right < heap->size && heap->data[right] > heap->data[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(&heap->data[index], &heap->data[largest]);
        maxHeapify(heap, largest);
    }
}
```

## GetMax Function

Returns the element with the maximum priority without removing it.

```c
int getMax(MaxHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap is empty\n");
        return -1;
    }
    return heap->data[0];
}
```

## ChangePriority Function

Changes the priority of an element at a given index.

```c
void changePriority(MaxHeap *heap, int index, int priority) {
    if (index < 0 || index >= heap->size) {
        printf("Index is out of bounds\n");
        return;
    }

    int old = heap->data[index];
    heap->data[index] = priority;

    if (priority > old) {
        // If the new priority is greater, bubble up
        while (index != 0 && heap->data[index] > heap->data[parent(index)]) {
            swap(&heap->data[index], &heap->data[parent(index)]);
            index = parent(index);
        }
    } else {
        // If the new priority is lower, heapify down
        maxHeapify(heap, index);
    }
}
```

## Conclusion

This tutorial covers the essential operations required to implement a priority queue using a binary heap in C, including insertion, extraction, and priority adjustment. The priority queue built here uses a max heap, which ensures that the largest element is always at the root, allowing for efficient maximum retrieval and modification operations.
```
