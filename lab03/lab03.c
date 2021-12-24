#include <stdio.h>
#include <stdlib.h>
// a ideia para resolver este problema é calcular os custos que no caso seria igual ao campo valor do structure
// já para calcular o caminho que devemos percorrer até achar o percurso de valor maximo temos os campos x0 e y0 que correspondem
// a posição inicial da matriz de


// movimentação do tabuleiro: temo que nas posições periféricas temos apenas dois tipos de movimentos, ou seja, só por ir para cima ou para cima + esquerda ou direita para
// dependendo de qual periferia você está.
struct Matriz {
    int valor;
    int x0;
    int y0;
};
typedef struct Matriz Matriz;
// irá printar o caminho, note que o caminho que devemos printar começa pela primeira linha, ou seja, temos que fazer uma recursão e só depois
// que chegar no final da recursão temos que ir printando, como se fosse uma pilha, temo que primeiro empilhar os primeiros valores( pŕimeiros valores eu digo as ultimas linhas)

void print_path(Matriz **m,int x,int y,int n){
    if(n<=0){
        return;
    }
    else{
        print_path(m,m[x][y].x0,m[x][y].y0,n-1);
        printf("%d ", y);
    }
}
// irá achar o valor maximo, este por sua vez estára na ultima linha da matriz
void find_max(Matriz **m,int n){
    int j;
    int max=-999;
    int x0,y0,y;
    for(j=0; j<n;j++){
            if(m[n-1][j].valor>max){
            max=m[n-1][j].valor;
            x0=m[n-1][j].x0;
            y0=m[n-1][j].y0;
            y=j;
           } 
        }
    printf("%d\n", max);
    print_path(m,x0,y0,n-1);
    printf("%d\n",y);
}

int main(){
    int n,j,i, entradas;
    // lo = linha origem ld= linha destino | co= coluna origem cd= coluna destino | p = reais coletados
    int lo,co,ld,cd,p; 
    scanf("%d",&n);
    entradas=((n-1)*(4+3*(n-2)));
    Matriz** custo=malloc(n*sizeof(Matriz*));
     for(i=0;i<n;i++){
        custo[i]=malloc(n*sizeof(Matriz));
    }

    // inicilização da matrix:
    // primeira linha da matriz ela tem custo nulo, pois é onde se inicia. outros valores colocarei como menos infinito, ou seja -999
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==0){
                custo[i][j].valor=0;
                custo[i][j].x0=i;
                custo[i][j].y0=j;
            } else{
                custo[i][j].valor=-999;
                custo[i][j].x0=i;
                custo[i][j].y0=j;
            }
        }
    }

    //calculo dos custos para andar no tabuleiro
    for(int j=0;j<entradas;j++){
        scanf("%d %d %d %d %d",&lo,&co,&ld,&cd,&p);
        if(custo[ld][cd].valor<(custo[lo][co].valor+p)){
            custo[ld][cd].valor=(custo[lo][co].valor)+p;
            custo[ld][cd].x0=lo; // irá setar de qual celula da matriz ele veio, de qual linha 
            custo[ld][cd].y0=co;// ira setar de qual celula da matriz ele veio, de qual coluna
        }
    }
  find_max(custo,n);
  for (i = 0; i < n; i++){
      free(custo[i]);
  }
  free(custo);
    return 0;
}