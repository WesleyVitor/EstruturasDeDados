#include <stdio.h>
#include <stdlib.h>

typedef struct NO NO;

struct NO{
  int value;
  NO *prox;
};

void inicializaLista(NO *l){
  l = NULL;
}

NO* adicionar(NO *l, int value){
  NO *ptr = (NO*) malloc(sizeof(NO));
  if(ptr==NULL){
    printf("Erro de alocação.\n");
    exit(1);
  }
  
  ptr->value = value;
  ptr->prox = l;
  return ptr;
}

int retirar(NO *l, int value){
  NO *ptr = l;
  NO *ant;
  int dado;
  if(ptr==NULL){
    printf("Lista Vazia!\n");
    exit(1);
  }
  while(ptr!=NULL && ptr->value != value){
    ant = ptr;
    ptr = ptr->prox;
  }

  //Verifica se ele chegou no último e não encontrou o elemento.
  if(ptr==NULL){
    printf("Elemento não encontrado!\n");
    exit(1);
  }


  if (ant == NULL){
		l = ptr->prox;
  }
	else{
    //Pula o elemento que quero retirar.
		ant->prox = ptr->prox;
}
  free(ptr);
  return dado;
}

void imprimirLista(NO *l){
  NO *ptr = l;
  if(ptr==NULL){
    printf("Pilha vazia!\n");
    exit(1);
  }
  while(ptr!=NULL){
    printf("%d\t",ptr->value);
    ptr = ptr->prox;
  }
  printf("\n");
}

void liberaEspaco(NO *l){
  NO *ptr = l;
  NO *ant;

  while(ptr!=NULL){
    ant = ptr;
    ptr = ant->prox;
    free(ant);
  }
}

int main(){

  NO *l1 = (NO*) malloc(sizeof(NO));
  
  inicializaLista(l1);

  l1 = adicionar(l1, 10);
  l1 = adicionar(l1, 20);
  l1 = adicionar(l1, 30);

  imprimirLista(l1);

  retirar(l1, 20);

  imprimirLista(l1);

  liberaEspaco(l1);


  return 0;
}