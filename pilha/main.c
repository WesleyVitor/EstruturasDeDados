#include <stdio.h>
#include <stdlib.h>

typedef struct NO No;
typedef struct PILHA Pilha;

struct NO{
  int value;
  No *prox;
};

struct PILHA{
  No *topo;
};

void inicializarPilha(Pilha *p){
  p->topo = NULL;
}

void empilhar(int valor, Pilha *p){
  No *novo = (No*) malloc(sizeof(No));
  
  if(novo==NULL){
    printf("Erro de alocação.\n");
    return;
  }
  novo->value = valor;
  //Adiciona um novo elemento que tem como próximo o atual topo da pilha.
  //Assim, podemos dizer que foi adicionado ao topo da pilha.
  novo->prox = p->topo;
  //Atualiza a referencia ao topo da pilha.
  p->topo = novo;

}

int desempilhar(Pilha *p){
  No *ptr = p->topo;
  int dado;
  if(ptr == NULL){
    printf("Pilha vazia!\n");
    exit(1);
  }
  //A referência ao topo "desce" 1 afim de retirar o atual elemento do topo da pilha.
  p->topo = ptr->prox;
  //Retira qualquer relação com os outros elementos da pilha.
  ptr->prox = NULL;

  dado = ptr->value;
  
  //Desaloca a memória do elemento da pilha.
  free(ptr);
  return dado;
}

void imprimirPilha(Pilha *p){
  No *ptr = p->topo;
  if(ptr==NULL){
    printf("Pilha vazia!\n");
    return;
  }
  while(ptr!=NULL){
    printf("%d\t",ptr->value);
    ptr = ptr->prox;
  }
  printf("\n");
}

void liberaEspaco(Pilha *p){
  No *ptr = p->topo;
  No *ant;

  while(ptr!=NULL){
    ant = ptr;
    ptr = ant->prox;
    free(ant);
  }
}


int main(){ 
  Pilha *p1 = (Pilha*) malloc(sizeof(Pilha));
  if(p1==NULL){
    printf("Erro de alocação.\n");
    exit(1);
  }

  inicializarPilha(p1);

  empilhar(10,p1);
  empilhar(20,p1);
  empilhar(30,p1);

  imprimirPilha(p1);

  desempilhar(p1);

  imprimirPilha(p1);

  liberaEspaco(p1);

  return 0;
}
