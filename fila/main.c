#include <stdio.h>
#include <stdlib.h>

typedef struct NO NO;
typedef struct FILA FILA;

struct NO{
  int value;
  NO *prox;
};

struct FILA{
  NO *fim;
  NO *inicio;
};

void inicializarFila(FILA *f){
  f->fim = NULL;
  f->inicio = NULL;
}

void enfileirar(FILA *f, int value){
  NO *ptr = (NO*) malloc(sizeof(NO));
  if(ptr==NULL){
    printf("Erro de alocação!\n");
    exit(1);
  }

  ptr->value = value;
  ptr->prox = NULL;
  //Se for o primeiro elemento da fila, então inicio aponta para esse elemento.
  if(f->inicio == NULL){
    f->inicio = ptr;
  }else{
    //Se não for o primeiro elemento da fila, então o novo elemento vai entrar na 
    //fila pelo final. Assim, o final-> prox aponta para o novo elemento
    f->fim->prox = ptr;
  }
  // E depois o final é atualizado para o novo elemento entrando no final da fila.
  f->fim = ptr;

}

int desenfileirar(FILA *f){
  NO *ptr = f->inicio;
  int dado;
  if(ptr == NULL){
    printf("Lista Vazia!\n");
    exit(1);
  }
  f->inicio = ptr->prox;
  ptr->prox = NULL;
  dado = ptr->value;
  free(ptr);
  if(f->inicio==NULL){
    f->fim = NULL;
  }

  return dado;

}

void imprimirFila(FILA *f){
  NO *ptr = f->inicio;
  if(f->inicio==NULL){
    printf("Fila Vazia!\n");
    return;
  }

  while(ptr!=NULL){
    printf("%d\t",ptr->value);
    ptr = ptr->prox;
  }
  printf("\n");
}

void liberaEspaco(FILA *f){
  NO *ptr = f->inicio;
  NO *ant;

  while(ptr!=NULL){
    ant = ptr;
    ptr = ant->prox;
    free(ant);
  }
}

int main(){

  FILA *f1 = (FILA*) malloc(sizeof(FILA));

  inicializarFila(f1);
  enfileirar(f1,10);
  enfileirar(f1,20);
  enfileirar(f1,30);

  imprimirFila(f1);

  desenfileirar(f1);

  imprimirFila(f1);

  liberaEspaco(f1);

  return 0;
}
