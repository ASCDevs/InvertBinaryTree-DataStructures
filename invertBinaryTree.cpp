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

    Arvore *arvore1, *espelho1;
    arvore1 = insere(4,insere(2,insere(1,inicia(),inicia()),insere(3,inicia(),inicia())),
            insere(6,insere(5,inicia(),inicia()),insere(10,insere(8,inicia(),inicia()),inicia())));

    printf("Exemplo 1:\n");
    printf("Leitura Infixa arvore1: ");
    imprimeInfixa(arvore1);

    printf("\nLeitura Infixa espelho da arvore1: ");
    espelho1 = espelho(arvore1);
    imprimeInfixa(espelho1);
    printf("\n\n");

    Arvore *arvore2, *espelho2;
    arvore2 = insere(27,insere(21,insere(12,insere(10,inicia(),inicia()),insere(19,inicia(),inicia())),inicia())
            ,insere(47,insere(81,insere(72,inicia(),inicia()),insere(82,inicia(),inicia())),inicia()));

    printf("Exemplo 2:\n");
    printf("Leitura Infixa arvore2: ");
    imprimeInfixa(arvore2);

    printf("\nLeitura Infixa espelho da arvore2: ");
    espelho2 = espelho(arvore2);
    imprimeInfixa(espelho2);
    printf("\n\n");

    Arvore *arvore3, *espelho3;
    arvore3 = insere(32,insere(1,inicia(),insere(2,inicia(),inicia()))
            ,insere(89,insere(42,inicia(),insere(83,inicia(),inicia())),inicia()));

    printf("Exemplo 3:\n");
    printf("Leitura Infixa arvore3: ");
    imprimeInfixa(arvore3);

    printf("\nLeitura Infixa espelho da arvore3: ");
    espelho3 = espelho(arvore3);
    imprimeInfixa(espelho3);
    printf("\n\n");

    printf("\n");
    system("pause");
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

