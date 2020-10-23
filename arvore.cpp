#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int numero;
    struct No *sae;
    struct No *sad;
}Arvore;

Arvore* insere(int n, Arvore *sae, Arvore *sad);
Arvore* espelho(Arvore *raiz);
Arvore* inicia();
void inverter(Arvore *raiz);
void imprimeInfixa(Arvore *tree);
void treeFree(Arvore *raiz);


int main(){
    int altura=0;

    Arvore *tree, *mirror;
    tree = insere(4,insere(2,insere(1,inicia(),inicia()),insere(3,inicia(),inicia())),
            insere(6,insere(5,inicia(),inicia()),insere(10,insere(8,inicia(),inicia()),inicia())));

    printf("Infixa Tree: ");
    imprimeInfixa(tree);



    printf("\nInfixa Espelho: ");
    mirror = espelho(tree);
    imprimeInfixa(mirror);

    printf("\n");
    system("pause");
    printf("\nLiberando arvores....");
    treeFree(tree); 
    treeFree(mirror);
    printf("\nOk");
}


Arvore* inicia(){
    return NULL;
}


void imprimeInfixa(Arvore *tree){
	if (!tree==NULL)
	{
		imprimeInfixa(tree->sae);
		printf("%d ", tree->numero);
		imprimeInfixa(tree->sad);
	}
}

Arvore* espelho(Arvore *raiz){
    if(raiz==NULL){
        return NULL;
    }else{
        Arvore *aux;
        
        espelho(raiz->sae);
        espelho(raiz->sad);
        
        aux = raiz->sae;
        raiz->sae = raiz->sad;
        raiz->sad = aux;

        return raiz;
    }
}
Arvore* insere(int n, Arvore *sae, Arvore *sad){
    Arvore *temp = (Arvore *)malloc(sizeof(Arvore));
    temp->numero=n;
    temp->sae = sae;
    temp->sad = sad;

    return temp;
}

void treeFree(Arvore *raiz){
    if(raiz!=NULL){
        treeFree(raiz->sae);
        treeFree(raiz->sad);
        free(raiz);
    }
}

