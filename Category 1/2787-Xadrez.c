#include <stdio.h>


int EhPar(int num){
    return num%2 == 0;
}


int main(){
    int linhas, colunas;


    scanf("%d %d", &linhas, &colunas);
    if (EhPar(linhas) && EhPar(colunas)){
        puts("1");
    }
    else if (!EhPar(linhas) && !EhPar(colunas)){
        puts("1");
    }
    else {
        puts("0");
    }


    return 0;
}