/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#include "dictionary.h"




/**
 * Returns a numeric value, a hash function, based on the current word
 */
unsigned int hash(const char *word)
{

    unsigned int hashed = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        hashed = (PRIME * hashed + tolower(word[i]))  % (HASH_SIZE -1);
    }
    return hashed;

}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    int index = 0;
    FILE* dp = fopen(dictionary, "r"); // Dictionnary Pointer ... stop thinking dirty!
    if (dp == NULL)
    {
        return false;
    }
    else
    {
        char word[LENGTH + 1];

        while(fscanf(dp, "%s", word) != EOF);
        {
            node_t *new_node = malloc(sizeof(node_t));
            if (new_node == NULL)
            {
                unload();
                return false;
            }
            else
            {
                strcpy(new_node->word, word);
                index = hash(new_node->word);

                if (hashTable[index] == NULL)
                {
                    hashTable[index] = new_node;
                }
                else
                {
                    new_node->next = hashTable[index]->next;
                    hashTable[index]->next = new_node;
                }

                printf("%s\n", hashTable[index]); // Test to make sure it gets printed
            }
            fclose(dp);
            return true;

        }

    }

    return false;

}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    //free()
    return false;
}
