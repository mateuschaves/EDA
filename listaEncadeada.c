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
void printList(List *list);

int main()
{
    List *lista = createList();

    push(lista, 5);
    push(lista, 2);
    push(lista, 3);
    push(lista, 1);
    printList(lista);
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
    node->before = NULL;
    if (list->head != NULL)
        list->head->before = node;
    list->head = node;
    list->size++;
}

void printList(List *list)
{
    Node *pointer = list->head;
    while (pointer != NULL)
    {
        printf("%d -", pointer->data);
        if (pointer->next != NULL)
        {
            pointer = pointer->next;
        }
        else
        {
            break;
        }
    }
    printf("\n");
    while (1)
    {
        if (pointer == list->head)
        {
            printf("%d -", pointer->data);
            break;
        }
        printf("%d -", pointer->data);
        pointer = pointer->before;
    }
}