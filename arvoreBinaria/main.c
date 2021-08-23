#include <stdio.h>
#include <stdlib.h>

typedef struct TEEN TEEN;
typedef struct NO NO;

struct NO{
  NO *pai;
  int value;
  NO *esquerda;
  NO *direita;
};

struct TEEN{
  NO *raiz;
  int tamanho;
};

void inicializarArvore(TEEN *a){
  a->raiz = NULL;
  a->tamanho = 0;
}


void adicionar(TEEN *a, int value){
  NO *ant = NULL;
  NO *ptr = a->raiz;
  NO *novo = (NO*) malloc(sizeof(NO));
  if(novo==NULL){
    printf("Erro de alocação.\n");
    exit(1);
  }
  novo->value = value;
  while(ptr!=NULL){
    //Iguala para não se perder
    ant = ptr;
    
    //Verifica se o valor do novo elemento é menor ou maior
    if(novo->value < ptr->value){
      ptr = ptr->esquerda;
    }else{
      ptr = ptr->direita;
    }
    
  }
  //Tendo um local livre o pai do novo elemento será o elemento antes de ser null
  novo->pai = ant;

  //Finalizada a entapa de adicionar um elemento a árvore
  //Temos que configurar os ponteiros esquerda e direita para o pai saber quem é maior ou menor
  //respectivamente.
  if(ant==NULL){
    a->raiz = novo;
  }else{
    if(novo->value < ant->value){
      ant->esquerda = novo;
    }else{
      ant->direita = novo;
    }
  }
  

}
//Vai até o menor valor e vem mostrando até o maior
void mostrarCrescente(NO *raiz){
  if(raiz!=NULL){

    
    mostrarCrescente(raiz->esquerda);
    printf("%d\n",raiz->value);
    mostrarCrescente(raiz->direita);
  }
  printf("\n");
}

//Vai até o maior valor e vem mostrando até o menor
void mostrarDecrescente(NO *raiz){
  if(raiz!=NULL){
    mostrarDecrescente(raiz->direita);
    printf("%d\n",raiz->value);
    mostrarDecrescente(raiz->esquerda);
  }
  printf("\n");
}

void pesquisarElemento(TEEN *a1, int value){
  NO *ant = NULL;
  NO *ptr = a1->raiz;
  while(ptr!=NULL){
    //Iguala para não se perder
    ant = ptr;
    
    //Verifica se o valor do novo elemento é menor ou maior
    if(value < ptr->value){
      ptr = ptr->esquerda;
    }else if(value > ptr->value){
      ptr = ptr->direita;
    }else{
      printf("%d está presente na árvore!\n\n",value);
      return; 
    }
  }

  printf("%d não está presente na árvore!\n\n",value);
}

int somatorio(NO *root){
    int subArvore1, subArvore2, soma = 0;
    if(root != NULL){
      subArvore1 = somatorio(root->direita);
      subArvore2 = somatorio(root->esquerda);
      soma = (root->value) + subArvore2 + subArvore1;
      return soma;
    }
}


int main(){ 

  TEEN *a1 = (TEEN*) malloc(sizeof(TEEN));

  inicializarArvore(a1);

  adicionar(a1, 21);
  adicionar(a1, 10);
  adicionar(a1, 33);
  adicionar(a1, 5);
  adicionar(a1, 17);
  adicionar(a1, 27);
  adicionar(a1, 35);

  printf("Crescente:\n");
  mostrarCrescente(a1->raiz);
  
  printf("Decrescente:\n");
  mostrarDecrescente(a1->raiz);

  pesquisarElemento(a1, 27);

  pesquisarElemento(a1, 207);

  printf("%d\n",somatorio(a1->raiz));

  return 0;
}

