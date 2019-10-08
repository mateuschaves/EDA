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
int push(List *list, int data);
void printList(List *list);
int isEmptyList(List *list);
int search(List *list, int data);
int deleteNode(List *list, int data);

int main()
{
    List *lista = createList();

    push(lista, 2);
    push(lista, 1);
    push(lista, 0);
    printList(lista);
    deleteNode(lista, 1);
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

int push(List *list, int data)
{
    if (search(list, data))
        return 0;
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
    return 1;
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
    printf("\n");
}

int isEmptyList(List *list)
{
    if (list->head == NULL)
        return 1;
    else
        return 0;
}

int search(List *list, int data)
{
    Node *pointer = list->head;
    while (pointer != NULL)
    {
        if (pointer->data == data)
            return 1;
        pointer = pointer->next;
    }
    return 0;
}

int deleteNode(List *list, int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node = list->head;
    while (node != NULL)
    {
        if (node->data == data)
        {
            if (node->before == NULL)
                list->head = node->next;
            else
                node->before->next = node->next;

            if (node->next != NULL)
                node->next->before = node->before;
            free(node);
            return 1;
        }
        node = node->next;
    }
}
