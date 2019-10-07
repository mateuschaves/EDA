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
void push(List *list, dataNode data);

int main()
{
    List *lista = createList();

    dataNode data;
    data.id = 5;

    push(lista, data);

    printf("%d", lista->head->data.id);
}

List *createList()
{
    List *list = (List *)malloc(sizeof(List));

    list->size = 0;
    list->head = NULL;

    return list;
}

void push(List *list, dataNode data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = list->head;
    list->head = node;
    list->size++;
}