# Hashmaps

## What is a Hashmap?

A hashmap (or hash table) is a data structure that provides a very efficient way of storing and retrieving data based on key-value pairs. It uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found.

Hashmaps are widely used due to their average-case constant time complexity for insertions, deletions, and lookups.

## How Hashmaps Work

1. **Hash Function:** A function that converts a given key into an index in the array.
2. **Buckets:** An array where each position (or bucket) holds a list of key-value pairs.
3. **Collision Handling:** Since multiple keys can hash to the same index, collisions are handled using methods like chaining (linked lists) or open addressing.

## Example Program in C

Here's a simple implementation of a hashmap in C using separate chaining for collision handling:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Node {
    char* key;
    int value;
    struct Node* next;
} Node;

Node* createNode(char* key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

unsigned int hashFunction(char* key) {
    unsigned long int hashValue = 0;
    int i = 0;
    while (hashValue < ULONG_MAX && i < strlen(key)) {
        hashValue = hashValue << 8;
        hashValue += key[i];
        i++;
    }
    return hashValue % TABLE_SIZE;
}

void insert(Node* table[], char* key, int value) {
    unsigned int index = hashFunction(key);
    Node* newNode = createNode(key, value);
    if (table[index] == NULL) {
        table[index] = newNode;
    } else {
        Node* temp = table[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int search(Node* table[], char* key) {
    unsigned int index = hashFunction(key);
    Node* temp = table[index];
    while (temp != NULL) {
        if (strcmp(temp->key, key) == 0) {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;  // Key not found
}

void delete(Node* table[], char* key) {
    unsigned int index = hashFunction(key);
    Node* temp = table[index];
    Node* prev = NULL;
    while (temp != NULL && strcmp(temp->key, key) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        // Key not found
        return;
    }
    if (prev == NULL) {
        table[index] = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp->key);
    free(temp);
}

void printTable(Node* table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* temp = table[i];
        printf("Index %d: ", i);
        while (temp != NULL) {
            printf("(%s, %d) -> ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Node* hashTable[TABLE_SIZE] = {NULL};

    insert(hashTable, "apple", 1);
    insert(hashTable, "banana", 2);
    insert(hashTable, "orange", 3);
    insert(hashTable, "grape", 4);
    insert(hashTable, "cherry", 5);

    printTable(hashTable);

    printf("Search for 'apple': %d\n", search(hashTable, "apple"));
    printf("Search for 'banana': %d\n", search(hashTable, "banana"));

    delete(hashTable, "banana");
    printTable(hashTable);

    return 0;
}
```

## Relevant YouTube Videos

1. [Hash Table Data Structure](https://www.youtube.com/watch?v=2Ti5yvumFTU)
2. [Hash Tables and Hash Functions](https://www.youtube.com/watch?v=shs0KM3wKv8)
3. [Collision Handling in Hash Tables](https://www.youtube.com/watch?v=0M_kIqhwbFo)

These resources should help you get a deeper understanding of hashmaps and their implementation in C. Happy coding!

---

## Detailed Explanation

### Hash Function

A hash function takes an input (or key) and returns an index in the array. This index is where the value associated with the key will be stored. A good hash function distributes keys uniformly across the array to minimize collisions. In our example, the `hashFunction` converts a string key into an index by accumulating the ASCII values of its characters and taking the modulus with the table size.

### Collision Handling

Collisions occur when two keys hash to the same index. There are several methods to handle collisions:
- **Chaining:** Each array element points to a linked list of entries that hash to the same index. This is the method used in our example.
- **Open Addressing:** All elements are stored in the array itself. When a collision occurs, the algorithm searches for the next empty slot in the array (e.g., linear probing, quadratic probing).

### Insert Operation

The `insert` function adds a new key-value pair to the hashmap. It first computes the index using the hash function. If the bucket at the computed index is empty, it inserts the new node. If the bucket already contains nodes, it traverses the linked list and appends the new node at the end.

### Delete Operation

The `delete` function removes a key-value pair from the hashmap. It computes the index using the hash function, then searches for the key in the linked list at that index. If the key is found, it adjusts the pointers to exclude the node from the list and frees the memory.
