#include <stdio.h>
#include <stdlib.h>

double max(double a, double b){
    if(a>b){
        return a;
    }
    else 
        return b;
}

double min(double a, double b){
    if(a<b){
        return a;
    }
    else 
        return b;
}


/* 
A ideia é achar a subsequencia que tem o maior produto
lembrando das aulas você tem que utilizar de uma estrategia
por indução:

1.caso base é o conjunto vazio, portanto 
o produto maximo é 1
2. Hipotese: sabemos calcular a subsequencia com o produto
máximo com n<2 e sabemos calcular o sufixo de produto maximo
e o menor produto.

3. passo: vet= { x1,x2,.. xn} e vet'={x1,x2, ..xn-1}
por hipotese de indução sabemos calular para vet',
agora temos que adicionar x' para solução e calcular os 
casos.

obs: lembrando como estamos trabalhando com produto,
temos que calular o menor valor, pois se ele é negativos
se multiplicarmos negativo por negativo dá positivo,
e talvez fique maior que o maximo valor atual.

*/
double maxDot(double*vet, int n){
    double min_dot=0,max_dot=0,maximo=0;
    double max_insertion_Xn;
    double min_insertion_Xn;
    int i;
    for(i=0;i<n;i++){
        
        //inserção de xn
        max_insertion_Xn=max(vet[i]*max_dot,vet[i]*min_dot);
        min_insertion_Xn=min(vet[i]*max_dot,vet[i]*min_dot);
        
        // re calculo do maior produto e o menor produto
        max_dot=max(vet[i],max_insertion_Xn);
        min_dot=min(vet[i],min_insertion_Xn);

        //calculo do maximo a cada inserção (verifica se o maximo anterior é maior que o maximo atual, pós insercao de xn)
        maximo=max(maximo,max_dot);
    }

    return maximo;
}





int main(){
    int n,i;
    double casobase=1.0;
    scanf("%d",&n);
    double *v=malloc(n*sizeof(double));
    for(i=0;i<n;i++){
        scanf("%lf",&v[i]);
    }
    double maximo =maxDot(v,n);
    // verificar se é melhor escolher o caso base, que é o conjunto vazio com valor 1 do que o maximo de
    maximo = max(casobase,maximo);
    printf("%lf\n",maximo);
    return 0;
}