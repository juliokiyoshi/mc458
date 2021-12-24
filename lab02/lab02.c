#include <stdio.h>
#include <stdlib.h>

/* Objetivo do lab02 é o estudo sobre ordenação, 
Devemos ordernar um conjunto de vetores em tempo O(n),
no qual as entradas tem tamanho de O(N^2 -1)
*/


/*************** Estratégia para ordenar em O(n) **************************
 A estratégia para ordenar em O(n) é utilizar o radix sort, porém
 não devemos tratar a base como decimal, devemos mudar de base 10 para a 
 base n para assim aplicar o algoritmo. Para auxiliar o algoritmo do 
 radix sort iremos utilizar o count Sort visto em sala de aula

***************************************************************************/




/**************************CountSort ******************
 * pseudocodigo:
count = array of k+1 zeros
for x in input do
    count[key(x)] += 1

total = 0
for i in 0, 1, ... k do
    count[i], total = total, count[i] + total

output = array of the same length as input
for x in input do
    output[count[key(x)]] = x
    count[key(x)] += 1 

return output
 * ****************************************************/
void countsort(int *vet,int n, int digito){
    int i;
    int *aux=malloc(n*sizeof(int));
    int *count=calloc(n,sizeof(int));
    for(i=0;i<n;i++){
        count[(vet[i]/digito)%n]++;
        // lembrando que vet[i]/digito%n vai extrair o valor a raiz do valor, ou seja, caso digito 1 e vet[0]= 78 o resultado = 8
        // caso o digito n e vet [0]=78 o resultado é o 7
    }
    for(i=1;i<n;i++){
        count[i]=count[i]+count[i-1];
    }
    for(i=n-1;i>=0;i--){
        aux[count[(vet[i]/digito)%n]-1]=vet[i];
        count[(vet[i]/digito)%n]=count[(vet[i]/digito)%n]-1;
    }
    for(i=0;i<n;i++){
        vet[i]=aux[i];
    }

}
/*************** ordenação **************************
esta função apĺica a estratégia do radix sort para ordenar
primeiro o primeiro digito na base n, e por fim devemos 
ordenar o digito restante.

lebrando que as entradas tem tamanho O(n² -1), ou seja valem de n² ate 1
se convertemos para a base n temos que [Digito mais significativo]_base=n [digito menos significativo]_base n
assim temos que ordenar primeiro o digito menos significativo e logo em seguida o digito mais significativo

****************************************************/

void ordenacao(int *vet, int tam){
    // primeiro devemos ordenar o primeiro digito na base n, sendo o primeiro digito =1
    countsort(vet,tam,1);
    // ordenação do segundo digito na base n, como o primeiro digito é o 1 temos que o segundo digito é n
    countsort(vet,tam,tam);   
}

void print_vet(int *vet,int n){
    for(int i=0; i<n; i++){
        if(i==n-1){
            printf("%i\n",vet[i]);
        }
        else{
            printf("%i ",vet[i]);
        }
    }
}
int main(){
    int n;
    int *vet;
    scanf("%i",&n);
    vet=malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%i", &vet[i]);
    }
    ordenacao(vet,n); // ordenacao em tempo O(n) com vetores de entrada n^2 -1
    print_vet(vet,n);// printar o vetor
    
    return 0;
}
