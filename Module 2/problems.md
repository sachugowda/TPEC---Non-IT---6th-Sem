### Problem 1: Implement a Basic Hashmap

**Problem:**
Implement a simple hashmap that supports basic operations: insertion, search, and deletion. Use separate chaining to handle collisions.

**Explanation:**
You need to create a hashmap that can store key-value pairs and handle collisions by using linked lists.

**Solution:**

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

### Problem 2: Detecting Duplicates within a Dataset

**Problem:**
Given an array of integers, find if there are any duplicates.

**Explanation:**
Use a hashmap to keep track of the elements you have seen so far. If you encounter an element that is already in the hashmap, you have found a duplicate.

**Solution:**

```c
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

unsigned int hashFunction(int key) {
    return key % TABLE_SIZE;
}

int insert(Node* table[], int key) {
    unsigned int index = hashFunction(key);
    Node* temp = table[index];
    while (temp != NULL) {
        if (temp->key == key) {
            return 1; // Duplicate found
        }
        temp = temp->next;
    }
    Node* newNode = createNode(key);
    newNode->next = table[index];
    table[index] = newNode;
    return 0; // No duplicate
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    Node* hashTable[TABLE_SIZE] = {NULL};
    
    for (int i = 0; i < size; i++) {
        if (insert(hashTable, arr[i])) {
            printf("Duplicate found: %d\n", arr[i]);
            return 0;
        }
    }
    
    printf("No duplicates found\n");
    return 0;
}
```

### Problem 3: Finding the Most Frequent Element

**Problem:**
Given an array of integers, find the most frequent element.

**Explanation:**
Use a hashmap to count the frequency of each element. Then, iterate through the hashmap to find the element with the highest frequency.

**Solution:**

```c
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100

typedef struct Node {
    int key;
    int count;
    struct Node* next;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = NULL;
    return newNode;
}

unsigned int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(Node* table[], int key) {
    unsigned int index = hashFunction(key);
    Node* temp = table[index];
    while (temp != NULL) {
        if (temp->key == key) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }
    Node* newNode = createNode(key);
    newNode->next = table[index];
    table[index] = newNode;
}

int findMostFrequent(Node* table[]) {
    int maxCount = 0;
    int mostFrequent = -1;
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* temp = table[i];
        while (temp != NULL) {
            if (temp->count > maxCount) {
                maxCount = temp->count;
                mostFrequent = temp->key;
            }
            temp = temp->next;
        }
    }
    return mostFrequent;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 2, 3, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    Node* hashTable[TABLE_SIZE] = {NULL};
    
    for (int i = 0; i < size; i++) {
        insert(hashTable, arr[i]);
    }
    
    int mostFrequent = findMostFrequent(hashTable);
    printf("Most frequent element: %d\n", mostFrequent);
    
    return 0;
}
```

### Problem 4: Anagram Checking

**Problem:**
Given two strings, check if they are anagrams of each other.

**Explanation:**
Use a hashmap to count the frequency of each character in the first string. Then, decrement the count for each character in the second string. If all counts return to zero, the strings are anagrams.

**Solution:**

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 256

typedef struct Node {
    char key;
    int count;
    struct Node* next;
} Node;

Node* createNode(char key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = NULL;
    return newNode;
}

unsigned int hashFunction(char key) {
    return (unsigned char)key % TABLE_SIZE;
}

void insert(Node* table[], char key) {
    unsigned int index = hashFunction(key);
    Node* temp = table[index];
    while (temp != NULL) {
        if (temp->key == key) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }
    Node* newNode = createNode(key);
    newNode->next = table[index];
    table[index] = newNode;
}

bool searchAndDecrement(Node* table[], char key) {
    unsigned int index = hashFunction(key);
    Node* temp = table[index];
    while (temp != NULL) {
        if (temp->key == key) {
            temp->count--;
            if (temp->count == 0) {
                Node* toDelete = temp;
                temp = temp->next;
                free(toDelete);
                return true;
            }
            return true;
        }
        temp =

 temp->next;
    }
    return false;
}

bool areAnagrams(char* str1, char* str2) {
    if (strlen(str1) != strlen(str2)) return false;

    Node* hashTable[TABLE_SIZE] = {NULL};

    for (int i = 0; str1[i] != '\0'; i++) {
        insert(hashTable, str1[i]);
    }
    
    for (int i = 0; str2[i] != '\0'; i++) {
        if (!searchAndDecrement(hashTable, str2[i])) {
            return false;
        }
    }
    
    return true;
}

int main() {
    char str1[] = "listen";
    char str2[] = "silent";

    if (areAnagrams(str1, str2)) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are not anagrams.\n");
    }
    
    return 0;
}
```

### Problem 5: Implementing a Cache using Hashmap

**Problem:**
Implement a simple cache using a hashmap and doubly linked list that supports the `get` and `put` operations. When the cache reaches its capacity, it should remove the least recently used item.

**Explanation:**
Use a hashmap to store key-node pairs for O(1) access. Use a doubly linked list to maintain the order of usage, with the most recently used items at the front and least recently used items at the back.

**Solution:**

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    Node* table[TABLE_SIZE];
    int capacity;
    int size;
} LRUCache;

unsigned int hashFunction(int key) {
    return key % TABLE_SIZE;
}

Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

LRUCache* createCache(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->head = NULL;
    cache->tail = NULL;
    cache->capacity = capacity;
    cache->size = 0;
    memset(cache->table, 0, sizeof(cache->table));
    return cache;
}

void removeNode(LRUCache* cache, Node* node) {
    if (node->prev) {
        node->prev->next = node->next;
    } else {
        cache->head = node->next;
    }
    if (node->next) {
        node->next->prev = node->prev;
    } else {
        cache->tail = node->prev;
    }
}

void insertAtHead(LRUCache* cache, Node* node) {
    node->next = cache->head;
    node->prev = NULL;
    if (cache->head) {
        cache->head->prev = node;
    }
    cache->head = node;
    if (!cache->tail) {
        cache->tail = node;
    }
}

void moveToHead(LRUCache* cache, Node* node) {
    removeNode(cache, node);
    insertAtHead(cache, node);
}

void put(LRUCache* cache, int key, int value) {
    unsigned int index = hashFunction(key);
    Node* node = cache->table[index];
    while (node) {
        if (node->key == key) {
            node->value = value;
            moveToHead(cache, node);
            return;
        }
        node = node->next;
    }
    
    if (cache->size == cache->capacity) {
        unsigned int tailIndex = hashFunction(cache->tail->key);
        Node* temp = cache->table[tailIndex];
        if (temp == cache->tail) {
            cache->table[tailIndex] = temp->next;
        } else {
            while (temp->next != cache->tail) {
                temp = temp->next;
            }
            temp->next = NULL;
        }
        removeNode(cache, cache->tail);
        free(cache->tail);
        cache->size--;
    }
    
    Node* newNode = createNode(key, value);
    insertAtHead(cache, newNode);
    newNode->next = cache->table[index];
    cache->table[index] = newNode;
    cache->size++;
}

int get(LRUCache* cache, int key) {
    unsigned int index = hashFunction(key);
    Node* node = cache->table[index];
    while (node) {
        if (node->key == key) {
            moveToHead(cache, node);
            return node->value;
        }
        node = node->next;
    }
    return -1; // Key not found
}

int main() {
    LRUCache* cache = createCache(2);
    put(cache, 1, 1);
    put(cache, 2, 2);
    printf("Get 1: %d\n", get(cache, 1));
    put(cache, 3, 3);
    printf("Get 2: %d\n", get(cache, 2)); // should return -1 (not found)
    put(cache, 4, 4);
    printf("Get 1: %d\n", get(cache, 1)); // should return -1 (not found)
    printf("Get 3: %d\n", get(cache, 3));
    printf("Get 4: %d\n", get(cache, 4));
    return 0;
}
```

### Explanation:

- **Hash Function:** Computes an index for the key to locate the bucket.
- **Node Structure:** Represents a single element in the cache.
- **LRUCache Structure:** Maintains the hashmap (table), doubly linked list (head, tail), capacity, and size.
- **Remove Node:** Removes a node from the linked list.
- **Insert at Head:** Inserts a node at the beginning of the linked list.
- **Move to Head:** Moves an existing node to the beginning of the list.
- **Put:** Inserts or updates a key-value pair in the cache, evicting the least recently used item if the cache is full.
- **Get:** Retrieves a value by key and moves the accessed node to the head of the list.

These problems and solutions should help you understand the various ways hashmaps can be used and implemented in C.
