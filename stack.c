#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct element *Stack;

typedef struct element
{
    int data;
    struct element *next;
} element;

typedef struct element Node;

Stack *createStack();
void freeStack(Stack *pi);
int isEmpty(Stack *pi);
int push(Stack *pi, int data);
int unstack(Stack *pi);
void printStack(Stack *pi);

int main()
{
    Stack *stack = createStack();
    printStack(stack);
    if (isEmpty(stack))
    {
        printf("Vazia\n");
    }
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    printStack(stack);
    printf("\n");
    unstack(stack);
    printStack(stack);
    freeStack(stack);
    printStack(stack);
}

Stack *createStack()
{
    Stack *pi = (Stack *)malloc(sizeof(Stack));
    if (pi != NULL)
        *pi = NULL;
    return pi;
}

void freeStack(Stack *pi)
{
    if (pi != NULL)
    {
        Node *node;
        while ((*pi) != NULL)
        {
            node = *pi;
            *pi = (*pi)->next;
            free(node);
        }
        free(*pi);
    }
}

int isEmpty(Stack *pi)
{
    if (*pi == NULL)
        return 1;
    else
        return 0;
}

int push(Stack *pi, int data)
{
    Node *node = (Node *)malloc(sizeof(Stack));
    node->data = data;
    node->next = *pi;
    *pi = node;
    return 1;
}

void printStack(Stack *pi)
{
    Node *node = (Node *)malloc(sizeof(Stack));
    node = *pi;
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int unstack(Stack *pi)
{
    if (isEmpty(pi))
        return 0;
    Node *node = (Node *)malloc(sizeof(Stack));
    node = *pi;
    *pi = (*pi)->next;
    free(node);
    return 1;
}
