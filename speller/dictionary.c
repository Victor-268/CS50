#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> // Include this header for strcasecmp

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = 1000; // Increase the number of buckets for better distribution

// Hash table
node *table[N];

// Counter for number of words in dictionary
unsigned int word_count = 0;

// Improved hash function
unsigned int hash(const char *word)
{
    unsigned long hash = 0;
    int c;

    while ((c = tolower(*word++))) // Convert character to lowercase
    {
        hash = (hash << 2) ^ c;
    }

    return hash % N;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash the word to obtain the hash value
    unsigned int index = hash(word);

    // Search the hash table at the location specified by the word’s hash value
    node *cursor = table[index];
    while (cursor != NULL)
    {
        // Compare the word case-insensitively using strcasecmp
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    // Return false if no word is found
    return false;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }

    // Buffer to store each word
    char word[LENGTH + 1];

    // Read each word in the file
    while (fscanf(source, "%s", word) != EOF)
    {
        // Create a new node
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            // Free any previously allocated nodes
            unload();
            fclose(source);
            return false;
        }

        // Copy the word into the node
        strcpy(new_node->word, word);

        // Hash the word to get the index
        unsigned int index = hash(word);

        // Insert the node into the hash table at the correct index
        new_node->next = table[index];
        table[index] = new_node;

        // Increment the word count
        word_count++;
    }

    // Close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        table[i] = NULL; // Ensure the bucket is set to NULL after freeing
    }
    return true;
}
