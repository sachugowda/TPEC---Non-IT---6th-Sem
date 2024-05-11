
# Implementing a Priority Queue using a Linked List in C

This tutorial provides a detailed guide on how to implement a priority queue using a linked list in C. In this implementation, the element with the lowest value has the highest priority, and we ensure that the list remains sorted at all times.

## Structure Definition

Define the node structure for the linked list, which includes the data and a pointer to the next node.

```c
typedef struct Node {
    int data;
    struct Node* next;
} Node;
```

## Initialization Function

Initialize the head pointer to `NULL` as the queue starts empty.

```c
Node* initializeQueue() {
    return NULL;
}
```

## Enqueue Function

The enqueue function inserts a new element in a sorted order based on its priority. It ensures that the linked list remains sorted so that dequeue operations are efficient.

```c
void enqueue(Node** head, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Unable to allocate memory for new node\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    // Insert in a sorted order
    if (*head == NULL || (*head)->data > value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}
```

## Dequeue Function

Remove and return the element with the highest priority (the head of the list), as it is the minimum element in our sorted list.

```c
int dequeue(Node** head) {
    if (*head == NULL) {
        printf("Priority Queue is empty\n");
        return -1; // Return -1 to indicate the queue is empty
    }
    Node* temp = *head;
    int result = temp->data;
    *head = temp->next;
    free(temp);
    return result;
}
```

## Print Function

Print all the elements in the priority queue.

```c
void printQueue(Node* head) {
    if (head == NULL) {
        printf("Priority Queue is empty\n");
        return;
    }
    Node* temp = head;
    printf("Priority Queue elements:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
```

## Main Function

Demonstrate the operations of the priority queue.

```c
int main() {
    Node* pq = initializeQueue();

    enqueue(&pq, 10);
    enqueue(&pq, 5);
    enqueue(&pq, 20);
    enqueue(&pq, 1);

    printQueue(pq);

    int val = dequeue(&pq);
    printf("Dequeued value: %d\n", val);

    printQueue(pq);

    return 0;
}
```

## Conclusion

This tutorial has covered the basic operations required to implement a sorted priority queue using a singly linked list in C. The queue automatically keeps the lowest numbers (highest priority) at the front for efficient removal. This structure is especially useful when you need a dynamic system that frequently changes its size.
```
