#include <stdio.h>


int ResultRafael(int x, int y){
    return 9*x*x + y*y;
}

int ResultBeto(int x, int y){
    return 2*x*x + 25*y*y;
}

int ResultCarlos(int x, int y){
    return -100*x + y*y*y;
}

/****
 * Vencedor: Encontra quem eh o vencedor entre Rafael, Beto e Carlos,
 *           comparando os resultados de suas funcoes.
 * 
 * Parametros:
 * rafael - Resultado da funcao de Rafael
 * beto - Resultado da funcao de Beto
 * carlos - Resultado da funcao de Carlos
 * 
 * Retorno:
 * 'R' - Se Rafael eh o vencedor
 * 'B' - Se Beto eh o vencedor
 * 'C' - se Carlos eh o vencedor
*/
char Vencedor(int rafael, int beto, int carlos){

    if (rafael > beto && rafael > carlos){
        return 'R';
    }
    else if (beto > rafael && beto > carlos){
        return 'B';
    }
    else { //Se nem Rafael nem Beto ganharam, entao Carlos eh o vencedor
        return 'C';
    }
}


int main(){
    int nTestes;
    int rafael; //(3x)^2 + y^2
    int beto; //2(x^2) + (5y)^2
    int carlos; // -100x + y^3
    int x, y; //Valores das variaveis de teste
    int i;

    scanf("%d", &nTestes);
    for (i = 0; i < nTestes; i++)
    {
        scanf("%d %d", &x, &y);

        rafael = ResultRafael(x, y);
        beto = ResultBeto(x, y);
        carlos = ResultCarlos(x, y);

        switch (Vencedor(rafael, beto, carlos)){
            case 'R':
                printf("Rafael");
                break;
            case 'B':
                printf("Beto");
                break;
            case 'C':
                printf("Carlos");
                break;
        }

        puts(" ganhou");
    }


    return 0;
}