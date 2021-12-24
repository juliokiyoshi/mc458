#include <stdio.h>
#include <stdlib.h>
/*----------------------------------------------------------------
Lab04: 

Suponha que você receba um conjunto de tarefas S = {a1, a2, ..., an}, onde a tarefa ai requer pi unidades de tempo de processamento para ser concluída, uma vez iniciada. 
Você tem um computador para executar essas tarefas, e o computador pode executar apenas uma tarefa por vez. Seja ci o tempo de conclusão da tarefa ai, ou seja, 
o tempo em que a tarefa ai conclui o processamento. Seu objetivo é minimizar o tempo total de conclusão, ou seja, minimizar c1 + c2 + ... + cn.

Projete e implemente um algoritmo O(n log n) que escalona as tarefas de forma a minimizar o tempo total de conclusão. Cada tarefa deve ser executada de forma não preemptiva, ou seja,
 uma vez que a tarefa ai é iniciada, ela deve ser executada continuamente por pi unidades de tempo

*/

/*----------------------------------------------------------------
Solução: 
Para resolver o laboratório temos que criar uma struct que guarda o numero da atividade i(posição) e guarda também o valor custo tempo de execução da atividade i
então teremos um vetor que guarda essas duas informações. Agora temos que aplicar a solução gulosa para este problema.

Solução Gulosa: Esta solução para minimizar o tempo total de conclusão é execultar o trabalho com o menor tempo de execução primeiro, S= min(tempo de execução do vetor de tarefas).
para a proxima interação temos a subestrutura otima que é dado como S' = S -  min(tempo de execução do vetor de tarefas). Lembrando muito o problema da mochila porém no caso do laboratório,
não temos a capacidade maxima para realizar as operações. O que facilita demais a resolução do problema, já que podemos fazer todas as operações sem se preocupar com um limite de operações.
Se tivessemos um limite de execução Poderiamos calcular até em quantos dias seria necessário para realizar todas as operações em menos dias.

Para facilitar achar o minimo podemos aplicar um algoritmo de ordenação estável, para manter o indices menores nas posições corretas no pós ordenação.
algoritmos escolhido é o merge-sort ordenando o valor (tempo de processamento).

*/


typedef struct vetor{
    int valor;
    int posicao;
}vetor;

void print(vetor* vetor,int n){
    int i;
    for(i=0;i<n;i++){
        printf("\nposicao: %d\n ", vetor[i].posicao);
        printf("valor: %d\n", vetor[i].valor);

        }
    }

void merge(vetor* vet,int l, int m, int r ){
    int i,j;
    int n1=m-l+1;
    int n2=r-m;
    vetor* left=malloc(n1*sizeof(vetor));
    vetor* right=malloc(n2*sizeof(vetor));

    for(i=0;i<n1;i++){
        left[i].valor=vet[l+i].valor;
        left[i].posicao=vet[l+i].posicao;
    }
      for(i=0;i<n2;i++){
        right[i].valor=vet[m + 1 + i].valor;
        right[i].posicao=vet[m + 1 + i].posicao;
    }

    i=0;
    j=0;
    int k=l;
    while (i < n1 && j < n2) {
        if (left[i].valor <= right[j].valor) {
            vet[k].valor = left[i].valor;
            vet[k].posicao = left[i].posicao;
            i++;
        }
        else {
            vet[k].valor = right[j].valor;
            vet[k].posicao = right[j].posicao;
            j++;
        }
        k++;
    }
    while (i < n1) {
        vet[k].valor = left[i].valor;
        vet[k].posicao = left[i].posicao;
        i++;
        k++;
    }
    while (j < n2) {
        vet[k].valor = right[j].valor;
        vet[k].posicao = right[j].posicao;
        j++;
        k++;
    }
    free(right);
    free(left);
}
void mergeSort(vetor* vet,int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m =l+ (r-l)/2;
    mergeSort(vet,l,m);
    mergeSort(vet,m+1,r);
    merge(vet,l,m,r);
}
void sum(int *vet,int n){
    int i,sum=0;
    for(i=0;i<n;i++){
        sum +=vet[i];
    }
    printf("%d\n",sum);
}
void solution(vetor*vet,int n){
    int *conclusao=malloc(n*sizeof(int));
    int i;
    for(i=0;i<n;i++){
        if(n==0){
            conclusao[i]=vet[i].valor;
        }
        else{
            conclusao[i]=conclusao[i-1]+vet[i].valor;
        }
    }
    sum(conclusao,n);
    for(i=0;i<n;i++){
        if(i==n-1){
            printf("%d\n",vet[i].posicao);
        }
        else{
            printf("%d ",vet[i].posicao);
        }
    }
    free(conclusao);
}
int main(){
    int n,i;
    // leitura do tamanho do vetor;
    scanf("%d",&n);
    vetor * vet= malloc(n*sizeof(vetor));
    // leitura dos dados;
    for(i=0;i<n;i++){
        vet[i].posicao=i+1;
        scanf("%d",&vet[i].valor);
    }
    mergeSort(vet, 0,n-1);
    //printf("\nPOS ORDENACAO TEMOS:\n");
    //print(vet,n);
    solution(vet,n);

    free(vet);
    return 0;

}