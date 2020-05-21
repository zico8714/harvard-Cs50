// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"
#include <ctype.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 444;

// Hash table
node *table[N];

int count = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int H = hash(word);
    node *tmp = table[H];

    while (tmp != NULL)
    {
        if ((strcasecmp(tmp->word, word) == 0))
        {
            return true;
        }
        else
        {
            tmp = tmp->next;
        }
    }
    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        if (word[i] != '\0')
            sum += tolower(word[i]);
        else
            break;
    }

    if (sum > N)
        return sum % N;
    else
        return sum;
}


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    char word2[LENGTH + 1];
    FILE *fDic = fopen(dictionary, "r");
    if (fDic == NULL)
    {
        printf("no se pudo abrir el archivo %s.\n", dictionary);
        return false;
    }

    while (fscanf(fDic, "%s", word2) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            unload();
            printf("Error en loop malloc.\n");
            return false;
        }

        count++;
        strcpy(n->word, word2);
        n->next = NULL;

        int H = hash(n->word);

        if (table[H] == NULL)
        {
            table[H] = n;
        }
        else
        {
            n->next = table[H];
            table[H] = n;
        }
    }
    fclose(fDic);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        if (table[i] == NULL)
        {
            continue;
        }
        else
        {
            node *curs = table[i];
            while (curs != NULL)
            {
                node *tmp = curs;
                curs = curs->next;
                free(tmp);
            }
            table[i] = NULL;
            free(curs);
        }
    }
    return true;
}
