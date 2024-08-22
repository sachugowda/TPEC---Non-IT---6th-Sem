
# Introduction to Tries

A **Trie** (pronounced "try") is a tree-like data structure that stores a dynamic set of strings, where each node represents a common prefix shared by some of the strings. Tries are particularly useful for operations like prefix search, auto-completion, and even dictionary implementations.

### Key Operations in Tries:
1. **Insertion**: Adding a string to the Trie.
2. **Search**: Checking if a string is present in the Trie.
3. **Deletion**: Removing a string from the Trie.

For a detailed visual explanation of Tries, you can also refer to this [YouTube video](https://www.youtube.com/watch?v=zT5g3cPXJ08).

---

## Trie Node Class in C

To create a Trie, we first need to define the structure of a Trie node.

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Trie Node structure
#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

// Function to create a new Trie node
TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }

    return node;
}
```

---

## Inserting a Word into the Trie

Insertion involves traversing the Trie according to the characters of the word. If the path does not exist, new nodes are created.

```c
// Function to insert a word into the Trie
void insert(TrieNode *root, const char *word) {
    TrieNode *crawler = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (!crawler->children[index]) {
            crawler->children[index] = createNode();
        }

        crawler = crawler->children[index];
    }

    crawler->isEndOfWord = true;
}
```

---

## Searching for a Word in the Trie

To search for a word, we traverse the Trie following the word's characters. If we reach the end of the word and the node is marked as `isEndOfWord`, the word exists in the Trie.

```c
// Function to search for a word in the Trie
bool search(TrieNode *root, const char *word) {
    TrieNode *crawler = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (!crawler->children[index]) {
            return false;
        }

        crawler = crawler->children[index];
    }

    return (crawler != NULL && crawler->isEndOfWord);
}
```

---

## Deleting a Word from the Trie

Deleting a word from the Trie involves checking if the word exists, and if it does, removing the node. If a node is part of another word, we do not delete it.

```c
// Function to check if a node has children
bool hasChildren(TrieNode* node) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            return true;
        }
    }
    return false;
}

// Recursive function to delete a word from the Trie
bool deleteWord(TrieNode* root, const char* word, int depth) {
    if (!root) {
        return false;
    }

    // If the end of the word is reached
    if (depth == strlen(word)) {
        // Unmark the end of word
        if (root->isEndOfWord) {
            root->isEndOfWord = false;

            // If the node has no children, it can be deleted
            if (!hasChildren(root)) {
                free(root);
                return true;
            }

            return false;
        }
    }

    int index = word[depth] - 'a';
    if (deleteWord(root->children[index], word, depth + 1)) {
        // Delete the child node
        free(root->children[index]);
        root->children[index] = NULL;

        // Recursively climb up, and delete eligible nodes
        return !hasChildren(root) && !root->isEndOfWord;
    }

    return false;
}
```

---

## Types of Tries

### Standard Trie:
- Stores characters of words at each node. 
- Every path from the root to a leaf node represents a unique string.

### Compressed Trie (Radix Tree):
- Compresses long chains of single-child nodes.
- Reduces memory usage and improves performance for certain operations.

### Suffix Trie:
- A Trie containing all the suffixes of a given text.
- Useful in string matching problems.

---

## Huffman Coding Using Trie

Tries are also used in Huffman coding, where the Trie is constructed to represent the binary codes assigned to each character based on their frequency in the text.

---

## Example Program

Here's a complete program that demonstrates the insertion, search, and deletion operations on a Trie.

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }

    return node;
}

void insert(TrieNode *root, const char *word) {
    TrieNode *crawler = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (!crawler->children[index]) {
            crawler->children[index] = createNode();
        }

        crawler = crawler->children[index];
    }

    crawler->isEndOfWord = true;
}

bool search(TrieNode *root, const char *word) {
    TrieNode *crawler = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (!crawler->children[index]) {
            return false;
        }

        crawler = crawler->children[index];
    }

    return (crawler != NULL && crawler->isEndOfWord);
}

bool hasChildren(TrieNode* node) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i]) {
            return true;
        }
    }
    return false;
}

bool deleteWord(TrieNode* root, const char* word, int depth) {
    if (!root) {
        return false;
    }

    if (depth == strlen(word)) {
        if (root->isEndOfWord) {
            root->isEndOfWord = false;

            if (!hasChildren(root)) {
                free(root);
                return true;
            }

            return false;
        }
    }

    int index = word[depth] - 'a';
    if (deleteWord(root->children[index], word, depth + 1)) {
        free(root->children[index]);
        root->children[index] = NULL;

        return !hasChildren(root) && !root->isEndOfWord;
    }

    return false;
}

int main() {
    TrieNode *root = createNode();

    insert(root, "hello");
    insert(root, "world");

    printf("Search for 'hello': %s\n", search(root, "hello") ? "Found" : "Not Found");
    printf("Search for 'world': %s\n", search(root, "world") ? "Found" : "Not Found");

    deleteWord(root, "world", 0);
    printf("Search for 'world' after deletion: %s\n", search(root, "world") ? "Found" : "Not Found");

    return 0;
}
```

---

This concludes the basic introduction to Tries in C with examples of insertion, search, and deletion operations. For more details, watch this [YouTube video](https://www.youtube.com/watch?v=zT5g3cPXJ08). Tries are a powerful data structure, especially when dealing with large datasets of strings or implementing dictionary-like structures.

---
