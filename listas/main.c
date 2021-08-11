
#include <stdio.h>
#include "lista.h"


int main(){

  List *A;
  A = NULL;
  A = insert(A, 30);
  A = insert(A,40);
  A = insert(A,50);
  A = insert(A,60);
  A = insert(A,70);
  mostrar(A);


  retirar(A, 40);
  mostrar(A);


  printf("%d\n",minimo(A)->value);
  
  libera(A);
  return 0;
}

List* insert(List *A,int v){
  List *novo = (List*) malloc(sizeof(List));
  novo->value = v;
  novo->next = A;
  return novo;
}

void libera(List *A){
  List *p = A;
  while(p!=NULL){
    List *t = p->next;
    free(p);
    p = t;
  }
}

void mostrar(List *A){
  List *p;
  for(p=A;p!=NULL;p = p->next ){
    printf("%d\t",p->value);
  }
  printf("\n");
}

int retirar(List *A, int v){
  if(A==NULL) return 1;
  List *ant;
  List *no = A;

  //Percorre os elementos
  while(no != NULL && no->value != v){
    ant = no;
    no = no->next;
  }

  if(no==NULL)return 1;
  if(no==A) {

    //Pula o elemento
    // A -> no -> NULL, agora...
    // A -> NULL;
    A = no->next;
  }else{

    //Pula o elemento: 
    // ant -> no -> prox, agora...
    // ant -> prox
    ant->next = no->next;
  }


  free(no);
  return 0;
}


List* minimo(List *A){
  List *no = A;
  List *menor =A;
  while(no!=NULL){
    if(no->value < menor->value){
      menor = no;
    }

    no = no->next;
  }

  return menor;
}
