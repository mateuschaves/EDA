#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node
{
    struct no *inicio;
    struct no *final;
} Fila;

typedef struct no
{
    int dado;
    struct no *proximo;
} T_FilaSimples;

Fila *criarFila();
int FilaVazia(Fila *Fila);
void enfileirar(Fila *fila, int data);
void desenfileirar(Fila *fila);
void printFila(Fila *fila);
int destruirFila(Fila *fila);

int main()
{
    Fila *fila = criarFila();

    enfileirar(fila, 2);
    enfileirar(fila, 3);
    destruirFila(fila);
    printFila(fila);
    printf("\n");
    desenfileirar(fila);
    desenfileirar(fila);
    printFila(fila);
}

int FilaVazia(Fila *fila)
{
    if (fila->inicio == NULL)
    {
        return 1; // True
    }
    return 0; // False
}

Fila *criarFila()
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));

    if (fila != NULL)
    {
        fila->inicio = NULL;
        fila->final = NULL;
    }

    return fila;
}

void enfileirar(Fila *fila, int data)
{
    T_FilaSimples *node = (T_FilaSimples *)malloc(sizeof(T_FilaSimples));

    node->dado = data;
    node->proximo = NULL;

    if (fila->inicio == NULL)
    {
        fila->inicio = node;
    }
    else
    {
        fila->final->proximo = node;
    }
    fila->final = node;
}

void desenfileirar(Fila *fila)
{
    T_FilaSimples *no = fila->inicio;
    fila->inicio = fila->inicio->proximo;
    if (fila->inicio == NULL)
        fila->final = NULL;
    free(no);
}

void printFila(Fila *fila)
{
    T_FilaSimples *no = fila->inicio;
    while (no != NULL)
    {
        printf("%d ", no->dado);
        no = no->proximo;
    }
}

int destruirFila(Fila *Fila)
{
    int quantidadeDeNos = 0;

    if (FilaVazia(Fila))
    {
        free(Fila);
        return quantidadeDeNos;
    }
    else
    {
        T_FilaSimples *no;
        while (Fila->inicio != NULL)
        {
            no = Fila->inicio;
            Fila->inicio = Fila->inicio->proximo;
            free(no);
            quantidadeDeNos++;
        }
        free(Fila);
    }
    return quantidadeDeNos;
}
