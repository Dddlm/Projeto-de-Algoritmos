#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> //gera o tempo em segundos.
#include <dir.h> //biblioteca para gerar os diretórios

typedef struct slista{ //estrutura com as váriáveis ultilizadas
    int tipo; //opção do tipo do vetor, decrescente, crescente ou aleatório.
    int tam; //tamanho do vetor.
    double tempo; //tempo de execusão gasto para ordenar o vetor.
    char algoritmo[30]; //nome do algoritmo ultilizado
    char prenchemento[20]; //Guarda em formato string o tipo do prenchemento do vetor
    int x; //representativo
    char caminhoE[100]; //variável que guarda o caminho de todos arquivos de entrada
    char caminhoS[100]; //variável que guarda o caminho de todos arquivos de saida
    char caminhoT[100]; //variável que guarda o caminho de todos arquivos de tempo

}lista;

void informacoes (lista *l){ //pega do usiário as informações, tipo do vetor e do algoritmo.
    //===============================Algoritmo=================================
    int op;
    printf("1- Insertion-Sort                \n");
    printf("2- Buble-Sort                    \n");
    printf("3- Selection-Sort                \n");
    printf("4- Shell-Sort                    \n");
    printf("5- Merge-Sort                    \n");
    printf("6- Quick-Sort                    \n");
    scanf("%d", &op);
    switch(op){
        case 1:
			sprintf(l->algoritmo,"InsertionSort");
			l->x=1;
			break;
        case 2:
            sprintf(l->algoritmo,"BubleSort");
            l->x=2;
            break;
        case 3:
            sprintf(l->algoritmo, "SelectionSort");
            l->x=3;
            break;
        case 4:
            sprintf(l->algoritmo, "ShellSort");
            l->x=4;
            break;
        case 5:
            sprintf(l->algoritmo, "MergeSort");
            l->x=5;
            break;
        case 6:
            sprintf(l->algoritmo, "QuickSort");
            l->x=6;
            break;
    }
    //===============================Tipo======================================   //1- Insertion. 2- Bubble, 3- Selection, 4- Shell, 5- Merge
    printf("\nEm qual ordem deseja colocar o vetor ?\n");
	printf("1- Decrescente      \n");
	printf("2- Crescente        \n");
	printf("3- Aleatoria        \n");
	scanf("%d",&l->tipo);
	if(l->tipo== 1)
        strcpy(l->prenchemento, "Decrescente");
	if(l->tipo== 2)
        strcpy(l->prenchemento, "Crescente");
	if(l->tipo== 3)
        strcpy(l->prenchemento, "Aleatorio");
}

void CriaDiretorio(lista *l){
    //===============================Entrada======================================
    mkdir("Arquivos");
    sprintf(l->caminhoE,"Arquivos/%s", l->algoritmo);
    mkdir(l->caminhoE);
    sprintf(l->caminhoE,"Arquivos/%s/Entrada", l->algoritmo);
    mkdir(l->caminhoE);
    sprintf(l->caminhoE,"Arquivos/%s/Entrada/%s", l->algoritmo, l->prenchemento);
    mkdir(l->caminhoE);

    //===============================Saida======================================
    sprintf(l->caminhoS,"Arquivos/%s", l->algoritmo);
    mkdir(l->caminhoS);
    sprintf(l->caminhoS,"Arquivos/%s/Saida", l->algoritmo);
    mkdir(l->caminhoS);
    sprintf(l->caminhoS,"Arquivos/%s/Saida/%s", l->algoritmo, l->prenchemento);
    mkdir(l->caminhoS);

//===============================Tempo======================================
    printf(l->caminhoT,"Arquivos/%s", l->algoritmo);
    mkdir(l->caminhoT);
    sprintf(l->caminhoT,"Arquivos/%s/Tempo", l->algoritmo);
    mkdir(l->caminhoT);
    sprintf(l->caminhoT,"Arquivos/%s/Tempo/%s", l->algoritmo, l->prenchemento);
    mkdir(l->caminhoT);
}

void preenche (lista *l, int vet[]){ //preenche o vetor de acordo com a opção escolhida .
    int i, j=0;
    switch(l->tipo){
        case 1:
			//printf("\nDecrescente\n");
			for(i=l->tam; i>0; i--){
                vet[j]=i; //i se inicia do ultimo valor de tam, colocando na posição j ------> i[0]=1000000
                j++;
            }
			break;
        case 2:
            //printf("\nCrescente\n");
            for(i=0; i<l->tam; i++)
                vet[i]=i;
            break;
        case 3:
            //printf("\nAleatório\n");
            for(i=0;i<l->tam;i++){
                vet[i]=rand() % 1000000;
            }
            break;
        default:
            printf("Ordem Inválida");
            exit(1);
    }
}

void imprimir (lista *l, int vet[]){ //imprime na tela todo o vetor .
    int i;
    for(i=0; i<l->tam; i++)
        printf("vet[%d] = %d \n", i, vet[i]);
}

void guardar_vetor (lista *l, int vet[]){ //guarda o vetor de um arquivo txt.
    sprintf(l->caminhoE,"Arquivos/%s/Entrada/%s/%d.txt", l->algoritmo, l->prenchemento, l->tam);

    FILE *fp;
	int i;
	fp = fopen(l->caminhoE, "w");
	if(fp == NULL){
        printf("Não foi possivel abrir o arquivo\n");
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

void guardar_vetor_ordenado (lista *l, int vet[]){ //guarda o vetor ordenado em um arquivo txt.
    sprintf(l->caminhoS,"Arquivos/%s/Saida/%s/%d.txt", l->algoritmo, l->prenchemento, l->tam);

    FILE *fp;
	int i;
	fp = fopen(l->caminhoS, "w");
	if(fp == NULL){
        printf("Não foi possivel abrir o arquivo\n");
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

void guardar_tempo(lista *l){ //guarda o tempo de execução para ordenar o vetor.
    sprintf(l->caminhoT,"Arquivos/%s/Tempo/%s/%d.txt", l->algoritmo, l->prenchemento, l->tam);


    FILE *fp; int i;
    fp = fopen(l->caminhoT, "w");
    if(fp == NULL){
        printf("Não foi possivel abrir o arquivo\n");
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

void InsertionSort (int *vet, lista *l){ //Algoritmo de ordenação insertion sort.
    int n = l->tam, i, j, key;
    for(j=1; j<n; j++){
        key = vet[j];
        i = j - 1;
        while(i>=0 && vet[i]>key){
            vet[i+1] = vet[i];
            i = i - 1;
        }
        vet[i+1]=key;
    }
}

void SelectionSort(int *vet, lista *l){ //Algoritmo de ordenação Selection sort.
    int tam = l->tam;
    int i, j, temp, PosicaoValorMinimo;
    for(i=0; i<tam-1; i++){
        PosicaoValorMinimo = i;
        for(j=(i+1); j<tam; j++){
            if(vet[j]<vet[PosicaoValorMinimo]){
                PosicaoValorMinimo = j;
            }
        }
        if(i!= PosicaoValorMinimo){
            temp=vet[i];
            vet[i]=vet[PosicaoValorMinimo];
            vet[PosicaoValorMinimo] = temp;
        }
    }
}

void BubbleSort(int *vet, lista *l){ //Algoritmo de ordenação Bubble sort.
    int tam = l->tam;
	int i, j, temp;
    for (i = 0; i < tam; i++){
        for (j = 0; j < tam - 1; j++){
            if (vet[j + 1] < vet[j]){
                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
    }
}

void ShellSort(int *vet, lista *l){ //Algoritmo de ordenação Shell sort.
    int tam = l->tam;
    int i, j, k, temp;
    for (i = tam / 2; i > 0; i = i / 2){
        for (j = i; j < tam; j++){
            for(k = j - i; k >= 0; k = k - i){
                if (vet[k+i] >= vet[k])
                    break;
                else{
                    temp = vet[k];
                    vet[k] = vet[k+i];
                    vet[k+i] = temp;
                }
            }
        }
    }
}

void Merge(int inicio, int meio, int fim, int *vet){ //Função ultilizada no algoritmo Merge-Sort.
    int i, j, k, *temp;
    temp = (int*) malloc ((fim-inicio) * sizeof (int));
    i = inicio; j = meio; k = 0;

    while (i < meio && j < fim) {
       if (vet[i] <= vet[j])  temp[k++] = vet[i++];
       else  temp[k++] = vet[j++];
    }
    while (i < meio)
        temp[k++] = vet[i++];
    while (j < fim)
        temp[k++] = vet[j++];
    for (i = inicio; i < fim; ++i)
        vet[i] = temp[i-inicio];
    free (temp);
}

void MergeSort(int inicio, int fim, int *vet){ //Algoritmo de ordenação Merge sort.
   if (inicio < fim-1) {
      int meio = (inicio + fim)/2;
      MergeSort(inicio, meio, vet);
      MergeSort(meio, fim, vet);
      Merge(inicio, meio, fim, vet);
   }
}

//============================================================Extremo=====================================================================================

void troca(int posicao, int a, int *vet){ // j, i vet;
    int aux;
    aux = vet[a];
    vet[a] = vet[posicao]; //vet[i] = vet[j];
    vet[posicao] = aux; // vet[j] = temp
}

int ParticionaExtremo(int *vet, int p, int r) { //Função utilizada pelo algoritmo Quick-Sort, com pivo extremo
    int x = vet[r];             //1
	int i = p-1;                //2
	int j;                      //3
    for(j=p;j<=r-1;j++) {       //4
		if (vet[j] <= x) {      //5
			i++;                //6
			troca(i,j, vet);    //7
		}                       //8
	}                           //9
	troca(i+1,r, vet);          //10
	return i+1;                 //11
}

void QuickSortExtremo(int *vet, int p, int r) {           //Quick-Sort com pivo extremo
	if (p<r) {                               //1
		int q = ParticionaExtremo(vet,p,r);  //2
		QuickSortExtremo(vet,p,q-1);         //3
		QuickSortExtremo(vet,q+1,r);         //4
	}
}

//===========================================================Media========================================================================================

void TrocaMedio(int *vet, int i, int y){
    int aux;
    aux = vet[y];
    vet[y] = vet[i]; //vet[i] = vet[j];
    vet[i] = aux; // vet[j] = temp
}

int ParticionaMedio (int quick[], int inicio, int fim, int pivo){
    int y, i;
    TrocaMedio(quick, pivo, fim);
    y = inicio;
    for(i = inicio; i < fim; i++){
    	if (quick[i] < quick[fim]){
        	TrocaMedio(quick, i, y);
        	y++;
		}
	}
    TrocaMedio(quick, fim, y);
    return y;
}

void QuickSortMedio (int *X, int inicio, int fim){
	int pivo, y;
    if (inicio < fim){
    	pivo = (inicio+fim)/2;
        y = ParticionaMedio(X, inicio, fim, pivo);
        QuickSortMedio(X, inicio, y-1);
        QuickSortMedio(X, y+1, fim);
    }
}

//===========================================================Aleatorio====================================================================================

int aleatorio(int alfa, int omega){
	int valor, aux;
	aux = omega - alfa;
	srand(valor*aux);
	valor=rand() % aux;
	return valor;
}

int ParticionaAleatorio(int *vet, int alfa, int omega){
	int pivo, i, j, k;
	i = alfa - 1;
	j = omega + 1;
	k = aleatorio(alfa, omega);
	k+= alfa;
	pivo = vet[k];
	while(1){

	do
		j--;
	while(vet[j] > pivo);


	do
		i++;
	while(vet[i] < pivo);


	if(i < j)
		TrocaMedio(vet, i, j);

	else return j;

	}
	return 0;
}

int QuickSortAleatorio(int *vet,int p,int r){
	int q;
	if(p<r)
	{
		q=ParticionaAleatorio(vet,p,r);
		QuickSortAleatorio(vet,p,q);
		QuickSortAleatorio(vet,q+1,r);
	}
}

//===========================================================Mediana======================================================================================
int ParticionaMediana (int *X, int inicio, int fim) {
	int pivo, aux, aux2, i, j;
	pivo = X[inicio];
	aux = X[(fim-inicio)/2+inicio];
	aux2 = X[fim-1];
	i = inicio - 1;
	j = fim;
	if (aux > pivo && aux < aux2 || aux > aux2 && aux < pivo){
		pivo = aux;
	}else{
		if (aux2 > pivo && aux2 < aux || aux2 > aux && aux2 < pivo ){
			pivo = aux2;
		}
	}
	while (1){
		do{
			j--;
		}while (X[j] > pivo);

		do{
			i++;
		}while (X[i] < pivo);

		if  (i < j){
			TrocaMedio(X, i, j);
		}else{
			return j+1;
		}

	}
	return 0;
}

void QuickSortMediano (int *X, int inicio, int fim){
	int y;
    if (fim-inicio < 2)
		return;

    y = ParticionaMediana(X, inicio, fim);
    QuickSortMediano(X, inicio, y);
    QuickSortMediano(X, y, fim);
}

//===========================================================Menu=========================================================================================
void menu(int *vet, lista *l){ //1- Insertion. 2- Bubble, 3- Selection, 4- Shell, 5- Merge, 6- Quick
    switch(l->x){
        case 1: //InsertionSort
            {
                guardar_vetor(l, vet);
                clock_t start_t, end_t;  double tempoGasto;
                start_t = clock();
                InsertionSort(vet, l);
                end_t = clock();
                tempoGasto = ((end_t - start_t) / (double)CLOCKS_PER_SEC);
                l->tempo = tempoGasto;
                guardar_vetor_ordenado(l, vet);
                guardar_tempo(l);
                //imprimir(&l, vet);
                break;
            }
        case 2: //BubbleSort
           {
                guardar_vetor(l, vet);
                clock_t start_t, end_t;  double tempoGasto;
                start_t = clock();
                BubbleSort(vet, l);
                end_t = clock();
                tempoGasto = ((end_t - start_t) / (double)CLOCKS_PER_SEC);
                l->tempo = tempoGasto;
                guardar_vetor_ordenado(l, vet);
                guardar_tempo(l);
                //imprimir(&l, vet);
                break;
           }
        case 3: //SelectionSort
            {
                guardar_vetor(l, vet);
                clock_t start_t, end_t;  double tempoGasto;
                start_t = clock();
                SelectionSort(vet, l);
                end_t = clock();
                tempoGasto = ((end_t - start_t) / (double)CLOCKS_PER_SEC);
                l->tempo = tempoGasto;
                guardar_vetor_ordenado(l, vet);
                guardar_tempo(l);
                //imprimir(&l, vet);
                break;
            }
        case 4: //ShellSort
            {
                guardar_vetor(l, vet);
                clock_t start_t, end_t;  double tempoGasto;
                start_t = clock();
                ShellSort(vet, l);
                end_t = clock();
                tempoGasto = ((end_t - start_t) / (double)CLOCKS_PER_SEC);
                l->tempo = tempoGasto;
                guardar_vetor_ordenado(l, vet);
                guardar_tempo(l);
                //imprimir(&l, vet);
                break;
            }
        case 5: //MergeSort
            {
                guardar_vetor(l, vet);
                clock_t start_t, end_t;  double tempoGasto;
                start_t = clock();
                MergeSort(0, l->tam, vet); //int inicio, int fim, int *vet
                end_t = clock();
                tempoGasto = ((end_t - start_t) / (double)CLOCKS_PER_SEC);
                l->tempo = tempoGasto;
                guardar_vetor_ordenado(l, vet);
                guardar_tempo(l);
                //imprimir(&l, vet);
                break;
            }
        case 6: //QuickSort
            {
                int t; printf("\n");
                printf("1- Extremo                 \n");
                printf("2- Medio                   \n");
                printf("3- Mediano                 \n");
                printf("4- Aleatorio               \n");
                scanf("%d", &t);

                switch(t){
                    case 1:
                    {
                        printf("\nExtremo\n"); guardar_vetor(l, vet); clock_t start_t, end_t;  double tempoGasto;  start_t = clock();
                        QuickSortExtremo(vet, 0, l->tam); // imprimir(l, vet);
                        end_t = clock(); tempoGasto = ((end_t - start_t) / (double)CLOCKS_PER_SEC);  l->tempo = tempoGasto;
                        guardar_vetor_ordenado(l, vet); guardar_tempo(l);
                        break;
                    }
                    case 2:
                    {
                        printf("\nMedio\n");
                        guardar_vetor(l, vet); clock_t start_t, end_t;  double tempoGasto;  start_t = clock();
                        QuickSortMedio(vet, 0-1, l->tam);
                        //imprimir(l, vet);
                        end_t = clock();
                        tempoGasto = ((end_t - start_t) / (double)CLOCKS_PER_SEC);
                        l->tempo = tempoGasto;
                        guardar_vetor_ordenado(l, vet);
                        guardar_tempo(l);
                        break;
                    }
                    case 3:
                    {
                        printf("\nMediano\n");
                        guardar_vetor(l, vet); clock_t start_t, end_t;  double tempoGasto;  start_t = clock();
                        QuickSortMediano(vet, 0, l->tam); //imprimir(l, vet);
                        end_t = clock(); tempoGasto = ((end_t - start_t) / (double)CLOCKS_PER_SEC);  l->tempo = tempoGasto;
                        guardar_vetor_ordenado(l, vet); guardar_tempo(l);
                        break;
                    }
                    case 4:
                    {
                        printf("\nAleatorio\n");
                        guardar_vetor(l, vet); clock_t start_t, end_t;  double tempoGasto;  start_t = clock();
                        QuickSortAleatorio(vet, 0, l->tam);  //imprimir(l, vet);
                        end_t = clock(); tempoGasto = ((end_t - start_t) / (double)CLOCKS_PER_SEC);  l->tempo = tempoGasto;
                        guardar_vetor_ordenado(l, vet); guardar_tempo(l);
                        break;
                    }
                }
            }
    }
}

int main(){
    lista l;
    int *vet; printf("Tamanho: "); scanf("%d",&l.tam); if(l.tam <= 0) exit(1);
    vet=(int*) malloc(l.tam * sizeof (int)); //cria e aloca um vetor do tamanha desejado.
    informacoes(&l); CriaDiretorio(&l);  system("cls");
    preenche(&l, vet); //imprimir(&l, vet);
    menu(vet, &l);

    free(vet); //Libera o vetor.

}