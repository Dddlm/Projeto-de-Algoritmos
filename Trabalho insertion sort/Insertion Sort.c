#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <time.h>
#include<conio.h>
#include <windows.h>



//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<In�cio da Sess�o Lista>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
typedef struct slista{
    char tipo;                                          //decrescente, crescente ou aleat�rio.
    int tam;                                            //tamanho do vetor.
    double tempo;                                       //tempo
    char algoritmo[30];                                 //nome do algoritmo
    char prenchemento[20];                              //Guarda em formato string o tipo do prenchemento do vetor
    int x;
    char caminhoE[100];                                 //caminho de entrada
    char caminhoS[100];                                 //caminho desaida
    char caminhoT[100];                                 //caminho de todos arquivos de tempo

}lista;
void informacoes (lista *l){                            //pega do usi�rio as informa��es, tipo do vetor e do algoritmo.


    sprintf(l->algoritmo, "InsertionSort");
    printf("\nQual processo de ordenacao voce deseja?\n");
	printf("1 para Decrescente     \n");
	printf("2 para Crescente       \n");
	printf("3 para Aleatoria(Randomica)       \n");
	scanf("%d",&l->tipo);

	if(l->tipo== '1')
        strcpy(l->prenchemento, "Decrescente");
	if(l->tipo== '2')
        strcpy(l->prenchemento, "Crescente");
	if(l->tipo== '3')
        strcpy(l->prenchemento, "Aleatorio(Randomico)");
}
void CriaDiretorio(lista *l){                                                                //Cria os diret�rios



    mkdir("Arquivos");                                                                      //Impress�o entrada
    sprintf(l->caminhoE,"Arquivos/%s", l->algoritmo);
    mkdir(l->caminhoE);
    sprintf(l->caminhoE,"Arquivos/%s/Entrada", l->algoritmo);
    mkdir(l->caminhoE);
    sprintf(l->caminhoE,"Arquivos/%s/Entrada/%s", l->algoritmo, l->prenchemento);
    mkdir(l->caminhoE);


    sprintf(l->caminhoS,"Arquivos/%s", l->algoritmo);                                        //Impress Saida
    mkdir(l->caminhoS);
    sprintf(l->caminhoS,"Arquivos/%s/Saida", l->algoritmo);
    mkdir(l->caminhoS);
    sprintf(l->caminhoS,"Arquivos/%s/Saida/%s", l->algoritmo, l->prenchemento);
    mkdir(l->caminhoS);


    printf(l->caminhoT,"Arquivos/%s", l->algoritmo);                                          //Fun��es de Tempo
    mkdir(l->caminhoT);
    sprintf(l->caminhoT,"Arquivos/%s/Tempo", l->algoritmo);
    mkdir(l->caminhoT);
    sprintf(l->caminhoT,"Arquivos/%s/Tempo/%s", l->algoritmo, l->prenchemento);
    mkdir(l->caminhoT);
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<#Fim da secss�o Lista>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>



//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Insertion Sort>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/*
                                       Nesta sess�o  ser� desenvolvido a base do algoritmo insertion sort


Insertion Sort, ou ordena��o por inser��o, � um algoritmo de ordena��o que, dado uma estrutura (array, lista) constr�i uma matriz final com um elemento de cada vez,
uma inser��o por vez. Assim como algoritmos de ordena��o quadr�tica, � bastante eficiente para problemas com pequenas entradas, sendo o mais eficiente entre os
algoritmos desta ordem de classifica��o.

Podemos fazer uma compara��o do Insertion Sort com o modo como algumas pessoas organizam um baralho num jogo de cartas. Imagine que voc� est� jogando �s cartas.
Voc� est� com as cartas na m�o e elas est�o ordenadas. Voc� recebe uma nova carta e deve coloc�-la na posi��o correta da sua m�o de cartas, de forma a que as
cartas obede�am � ordena��o.

A cada nova carta adicionada � sua m�o de cartas, a nova carta pode ser menor que algumas das cartas que voc� j� tem na m�o ou maior, e assim, voc� come�a a
comparar a nova carta com todas as cartas na sua m�o at� encontrar sua posi��o correta. Voc� insere a nova carta na posi��o correta, e, novamente, a sua m�o
� composta de cartas totalmente ordenadas. Ent�o, voc� recebe outra carta e repete o mesmo procedimento. Ent�o outra carta, e outra, e assim em diante, at� n�o
receber mais cartas.

Por esse motivo o algoritmo Insertion Sort n�o � �timo ao lidar com n�meros especialmente grandes, tendo um crescimento em progess�o geom�trica, oque o torna mais
suscetivel a um menor desempenho.

*/
void InsertionSort (int vet[], lista *l, int tamanho){ //Algoritmo de ordena��o insertion sort.

    int n = tamanho, i, j, key; // = l->tam
    time_t t_ini, t_fim;
    t_ini = time(NULL);

    for(j=1; j<=n; j++){
        key = vet[j];
        i = j - 1;
        while(i>=0 && vet[i]>key){
            vet[i+1] = vet[i];
            i = i - 1;
        }
        vet[i+1]=key;
    }
    t_fim = time(NULL);
    l->tempo = difftime(t_fim, t_ini);
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Fim da sess�o>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>



//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Sess�o Fun��es>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void preenche (lista *l, int vet[]){                                                                    //Preenche o vetor
    int i, j=0;

    switch(l->tipo){
        case 1:
			for(i=l->tam; i>0; i--){
                vet[j]=i;
                j++;
            }
			break;
        case 2:
            for(i=0; i<l->tam; i++)
                vet[i]=i;
            break;
        case 3:
            for(i=0;i<l->tam;i++){
                vet[i]=rand() % 1000000;
            }
            break;
        default:
            printf("Ordem Invalida\n\n\n");
            exit(1);
    }
}
void imprimir (lista *l, int vet[], int tamanho){                                                       //Imprime o vetor na tela
    int i;
    for(i=0; i<=tamanho; i++)
        printf("vet[%d] = %d \n", i, vet[i]);
}
void salvaVetor (lista *l, int vet[]){                                                                  //Guarda as informa��es no arquivo
    sprintf(l->caminhoE,"Arquivos/%s/Entrada/%s/%d.txt", l->algoritmo, l->prenchemento, l->tam);
    FILE *fp;
	int i;
	fp = fopen(l->caminhoE, "w");
	if(fp == NULL){
        printf("N�o foi possivel abrir o arquivo para guardar o vetor original\n");
        exit(1);
	}
	fprintf(fp,"Tamanho: %d", l->tam);
	fprintf(fp,"\nAlgoritmo: %s", l->algoritmo);
	fprintf(fp,"\nTipo: %s", l->prenchemento);
	fprintf(fp,"\n");
	for(i=0; i<l->tam; i++)
		fprintf(fp," %d\n",vet[i]);
	fclose(fp);
}
void salvaVetOrd (lista *l, int vet[]){                                                           //guarda o vetor ordenado em um arquivo txt.

    sprintf(l->caminhoS,"Arquivos/%s/Saida/%s/%d.txt", l->algoritmo, l->prenchemento, l->tam);
    FILE *fp;
	int i;
	fp = fopen(l->caminhoS, "w");
	if(fp == NULL){
        printf("N�o foi possivel abrir o arquivo para guardar o vetor ordenado\n");
        exit(1);
	}
	fprintf(fp,"Tamanho: %d", l->tam);
	fprintf(fp,"\nAlgoritmo: %s", l->algoritmo);
	fprintf(fp,"\nTipo: %s", l->prenchemento);
	fprintf(fp,"\n");
	for(i=0; i<l->tam; i++)
		fprintf(fp," %d\n",vet[i]);
	fclose(fp);
}
void salvaTemp(lista *l){                                                                        //Tempo de execu��o

    sprintf(l->caminhoT,"Arquivos/%s/Tempo/%s/%d.txt", l->algoritmo, l->prenchemento, l->tam);
    FILE *fp; int i;
    fp = fopen(l->caminhoT, "w");
    if(fp == NULL){
        printf("N�o foi possivel abrir o arquivo para guardar o tempo\n");
        exit(1);
	}
	int tam; double tempo2;
	tam = l->tam; tempo2 = l->tempo;
	fprintf(fp,"Tamanho: %d", tam);
	fprintf(fp,"\nAlgoritmo: %s", l->algoritmo);
	fprintf(fp,"\nTipo: %s", l->prenchemento);
	fprintf(fp,"\n");
	fprintf(fp,"Tempo: %f\n", tempo2);
	fclose(fp);
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Fim da Sess�o Fun��es>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>



//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Menu>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void menu(int *vet, lista *l, int tamanho){
    int op=1; int min;
    while(op != 0)
        {
            printf("\nInsertionSort Novo                  ");
            printf("\n1- Preencher Vetor                ");
            printf("\n2- InsertionSort                  ");
            printf("\n3- Imprimir                       ");
            printf("\n0- Sair                           ");
            printf("\n");
            scanf("%d", &op);
            system("cls");
            switch(op)
            {
                case 1:
                    informacoes(l);
                    preenche(l, vet);
                    break;
                case 2:{
                    CriaDiretorio(l);  system("cls");
                    salvaVetor(l, vet);
                    clock_t start_t, end_t;  double tempoGasto;
                    start_t = clock();
                    InsertionSort(vet, &l, tamanho);
                    end_t = clock();
                    tempoGasto = ((end_t - start_t) / (double)CLOCKS_PER_SEC);
                    l->tempo = tempoGasto;
                    salvaVetOrd(l, vet);
                    salvaTemp(l);
                    break;
                }
                case 3:
                    imprimir(&l, vet, tamanho);
                    break;
                case 0: printf("\nExit"); break;
                default: printf("\nNumero Invalido."); break;
            }
        }
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Fim da sess�o Menu>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>



//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<MAIN>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int main(){

    system("color 3f");
    lista l;
    int *vet; printf("\n Qual o tamanho do vetor? "); scanf("%d",&l.tam); if(l.tam <= 0) exit(1);          //Pergunta na tela
    int tamanho=l.tam-1;                                                                                   //Recebe o tamanho do n�mero que ser� utilizado
    vet=(int*) malloc(l.tam * sizeof (int));                                                               //Aloca o vetor
    menu(vet, &l, tamanho);                                                                                         //Acessa o menu
    free(vet);                                                                                             //Libera o espa�o de mem�ria


}
