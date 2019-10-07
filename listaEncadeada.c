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
int isEmptyList(List *list);

int main()
{
    List *lista = createList();

    push(lista, 2);
    push(lista, 1);
    push(lista, 0);
    push(lista, 4);
    printList(lista);
    if (isEmptyList(lista))
    {
        printf("Lista vazia");
    }
    else
    {
        printf("Lista com elementos");
    }
    return 0;
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
    if (isEmptyList(list))
    {
        node->next = list->head;
        node->before = NULL;
        if (list->head != NULL)
            list->head->before = node;
        list->head = node;
        list->size++;
    }
    else
    {
        Node *before, *current = list->head;
        while (current != NULL && current->data < data)
        {
            before = current;
            current = current->next;
        }
        if (current == list->head)
        {
            node->next = list->head;
            node->before = NULL;
            if (list->head != NULL)
                list->head->before = node;
            list->head = node;
            list->size++;
        }
        else
        {
            node->next = before->next;
            node->before = before;
            before->next = node;
            if (current != NULL)
                current->before = node;
        }
    }
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

int isEmptyList(List *list)
{
    if (list->head == NULL)
        return 1;
    else
        return 0;
}