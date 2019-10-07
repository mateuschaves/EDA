#include <stdio.h>
#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node *next, *before;
} Node;

typedef struct list
{
    int size;
    Node *head;
} List;

List *createList();
void push(List *list, int data);

int main()
{
    List *lista = createList();

    push(lista, 5);

    printf("%d", lista->head->data);
}

List *createList()
{
    List *list = (List *)malloc(sizeof(List));

    list->size = 0;
    list->head = NULL;

    return list;
}

void push(List *list, int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = list->head;
    list->head = node;
    list->size++;
}