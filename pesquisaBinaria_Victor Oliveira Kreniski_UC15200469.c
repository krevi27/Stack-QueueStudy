#include <stdio.h>
#include <stdlib.h>
// Sintese
//   objetivo "Arvore Binaria de Busca"

// Tipo para Nodo
typedef struct tNodo {
  struct tNodo *esq;	
  int valor;
  struct tNodo *dir;	
} tNodo;

// Prototipo de funcoes
int menu(void);
void incluir(struct tNodo**, struct tNodo*);
struct tNodo* pesquisar(struct tNodo*, int v);
void destruir(struct tNodo*);

int main(void) {
  struct tNodo *raiz=NULL, *novo;
  int op, valor;
  
  do {
    op = menu();
    switch (op) {
      case 1:
        printf("\n\n* Incluir *\n\n");
      	novo = (struct tNodo*) malloc(sizeof(struct tNodo));
      	printf("Digite o valor: ");
		scanf("%d", &(novo->valor));
		incluir(&raiz, novo);
   	    break;
      case 2: 
        printf("\n\n* Pesquisar *\n\n");
      	printf("Digite o valor: ");
		scanf("%d", &valor);
		if (pesquisar(raiz, valor) == NULL)
      	  printf("Nao achei!");
      	else
      	  printf("Achei!");
       break;
    	case 3:
    		destruir(raiz);
			printf("�rvore destruida com sucesso\n");		
    		break;
	}
  } while (op != 0);
  destruir(raiz);
	
  return 0;
}

int menu(void) {
  int op;
  printf("\n\n*** Menu ***\n\n");
  printf("1. Incluir\n");
  printf("2. Pesquisar\n");
  printf("0. Sair\n\n");
  printf("Digite sua opcao: ");
  scanf("%d", &op);
  return op;
}

void destruir(struct tNodo *raiz) {
	if(raiz == NULL){
		return;
	}else{
		destruir(raiz->dir);
		destruir(raiz->esq);
		free(raiz);
		no = NULL;
	}
}

void incluir(struct tNodo **raiz, struct tNodo *n) {
	n->esq = n->dir = NULL;
	if ((*raiz) == NULL)
	  (*raiz) = n;
	else
	  if (n->valor < (*raiz)->valor)
	    incluir(&((*raiz)->esq), n);
	  else
	    incluir(&((*raiz)->dir), n);
}

struct tNodo* pesquisar(struct tNodo *raiz, int v) {
	if ((raiz == NULL) || (raiz->valor == v))
    	return raiz;
    if (v < raiz->valor)
      	return pesquisar(raiz->esq, v);
    return pesquisar(raiz->dir, v);
}

