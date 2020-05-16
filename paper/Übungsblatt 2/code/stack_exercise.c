#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Struktur, die Eintraege des Stacks kapselt.
 */
typedef struct StackNode
{
    // Zeiger auf den Command-String
    char *command;
    // Zeiger auf den naechsten Knoten des Stacks
    struct StackNode *next_node;
} StackNode;

/**
 * Erstellt einen neuen Knoten des Stacks und haengt ihn am Anfang an
 * Gibt den neuen Startknoten zurück.
 */
StackNode *newNode(char *command)
{
    // allokiere neuen Speicherplatz für den naechsten Knoten auf dem Heap
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->command = command;
    node->next_node = NULL;
    return node;
}

/**
 * Teste, ob Stack leer ist
 */
bool isEmpty(StackNode *root)
{
    // Falls root auf NULL zeigt, ist der Stack leer
    return !root;
}

/**
 * Fuege einen neuen Knoten dem Stack hinzu.
 */
void push(StackNode **pointer2root, char *command)
{
    StackNode *node = newNode(command);
    node->next_node = *pointer2root;
    *pointer2root = node;
}

/**
 * Gib den obersten Knoten zurueck und loesche diesen vom Stack (inklusive Speicherplatzfreigabe)
 */
bool pop(StackNode **pointer2root, char **pointer2command)
{
    if(isEmpty(*pointer2root)) return false;
    StackNode *root = *pointer2root;
    *pointer2command = ((*root).command);
    *pointer2root = ((*root).next_node);
    free(root);
    return true;
}

int main()
{
    StackNode *root = NULL;

    push(&root, "create: grades.txt");
    push(&root, "add: Max Mustermann 1.0");
    push(&root, "delete: grades.txt");

    char *command;
    while (pop(&root, &command))
    {
        printf("'%s' popped from stack \n", command);
    }

    printf("Stack is empty. Exit \n");

    return 0;
}
