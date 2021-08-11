#include <stdlib.h>
#include <stdio.h>

typedef struct list List;
List* insert(List*, int);
void mostrar(List *A);
void libera(List *A);
int retirar(List *A, int v);
List* minimo(List *A);
struct list{
  int value;
  struct list *next;
};