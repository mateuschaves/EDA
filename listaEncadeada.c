#include <stdio.h>
#include <stdio.h>
#include <malloc.h>

typedef struct dataNode
{
    int id;
} dataNode;

typedef struct node
{
    dataNode data;
    struct node *next;

} Node;

typedef struct list
{
    int size;
    Node *head;
} List;

List *createList();

int main()
{
    List *lista = createList();

    dataNode data;
    data.id = 5;

    printf("%d", lista->size);
}

List *createList()
{
    List *list = (List *)malloc(sizeof(List));

    list->size = 0;
    list->head = NULL;

    return list;
}